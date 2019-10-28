#include "Tensor.hpp"
#include "TensorImp.hpp"

unique_ptr<Tensor> Tensor::Create(const string &name, 
			const vector<int> &dims, DataType data_type)
{
	return unique_ptr<Tensor>{static_cast<Tensor*>(
				new TensorImp(name, dims, data_type))};
}

unique_ptr<Tensor> Tensor::Create(const Tensor *tensor)
{
    auto ret = unique_ptr<Tensor>{static_cast<Tensor*>(
				new TensorImp(tensor->get_name(), tensor->get_dims(), 
					tensor->get_data_type()))};
	if(tensor->has_data()){
		ret->copy_from(tensor);
	}
	return std::move(ret);
}

unique_ptr<Tensor> Create(const Tensor *tensor, string name)
{
    auto ret = unique_ptr<Tensor>{static_cast<Tensor*>(
				new TensorImp(name, tensor->get_dims(), 
					tensor->get_data_type()))};
	if(tensor->has_data()){
		ret->copy_from(tensor);
	}
	return std::move(ret);
}
