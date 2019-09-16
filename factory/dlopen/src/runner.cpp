#include "runner.hpp"
#include<map>
#include<dlfcn.h>
#include<cassert>
#include<iostream>

namespace run_factory{

static std::map<std::string,
				std::function<std::unique_ptr<Runner>(const int*data, int size)>>
	   the_factory_methods;

void Runner::register_(const std::string &device,
				std::function<std::unique_ptr<Runner>(const int* data, int size)> m){
	auto it = the_factory_methods.begin();
	auto inserted = false;
	std::tie(it, inserted) = the_factory_methods.emplace(std::make_pair(device, m));
	assert(inserted && "add factory method falid");
}

static bool g_init = false;
std::unique_ptr<Runner> Runner::create(const std::string &device,
				const int* data, int size){
	if(!g_init){
		void *p = nullptr;
		p = dlopen("librun_cpu.so", RTLD_NOW);
		if(p == nullptr) std::cout<<"open librun_cpu.so failed"<<std::endl;
		p = dlopen("librun_sim.so", RTLD_NOW);
		if(p == nullptr) std::cout<<"open librun_sim.so failed"<<std::endl;
		p = dlopen("librun_xpu.so", RTLD_NOW);
		if(p == nullptr) std::cout<<"open librun_xpu.so failed"<<std::endl;
		g_init = true;
	}
	auto it = the_factory_methods.find(device);
	assert(it != the_factory_methods.end()
			&& "cannot find factory method");
	return it->second(data, size);
}

}
