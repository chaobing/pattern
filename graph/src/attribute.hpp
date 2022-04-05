#pragma once

#include "common.hpp"

enum class AttributeKind : uint8_t {
  F,  /*float*/
  Fs, /*float list*/
  I,  /*int*/
  Is, /*int list*/
  S,  /*string*/
  Ss  /*string list*/
};

static inline const char *toString(AttributeKind kind) {
  static constexpr const char *names[] = {"F", "Fs", "I", "Is", "S", "Ss"};
  assert(size_t(kind) < sizeof(names) / sizeof(const char *));
  return names[int(kind)];
};

struct AttributeValue {
  AttributeValue(string na) : name_(na) {}
  using Ptr = std::unique_ptr<AttributeValue>;
  string name_;
  virtual AttributeKind kind() const = 0;
  virtual Ptr clone() const = 0;
  virtual ~AttributeValue() = default;
};

template <typename T, AttributeKind Kind>
struct ScalarAttributeValue final : public AttributeValue {
  using ConstructorType = const T &;
  using ValueType = T;
  ScalarAttributeValue(string name, ConstructorType value)
      : AttributeValue(name), value_(value) {}
  ValueType &value() { return value_; }
  virtual Ptr clone() const override {
    return Ptr(new ScalarAttributeValue(name_, value_));
  }
  virtual AttributeKind kind() const override { return Kind; }

private:
  ValueType value_;
};

template <typename T, AttributeKind Kind>
struct VectorAttributeValue final : public AttributeValue {
  using ConstructorType = const vector<T> &&;
  using ValueType = vector<T>;
  VectorAttributeValue(string name, ConstructorType value)
      : AttributeValue(name), value_(std::move(value)) {}
  ValueType &value() { return value_; }
  virtual std::unique_ptr<AttributeValue> clone() const override {
    auto tmp = value_;
    return Ptr(new VectorAttributeValue(name_, std::move(tmp)));
  }
  virtual AttributeKind kind() const override { return Kind; }

private:
  ValueType value_;
};

using FloatAttr = ScalarAttributeValue<float, AttributeKind::F>;
using FloatsAttr = VectorAttributeValue<float, AttributeKind::Fs>;
using IntAttr = ScalarAttributeValue<int64_t, AttributeKind::I>;
using IntsAttr = VectorAttributeValue<int64_t, AttributeKind::Is>;
using StringAttr = ScalarAttributeValue<string, AttributeKind::S>;
using StringsAttr = VectorAttributeValue<string, AttributeKind::Ss>;

class Attributes {
public:
  Attributes() {}
  void Clear() { values_.clear(); };
  void CopyAttributes(const Attributes &rhs) {
    values_.clear();
    values_.reserve(rhs.values_.size());
    for (auto &it : rhs.values_) {
      values_.push_back(it->clone());
    }
  };
  bool HasAttributes(string name) const {
    return Find(name, false) != values_.end();
  }
  AttributeKind KindOf(string name) const {
    return (*Find(name, true))->kind();
  }
  void RemoveAttribute(string name) { values_.erase(Find(name, true)); }
  bool ContainAttributes() const { return values_.size() > 0; }
  vector<string> AttributesNames() const {
    std::vector<string> names;
    names.reserve(values_.size());
    for (auto &it : values_) {
      names.push_back(it->name_);
    }
    return names;
  }
#define ATTR_GETTOR_SETTOR(Kind, method)                                       \
  void Set##method(string name, Kind##Attr::ConstructorType v) {               \
    return Set<Kind##Attr>(name,                                               \
                           std::forward<Kind##Attr::ConstructorType>(v));      \
  }                                                                            \
  const Kind##Attr::ValueType &Get##method(string name) const {                \
    return Get<Kind##Attr>(name);                                              \
  }                                                                            \
  bool TryGet##method(string name, Kind##Attr::ValueType &value) const {       \
    return TryGet<Kind##Attr>(name, value);                                    \
  }

  ATTR_GETTOR_SETTOR(Float, F)
  ATTR_GETTOR_SETTOR(Floats, Fs)
  ATTR_GETTOR_SETTOR(Int, I)
  ATTR_GETTOR_SETTOR(Ints, Is)
  ATTR_GETTOR_SETTOR(String, S)
  ATTR_GETTOR_SETTOR(Strings, Ss)
#undef ATTR_GETTOR_SETTOR
private:
  using AVPtr = AttributeValue::Ptr;
  vector<AVPtr> values_;

  using iterator = vector<AVPtr>::iterator;
  iterator Find(string name, bool required) {
    auto it = std::find_if(values_.begin(), values_.end(),
                           [&](const AVPtr &v) { return v->name_ == name; });
    assert(!required || it != values_.end());
    return it;
  }

  using const_iterator = vector<AVPtr>::const_iterator;
  const_iterator Find(string name, bool required) const {
    auto it = std::find_if(values_.begin(), values_.end(),
                           [&](const AVPtr &v) { return v->name_ == name; });
    /*
if (required || it == values_.end())
assert(0 && " require undefined attribute");
    */
    return it;
  }

  template <typename T> void Set(string name, typename T::ConstructorType v) {
    auto it = Find(name, false);
    auto nv = AVPtr(new T(name, std::forward<typename T::ConstructorType>(v)));
    if (it == values_.end()) {
      values_.push_back(std::move(nv));
    } else {
      *it = std::move(nv);
    }
  }
  template <typename T> typename T::ValueType &Get(string name) const {
    auto it = Find(name, false);
    T *tptr = static_cast<T *>(it->get());
    return tptr->value();
  }
  template <typename T>
  bool TryGet(string name, typename T::ValueType &value) const {
    auto it = Find(name, false);
    if (it == values_.end())
      return false;
    T *tptr = static_cast<T *>(it->get());
    value = tptr->value();
    return true;
  }
};
