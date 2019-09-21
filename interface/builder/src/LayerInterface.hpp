#pragma once
#include "Layer.hpp"
#include<cassert>
#include<cstdint>
#include<functional>
#include<string>
#include<iostream>
#include<vector>
#include<memory>

namespace layer_proxy{

using namespace std;

class LayerInterface{
	public:
		virtual std::string DebugString() const = 0;
		virtual uint32_t get_field(size_t i) const = 0;
		virtual string get_field_s(size_t i) const = 0;
		virtual const char * get_layer_type() const = 0;
		virtual ~LayerInterface() {};
};

template <typename Layer>
struct LayerProxy: public LayerInterface{
	LayerProxy(Layer layer): layer_(layer){}
	~LayerProxy(){}

		virtual std::string DebugString() const override{
			return layer_.DebugString();
		}
		virtual uint32_t get_field(size_t i) const override{	
			return layer_.GetNumberFields()[i];
		}
		virtual string get_field_s(size_t i) const override{	
			return layer_.GetStringFields()[i];
		}
		virtual const char * get_layer_type() const override{	
			return layer_.get_layer_type();
		}

		std::unique_ptr<Layer> get_param(){
			return make_unique<Layer>(layer_);
		}
	private:
		Layer layer_;
};

}
