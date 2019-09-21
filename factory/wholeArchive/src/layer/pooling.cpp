#include "pooling.hpp"
namespace whole_fac{
LayerPooling::LayerPooling(const std::string n)
	:Layer(n)
	{
}
LayerPooling::~LayerPooling(){
}

void LayerPooling::exec(){
	std::cout<<"LayerPooling is running..."<<std::endl;
}

bool isLayerPooling(const std::string & param){
	return !param.compare("isLayerPooling");
}

REGISTER_LAYER(Pooling, isLayerPooling);

}
