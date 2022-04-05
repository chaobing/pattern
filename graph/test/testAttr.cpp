#include "attribute.hpp"

void testAttr() {
  cout << __FUNCTION__ << endl;
  Attributes attr;
  attr.SetI("int_val", 10);
  vector<int64_t> ilist({2, 3, 4, 5});
  attr.SetIs("int_list", std::move(ilist));
  vector<float> flist({1.1, 2.2, 3.3, 4.4});
  attr.SetFs("float_list", std::move(flist));
  auto attr_names = attr.AttributesNames();
  for (auto ns : attr_names) {
    cout << ns << "-";
  }
  cout << endl;
  string key = "int_val";
  auto iv = attr.GetI(key);
  cout << key << ": " << iv << endl;
  key = "fint_val";
  if (attr.HasAttributes(key)) {
    auto it = attr.GetI(key);
    cout << key << ": " << it << endl;
  }
  int64_t ti = 0;
  attr.TryGetI("int_val", ti);
  cout << " ti " << ti << endl;

  auto fl = attr.GetFs("float_list");
  for (auto f : fl) {
    cout << f << ", ";
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  testAttr();
  return 0;
}
