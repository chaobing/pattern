#pragma once
#include "Layer.hpp"
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
namespace whole_fac{

using namespace std;

#define REGISTER_LAYER(CLASS, CHECK_FUNC)    \
	static LayerFactory::register_h<Layer##CLASS> __##CLASS( \
		#CLASS, CHECK_FUNC)

class LayerFactory{
	public:
		using CriterionCheck = function<bool(const std::string &)>;
		using ConstructionWithCriterion = 
			function<unique_ptr<Layer>(const string &)>;
		
		template<typename T> 
		struct register_h{
			register_h(const std::string s, const CriterionCheck &chk){
				LayerFactory::instance()->creators.emplace_back(
					make_tuple(s, chk,
						[](const string &param)->unique_ptr<Layer>{
								unique_ptr<Layer> ret = 
									static_cast<unique_ptr<Layer>>(
										std::make_unique<T>(param));
							return ret;	
						}));
				std::cout<<"emplace_back "<<s<<std::endl;
			}
		};

		static unique_ptr<Layer> create(const std::string &id, const std::string & param){
			return LayerFactory::instance()->creator_h(id, param);
		}
		
	private:
		LayerFactory() = default;
		LayerFactory(const LayerFactory &) = delete;
		LayerFactory(LayerFactory &&) = delete;
		LayerFactory &operator=(const LayerFactory &) = delete;

		static LayerFactory *instance(){
			static LayerFactory f;
			return &f;
		}

		unique_ptr<Layer> creator_h(const std::string id, const std::string &param){
			std::cout<<"sreaching creators for "<<id;
			for(auto iter : creators){
				
				if( get<0>(iter) == id && get<1>(iter)(param)){
					std::cout<<", create success!!!"<<std::endl;
					return get<2>(iter)(param);
				}
			}
			std::cout<<", create failed!!! "<<std::endl;
			return nullptr;
		}
	
	private:
		vector<tuple<string, CriterionCheck, ConstructionWithCriterion>> creators;
};

}
