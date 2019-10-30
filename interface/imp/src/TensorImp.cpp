#include "TensorImp.hpp"

TensorImp::TensorImp(const string &name, 
			const vector<int> &dims, DataType data_type)
	:name_(name), dims_(dims), data_type_(data_type){}

const string TensorImp::get_name() const { return name_; }

const vector<int> TensorImp::get_dims() const { return dims_; }

const size_t TensorImp::get_element_num() const {
  size_t size = 1;
  for(auto d : dims_){
	size *= d;
  }
  return size;
}

bool TensorImp::is_same_size(const Tensor* tensor) const{
	return this->get_data_size() ==  tensor->get_data_size();
}

const DataType TensorImp::get_data_type() const{ return data_type_; }

void TensorImp::set_data_type(const DataType & dtype){ data_type_ = dtype; }

static size_t size_of(DataType dtype){
	size_t ret = 0;
	switch(dtype){
		case DataType::INT8: ret = 1; break;
		case DataType::FLOAT: ret = 4; break;
	 default: ret=0;
	}
	return ret;
}
const int TensorImp::get_data_size() const {
	return get_element_num()*size_of(data_type_);	
}
	
void TensorImp::malloc()
{
	assert(!has_data_);
	has_data_ = true;
	data_ = new char[get_data_size()];
}
void TensorImp::free()
{
	if(data_ != nullptr){
		char* tmp = static_cast<char*>(data_);
		delete tmp;
		has_data_ = false;
		tmp = nullptr;
		data_ = nullptr;
	}else{
		assert("error try to free nullptr!!!");
	}
}
bool TensorImp::has_data() const{ return has_data_;}
void* TensorImp::data() const{ return data_; }
	
void TensorImp::copy_from(const Tensor* tensor){
  assert(this->data_type_ == tensor->get_data_type());
  if(is_same_size(tensor)){
	if(data_ == nullptr){
		malloc();
		has_data_ = true;
	}
	std::memcpy(data_, tensor->data(), get_data_size());
  }else{
	assert("error try to different data_type tensor!!!");	
  }
}

void TensorImp::reshape(const vector<int> &dim){
  assert(dim.size()>0);
  size_t size = 0;
  for(auto d : dim){
	size *= d;
  }
  assert(size == get_element_num());
  dims_ = dim;
}

