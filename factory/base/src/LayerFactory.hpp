#pragma once
#include "Layer.hpp"
#include "convolution.hpp"
#include "pooling.hpp"
#include "eltwise.hpp"
#include <memory>

namespace layer_base{
class LayerFactory{
public:
	LayerFactory() = delete;
	~LayerFactory() = delete;
public:
	static std::shared_ptr<Layer> CreatorLayer(layer_base::LAYER_TYPE lt);
};
}
