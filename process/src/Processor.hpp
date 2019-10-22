#pragma once

#include "common.hpp"

class ITProcessor;

class Processor{
  public:
	  Processor();
	  bool Process(vector<int> & data);
  private:
	  vector<shared_ptr<ITProcessor>> plist_;
};
void printVector(const string prefix, const vector<int>& d);
