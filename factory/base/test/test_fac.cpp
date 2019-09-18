#include "Layer.hpp"
#include "LayerFactory.hpp"

int main(int argc, char*argv[]){
	auto layer = layer_base::LayerFactory::CreatorLayer(layer_base::LAYER_TYPE_CONV);
	layer->exec();
	layer = layer_base::LayerFactory::CreatorLayer(layer_base::LAYER_TYPE_POOL);
	layer->exec();
	layer = layer_base::LayerFactory::CreatorLayer(layer_base::LAYER_TYPE_ELEW);
	layer->exec();
	return 0;
}
