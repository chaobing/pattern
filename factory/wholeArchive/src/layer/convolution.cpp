#include "convolution.hpp"
namespace whole_fac{
LayerConvolution::LayerConvolution(const std::string n)
	:Layer(n)
	{
}
LayerConvolution::~LayerConvolution(){
}

void LayerConvolution::exec(){
	std::cout<<"LayerConvolution is running..."<<std::endl;
}

bool isLayerConvolution(const std::string & param){
	return !param.compare("isLayerConvolution");
}

REGISTER_LAYER(Convolution, isLayerConvolution);

}
