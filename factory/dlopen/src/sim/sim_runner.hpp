#pragma once
#include "runner.hpp"

namespace run_factory{
namespace sim{

class SimRunner : public Runner{
	public:
		explicit SimRunner(const int* data, int size);
		~SimRunner() = default;
		SimRunner(const SimRunner &r) = delete;
		SimRunner operator=(const SimRunner &rhs) = delete;

	private:
		virtual void run() override;

};

}
}
