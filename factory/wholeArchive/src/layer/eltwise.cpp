#include "eltwise.hpp"
namespace whole_fac{
LayerEltwise::LayerEltwise(const std::string n)
	:Layer(n)
{
}
LayerEltwise::~LayerEltwise(){
}

void LayerEltwise::exec(){
	std::cout<<"LayerEltwise is running..."<<std::endl;
}

bool isLayerEltwise(const std::string & param){
	return !param.compare("isLayerEltwise");
}

REGISTER_LAYER(Eltwise, isLayerEltwise);

}
