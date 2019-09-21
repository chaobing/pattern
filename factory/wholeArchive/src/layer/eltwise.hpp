#pragma once
#include "Layer.hpp"
#include "LayerFactory.hpp"
namespace whole_fac{
class LayerEltwise: public Layer{
	public:
		LayerEltwise(const std::string n);
		~LayerEltwise();
	public:
		virtual void exec() override;
};
}
