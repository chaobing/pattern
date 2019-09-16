#include "cpu_runner.hpp"
#include "runner.hpp"
#include <iostream>

namespace run_factory{
namespace cpu{
CPURunner::CPURunner(const int *data, int size)
	: run_factory::Runner{}
{ 
}

void CPURunner::run(){
	std::cout<<"CPU Running"<<std::endl;
}

static struct CPURunnerRegister{
	CPURunnerRegister(){
		CPURunner::register_("cpu",
				[](const int *data, int size){
					return std::make_unique<CPURunner>(data, size);
				});
	}
}g_register_;


}
}
