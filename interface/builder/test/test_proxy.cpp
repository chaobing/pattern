#include "Layer.hpp"
#include "LayerFactory.hpp"
#include "LayerInterface.hpp"

int main(int argc, char*argv[]){
	auto builder = layer_proxy::LCONV::Builder();
	builder.set_str_name("CONV");
	std::cout<<builder.DebugString()<<std::endl;
	builder.set_str_in("data");
	builder.set_kernel_w(7);
	builder.set_kernel_h(3);
	auto conv = builder.build();
	std::cout<<conv.DebugString()<<std::endl;
	std::cout<<" input is: "<<conv.get_str_in()<<std::endl;
	
	auto elew = layer_proxy::LayerFactory::CreateLayerFromString(
			"LELEW str_name testEltwise kernel_w 6");
	if(elew){
		std::cout<<elew->DebugString()<<std::endl;
		std::cout<<" str_name is: "<<elew->get_field_s(layer_proxy::LELEW::Builder::str_name)<<std::endl;
	}
	
	auto pool = layer_proxy::LayerFactory::CreateLayerFromString(
			"LPOOL str_name testPool kernel_w 10 kernel_h 4 input");
	if(pool){
		std::cout<<pool->DebugString()<<std::endl;
		std::cout<<" kernel_w is: "<<pool->get_field(layer_proxy::LPOOL::Builder::kernel_w)<<std::endl;
	}
	
	return 0;
}
