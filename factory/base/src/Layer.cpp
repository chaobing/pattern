#include "Layer.hpp"
#include "layer_declaration.hpp"

namespace layer_base{

Layer::Layer(){}

Layer::~Layer(){}

static const layer_registry_entry layer_registry[] =
{
	{Convolution_final_layer_creator},
	{Pooling_final_layer_creator},
	{Eltwise_final_layer_creator},
};

static const int layer_registry_entry_count = sizeof(layer_registry) / sizeof(layer_registry_entry);

Layer* create_layer(int index)
{
    if (index < 0 || index >= layer_registry_entry_count){
		std::cout<<"Not support this type "<<index << std::endl;
		abort();
	}

    layer_creator_func layer_creator = layer_registry[index].creator;
    if (!layer_creator){
		std::cout<<"Create Error "<<index << std::endl;
		abort();
	}

    Layer* layer = layer_creator();
    return layer;
}


}
