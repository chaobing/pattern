#pragma once
#include <memory>
#include <string>
#include <functional>

namespace run_factory{

class Runner{
	protected:
		Runner(){}
	public:
		virtual ~Runner() = default;
		Runner(const Runner &r) = delete;
		Runner &operator=(const Runner &rhs) = delete;

	public:
		static void register_(const std::string &device,
				std::function<std::unique_ptr<Runner>(const int* data, int size)> m);
		static std::unique_ptr<Runner> create(const std::string &device,
				const int* data, int size);

	public:
		virtual void run() = 0;
};

}
