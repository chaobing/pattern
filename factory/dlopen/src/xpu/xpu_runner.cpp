#include "xpu_runner.hpp"
#include "runner.hpp"
#include <iostream>

namespace run_factory{
namespace xpu{
XPURunner::XPURunner(const int *data, int size)
	: run_factory::Runner{}
{ 
}

void XPURunner::run(){
	std::cout<<"XPU Running"<<std::endl;
}

static struct XPURunnerRegister{
	XPURunnerRegister(){
		XPURunner::register_("xpu",
				[](const int *data, int size){
					return std::make_unique<XPURunner>(data, size);
				});
	}
}g_register_;


}
}
