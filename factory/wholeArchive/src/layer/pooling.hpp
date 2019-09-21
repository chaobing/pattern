#pragma once
#include "Layer.hpp"
#include "LayerFactory.hpp"
namespace whole_fac{
class LayerPooling: public Layer{
	public:
		LayerPooling(const std::string n);
		~LayerPooling();
	public:
		virtual void exec() override;
};
}
