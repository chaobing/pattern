#pragma once
#include "LayerInterface.hpp"
namespace layer_proxy{

struct LayerFactory{
	public:
		static std::shared_ptr<LayerInterface>
			CreateLayerFromString(const std::string &str_layer){
				std::shared_ptr<LayerInterface> p = nullptr;
				if(!p){
					p = TryCreateLayerFromString<LCONV>(str_layer);
				}
				if(!p){
					p = TryCreateLayerFromString<LPOOL>(str_layer);
				}
				if(!p){
					p = TryCreateLayerFromString<LELEW>(str_layer);
				}
				return p;
			}

	private:
		template <typename Layer>
		static std::shared_ptr<LayerInterface> 
			TryCreateLayerFromString(const std::string &str_layer){
				typedef typename Layer::Builder Builder;
				auto builder = Builder();
				if(builder.Parse(str_layer)){
					return std::shared_ptr<LayerInterface>{
						new LayerProxy<Layer>(builder.build())};
				}
				return nullptr;
			}
	
};

}
