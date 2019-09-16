#pragma once
#include "runner.hpp"

namespace run_factory{
namespace xpu{

class XPURunner : public Runner{
	public:
		explicit XPURunner(const int* data, int size);
		~XPURunner() = default;
		XPURunner(const XPURunner &r) = delete;
		XPURunner operator=(const XPURunner &rhs) = delete;

	private:
		virtual void run() override;

};

}
}
