#include "Layer.hpp"

int main(int argc, char*argv[]){
	layer_base::Layer* layer = layer_base::create_layer(static_cast<int>(layer_base::LAYER_TYPE_CONV));
	layer->exec();
	layer =  layer_base::create_layer(static_cast<int>(layer_base::LAYER_TYPE_POOL));
	layer->exec();
	layer =  layer_base::create_layer(static_cast<int>(layer_base::LAYER_TYPE_ELEW));
	layer->exec();
	return 0;
}
