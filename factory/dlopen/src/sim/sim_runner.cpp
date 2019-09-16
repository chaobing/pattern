#include "sim_runner.hpp"
#include "runner.hpp"
#include <iostream>

namespace run_factory{
namespace sim{
SimRunner::SimRunner(const int *data, int size)
	: run_factory::Runner{}
{ 
}

void SimRunner::run(){
	std::cout<<"Sim Running"<<std::endl;
}

static struct SimRunnerRegister{
	SimRunnerRegister(){
		SimRunner::register_("sim",
				[](const int *data, int size){
					return std::make_unique<SimRunner>(data, size);
				});
	}
}g_register_;


}
}
