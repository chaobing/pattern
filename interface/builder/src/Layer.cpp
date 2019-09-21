#include "Layer.hpp"
#include "LayerFactory.hpp"
#include <memory>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>

namespace layer_proxy{

using namespace std;

bool ParseLayerField(std::string &line, const char *name, std::function<void(std::string)> f){
	string str_rex = string("^") + name + " +([0-9a-zA-Z_/]+) *";
	std::regex rex{str_rex};
	std::smatch pieces_match;
	bool ret = false;
	ret = std::regex_search(line, pieces_match, rex);
	if(ret){
		std::string tmp = pieces_match[1].str();
		std::replace_if(tmp.begin(), tmp.end(), [](char c){return c == '/';},
				'_');
		f(tmp);
		line = line.substr(pieces_match.length(0));
	}
	return ret;
}

bool ParseLayerField(std::string &line, const char *name, std::function<void(int)> f){
	string str_rex = string("^") + name + " +([0-9a-zA-Z_/]+) *";
	std::regex rex{str_rex};
	std::smatch pieces_match;
	bool ret = false;
	ret = std::regex_search(line, pieces_match, rex);
	if(ret){
		f((int)stoi(pieces_match[1].str()));
		line = line.substr(pieces_match.length(0));
	}
	return ret;
}

std::string LCONV::Builder::get_str_name() const{
	std::string ret = string_fields_[0];
	return ret;
}
std::string LCONV::Builder::get_str_in() const{
	std::string ret = string_fields_[1];
	return ret;
}
int LCONV::Builder::get_kernel_w() const{
	int ret = number_fields_[0];
	return ret;
}
int LCONV::Builder::get_kernel_h() const{
	int ret = number_fields_[1];
	return ret;
}

LCONV::Builder& LCONV::Builder::set_str_name(std::string v){
		string_fields_[0] = v;
		return *this;
}
LCONV::Builder& LCONV::Builder::set_kernel_w(int v){
	number_fields_[0] = v;
	return *this;
}
LCONV::Builder& LCONV::Builder::set_kernel_h(int v){
	number_fields_[1] = v;
	return *this;
}
LCONV::Builder& LCONV::Builder::set_str_in(std::string v){
		string_fields_[1] = v;
		return *this;
}
std::regex& LCONV::Builder::get_regex_pattern(){
	static std::regex ret{"^LCONV"
						  " +(.*)$"};
	return ret;
}
bool LCONV::Builder::Parse(const std::string& line){
	std::smatch pieces_match;
	std::regex e("\\r");
	std::string line2;
	line2 = std::regex_replace(line, e, "");
	if(std::regex_match(line, pieces_match, get_regex_pattern())){
		std::string str_fields = pieces_match[1].str();
		while(!str_fields.empty()){
			if(0){
			} 
			else if(ParseLayerField(str_fields, "str_name", [this, line2](std::string value){
				set_str_name(value);
			})) {
			}
			else if(ParseLayerField(str_fields, "str_in", [this, line2](std::string value){
				set_str_in(value);
			})) {
			} 
			else if(ParseLayerField(str_fields, "kernel_w", [this, line2](int value){
				set_kernel_w(value);
			})) {
			}
			else if(ParseLayerField(str_fields, "kernel_h", [this, line2](int value){
				set_kernel_h(value);
			})) {
			}
			else{
				std::cerr <<"cannot parse field for LCONV"
						  <<" str_fields = " << str_fields
						  <<std::endl;
				abort();
			}
		}
		return true;
	}
	return false;
}

std::string LCONV::Builder::DebugString() const{
	std::ostringstream ss;
   ss <<"str_name" << ": " <<get_str_name() << " ";
   ss <<"str_in" << ": " <<get_str_in() << " ";
   ss <<"kernel_w" << ": " <<get_kernel_w() << " ";
   ss <<"kernel_h" << ": " <<get_kernel_h() << " ";
	ss<<std::dec<<"\n";
	return ss.str();
}

LCONV LCONV::Builder::build(){
	LCONV ret {number_fields_, string_fields_};
	return ret;
}

std::string LCONV::get_str_name() const{
	std::string ret = string_fields_[0];
	return ret;
}

int LCONV::get_kernel_w() const{
	int ret = number_fields_[0];
	return ret;
}

int LCONV::get_kernel_h() const{
	int ret = number_fields_[1];
	return ret;
}

std::string LCONV::get_str_in() const{
	std::string ret = string_fields_[1];
	return ret;
}

std::string LCONV::DebugString() const{
	std::ostringstream ss;
   ss <<"str_name" << ": " <<get_str_name() << " ";
   ss <<"str_in" << ": " <<get_str_in() << " ";
   ss <<"kernel_w" << ": " <<get_kernel_w() << " ";
   ss <<"kernel_h" << ": " <<get_kernel_h() << " ";
	ss<<std::dec<<"\n";
	return ss.str();
}


std::string LPOOL::Builder::get_str_name() const{
	std::string ret = string_fields_[0];
	return ret;
}
int LPOOL::Builder::get_kernel_w() const{
	int ret = number_fields_[0];
	return ret;
}
int LPOOL::Builder::get_kernel_h() const{
	int ret = number_fields_[1];
	return ret;
}

LPOOL::Builder& LPOOL::Builder::set_str_name(std::string v){
		string_fields_[0] = v;
		return *this;
}
LPOOL::Builder& LPOOL::Builder::set_kernel_w(int v){
	number_fields_[0] = v;
	return *this;
}
LPOOL::Builder& LPOOL::Builder::set_kernel_h(int v){
	number_fields_[1] = v;
	return *this;
}
std::regex& LPOOL::Builder::get_regex_pattern(){
	static std::regex ret{"^LPOOL"
						  " +(.*)$"};
	return ret;
}
bool LPOOL::Builder::Parse(const std::string& line){
	std::smatch pieces_match;
	std::regex e("\\r");
	std::string line2;
	line2 = std::regex_replace(line, e, "");
	if(std::regex_match(line, pieces_match, get_regex_pattern())){
		std::string str_fields = pieces_match[1].str();
		while(!str_fields.empty()){
			if(0){
			} 
			else if(ParseLayerField(str_fields, "str_name", [this, line2](std::string value){
				set_str_name(value);
			})) {
			}
  
			else if(ParseLayerField(str_fields, "kernel_w", [this, line2](int value){
				set_kernel_w(value);
			})) {
			}

			else if(ParseLayerField(str_fields, "kernel_h", [this, line2](int value){
				set_kernel_h(value);
			})) {
			}
			else{
				std::cerr <<"cannot parse field for LPOOL"
						  <<" str_fields = " << str_fields
						  <<std::endl;
				abort();
			}
		}
		return true;
	}
	return false;
}

std::string LPOOL::Builder::DebugString() const{
	std::ostringstream ss;
   ss <<"str_name" << ": " <<get_str_name() << " ";
   ss <<"kernel_w" << ": " <<get_kernel_w() << " ";
   ss <<"kernel_h" << ": " <<get_kernel_h() << " ";
	ss<<std::dec<<"\n";
	return ss.str();
}

LPOOL LPOOL::Builder::build(){
	LPOOL ret {number_fields_, string_fields_};
	return ret;
}

std::string LPOOL::get_str_name() const{
	std::string ret = string_fields_[0];
	return ret;
}

int LPOOL::get_kernel_w() const{
	int ret = number_fields_[0];
	return ret;
}

int LPOOL::get_kernel_h() const{
	int ret = number_fields_[1];
	return ret;
}

std::string LPOOL::DebugString() const{
	std::ostringstream ss;
   ss <<"str_name" << ": " <<get_str_name() << " ";
   ss <<"kernel_w" << ": " <<get_kernel_w() << " ";
   ss <<"kernel_h" << ": " <<get_kernel_h() << " ";
	ss<<std::dec<<"\n";
	return ss.str();
}

std::string LELEW::Builder::get_str_name() const{
	std::string ret = string_fields_[0];
	return ret;
}
int LELEW::Builder::get_kernel_w() const{
	int ret = number_fields_[0];
	return ret;
}

LELEW::Builder& LELEW::Builder::set_str_name(std::string v){
		string_fields_[0] = v;
		return *this;
}
LELEW::Builder& LELEW::Builder::set_kernel_w(int v){
	number_fields_[0] = v;
	return *this;
}
std::regex& LELEW::Builder::get_regex_pattern(){
	static std::regex ret{"^LELEW"
						  " +(.*)$"};
	return ret;
}
bool LELEW::Builder::Parse(const std::string& line){
	std::smatch pieces_match;
	std::regex e("\\r");
	std::string line2;
	line2 = std::regex_replace(line, e, "");
	if(std::regex_match(line, pieces_match, get_regex_pattern())){
		std::string str_fields = pieces_match[1].str();
		while(!str_fields.empty()){
			if(0){
			} 
			else if(ParseLayerField(str_fields, "str_name", [this, line2](std::string value){
				set_str_name(value);
			})) {
			}
  
			else if(ParseLayerField(str_fields, "kernel_w", [this, line2](int value){
				set_kernel_w(value);
			})) {
			}

			else{
				std::cerr <<"cannot parse field for LELEW"
						  <<" str_fields = " << str_fields
						  <<std::endl;
				abort();
			}
		}
		return true;
	}
	return false;
}

std::string LELEW::Builder::DebugString() const{
	std::ostringstream ss;
   ss <<"str_name" << ": " <<get_str_name() << " ";
   ss <<"kernel_w" << ": " <<get_kernel_w() << " ";
	ss<<std::dec<<"\n";
	return ss.str();
}

LELEW LELEW::Builder::build(){
	LELEW ret {number_fields_, string_fields_};
	return ret;
}

std::string LELEW::get_str_name() const{
	std::string ret = string_fields_[0];
	return ret;
}

int LELEW::get_kernel_w() const{
	int ret = number_fields_[0];
	return ret;
}

std::string LELEW::DebugString() const{
	std::ostringstream ss;
   ss <<"str_name" << ": " <<get_str_name() << " ";
   ss <<"kernel_w" << ": " <<get_kernel_w() << " ";
	ss<<std::dec<<"\n";
	return ss.str();
}

}









