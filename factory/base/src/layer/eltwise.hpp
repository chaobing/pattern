#pragma once
#include "Layer.hpp"
namespace layer_base{
class Eltwise: public Layer{
	public:
		Eltwise();
		~Eltwise();
	public:
		virtual void exec() override;
};
}
