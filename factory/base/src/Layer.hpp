#pragma once
#include <iostream>
#include <string>

namespace layer_base{
enum LAYER_TYPE{
	LAYER_TYPE_MIN = 0,
	LAYER_TYPE_CONV = LAYER_TYPE_MIN,
	LAYER_TYPE_POOL,
	LAYER_TYPE_ELEW,
	LAYER_TYPE_MAX,
};

class Layer{
	public:
		Layer();
		virtual ~Layer();

	public:
		virtual void exec() = 0;
};

typedef Layer* (*layer_creator_func)();

struct layer_registry_entry
{
    // layer factory entry
    layer_creator_func creator;
};

// create layer from layer type
Layer* create_layer(int index);

#define DEFINE_LAYER_CREATOR(name) \
    ::layer_base::Layer* name##_layer_creator() { return new name; }

}
