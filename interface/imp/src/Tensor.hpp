#pragma once

#include "common.hpp"

enum class DataType{
	INT8,
	FLOAT,
	UNKNOWN
};

//interface
class Tensor{
  public:
	static unique_ptr<Tensor> Create(const string &name, 
			const vector<int> &dims, DataType data_type);
	static unique_ptr<Tensor> Create(const Tensor *tensor);
	static unique_ptr<Tensor> Create(const Tensor *tensor, string name);
  
  public:
	virtual const string get_name() const = 0;
	virtual const vector<int> get_dims() const = 0;
	virtual const DataType get_data_type() const = 0;
	virtual bool has_data() const = 0;
	
	virtual const size_t get_element_num() const = 0;
	virtual bool is_same_size(const Tensor*) const = 0;
	virtual void set_data_type(const DataType &) = 0;
	virtual const int get_data_size() const = 0;
	
	virtual void malloc() = 0;
	virtual void free() = 0;
	virtual void* data() const = 0;

	template<typename T>
	T* data(){ return reinterpret_cast<T*>(this->data()); }
	
	virtual void copy_from(const Tensor*) = 0;
	virtual void reshape(const vector<int>&) = 0;

  public:
	virtual ~Tensor() = default;
};

