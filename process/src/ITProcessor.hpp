#pragma once
#include "common.hpp"

class ITProcessor{
	public:
		virtual bool Process(vector<int> & data) = 0;
		virtual string name() = 0;
		virtual ~ITProcessor(){};
};

class ITProcessorA : public ITProcessor{
	public:
		bool Process(vector<int> & data) override;
		string name() override { return "ITProcessorA"; };
};

class ITProcessorB : public ITProcessor{
	public:
		bool Process(vector<int> & data) override;
		string name() override { return "ITProcessorB"; };
};

class ITProcessorC : public ITProcessor{
	public:
		bool Process(vector<int> & data) override;
		string name() override { return "ITProcessorC"; };
};
