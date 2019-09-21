#pragma once
#include "Layer.hpp"
#include "LayerFactory.hpp"
namespace whole_fac{
class LayerConvolution: public Layer{
	public:
		LayerConvolution(const std::string n);
		~LayerConvolution();
	public:
		virtual void exec() override;
};
}
