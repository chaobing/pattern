#pragma once
#include <iostream>
#include <string>

namespace whole_fac{

class Layer{
	public:
		Layer(const std::string n);
		virtual ~Layer();

	public:
		virtual void exec() = 0;
	private:
		std::string name;
};

}
