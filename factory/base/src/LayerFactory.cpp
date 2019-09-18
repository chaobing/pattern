#include "LayerFactory.hpp"
#include <cassert>
namespace layer_base{
std::shared_ptr<Layer> LayerFactory::CreatorLayer(layer_base::LAYER_TYPE lp){
	std::shared_ptr<Layer> player;
	assert(lp < layer_base::LAYER_TYPE_MAX && "Not support this layer type");
	if(lp == layer_base::LAYER_TYPE_CONV){
		player = std::make_shared<Convolution>();
	}else if(lp == layer_base::LAYER_TYPE_POOL){
		player = std::make_shared<Pooling>();
	}else if(lp == layer_base::LAYER_TYPE_ELEW){
		player = std::make_shared<Eltwise>();
	}else{
		std::cout<<"no such layer type "<<std::endl;
		abort();
	}
	return player;
}

}
