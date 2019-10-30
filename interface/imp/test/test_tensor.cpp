#include "Tensor.hpp"
#include "TensorImp.hpp"

int main(int argc, char*argv[]){
	auto t = Tensor::Create("tensorA", {1, 1, 1, 8}, DataType::INT8);
	cout<<t->get_name()
		<<", "<<t->get_element_num()<<
		", "<<t->get_data_size()<<endl;
	
	t->malloc();
	int8_t* data_ptr = reinterpret_cast<int8_t*>(t->data());
	for(int i=0; i<8; i++){
		*(data_ptr + i) = i-4;
	}
	int8_t* tmp = t->data<int8_t>();
	for(auto i=0U; i<t->get_element_num(); i++){
		cout<<+tmp[i]<<" ";
	}

	return 0;
}
