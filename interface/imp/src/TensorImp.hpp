#pragma once

#include "Tensor.hpp"

class TensorImp : public Tensor{
	 const string get_name() const override;
	 const vector<int> get_dims() const override;
	 const DataType get_data_type() const override;
	 bool has_data() const override;
	 
	 const size_t get_element_num() const override;
	 bool is_same_size(const Tensor*) const override;
	 void set_data_type(const DataType &) override;
	 const int get_data_size() const override;
	
	 void malloc() override;
	 void free() override;
	 void* data() const override;
	
	 void copy_from(const Tensor*) override;
	 void reshape(const vector<int> &) override;

  private:
	string name_;
	vector<int> dims_;
	DataType data_type_;
	bool has_data_{false};
	void *data_{nullptr};
  public:
	TensorImp(const string &name, 
			const vector<int> &dims, DataType data_type);
	TensorImp(TensorImp &&) = default;
	TensorImp() = delete;

	~TensorImp(){
		if(has_data_) this->free();
	}
};
