#pragma once
#include "runner.hpp"

namespace run_factory{
namespace cpu{

class CPURunner : public Runner{
	public:
		explicit CPURunner(const int* data, int size);
		~CPURunner() = default;
		CPURunner(const CPURunner &r) = delete;
		CPURunner operator=(const CPURunner &rhs) = delete;

	private:
		virtual void run() override;

};

}
}
