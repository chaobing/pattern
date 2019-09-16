#include <vector>
#include <iostream>
#include "runner.hpp"
using std::vector;

int main(int argc, char* argv[]){
	vector<int> vec = {1, 2, 3, 5, 7};
	auto runner = run_factory::Runner::create("sim", vec.data(), vec.size());
	runner->run();
	return 0;
}
