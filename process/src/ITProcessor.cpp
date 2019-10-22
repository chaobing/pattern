#include "ITProcessor.hpp"

bool ITProcessorA::Process(vector<int> & data)
{
	std::for_each(data.begin(), data.end(),
			[](int &n) -> int{  return ++n; });
	return true;
}

bool ITProcessorB::Process(vector<int> & data)
{
	std::for_each(data.begin(), data.end(),
			[](int &n){ --n; });
	return true;
}

bool ITProcessorC::Process(vector<int> & data)
{
	std::transform(data.begin(), data.end(), data.begin(),
			[](int n)->int{ return n*2; });
	return true;
}
