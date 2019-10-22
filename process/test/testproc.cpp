
#include "common.hpp"
#include "Processor.hpp"


int main(int argc, char*argv[]){
	int len = 10;
	vector<int> dat(len);
	int value = 0;
	for(auto &e : dat){ e = value++; }

	printVector("before process", dat);
	auto proc = make_shared<Processor>();
	bool ok = proc->Process(dat);
	if(ok) std::cout<< "Process finish!!!\n";
	else std::cout<<"Process not finish!!!\n";
	
	printVector("after process", dat);
	
	return 0;
}
