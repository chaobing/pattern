#pragma once
#include "Layer.hpp"
namespace layer_base{
class Pooling: public Layer{
	public:
		Pooling();
		~Pooling();
	public:
		virtual void exec() override;
};
}
