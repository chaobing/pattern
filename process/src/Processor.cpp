#include "Processor.hpp"
#include "ITProcessor.hpp"

#define PROC_DEF(p) make_shared<p>()

Processor::Processor()
{
	plist_.emplace_back(PROC_DEF(ITProcessorA));
	plist_.emplace_back(PROC_DEF(ITProcessorB));
	plist_.emplace_back(PROC_DEF(ITProcessorC));
}
void printVector(const string prefix, const vector<int>& d)
{
	cout<<prefix<<"\n";
	for(auto i=0U; i<d.size(); i++){
		cout<<d[i]<<" ";
	}
	cout<<"\n";
}

bool Processor::Process(vector<int> &data)
{
	bool status = false;
	for(auto &proc : plist_){
		status |= proc->Process(data);
		printVector(proc->name(), data);
	}
	return status;
}
