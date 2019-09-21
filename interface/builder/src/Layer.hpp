#pragma once
#include<array>
#include<cassert>
#include<cstdint>
#include<functional>
#include<regex>
#include<string>
#include<unordered_map>

namespace layer_proxy{

struct  LCONV;
struct  LPOOL;
struct  LELEW;

template <typename T> struct is_layer{
	static constexpr bool value = false;
};

struct LCONV{
	public:
	struct Builder{
		public:
			Builder() : number_fields_{{0}} {}
			Builder(const std::array<int, 2>& number_fields, 
				const std::array<std::string, 2>& string_fields) 
				: number_fields_{{number_fields[0],number_fields[1]}},
				  string_fields_{{string_fields[0],string_fields[1]}}{}
			
			static constexpr int  str_name = 0;
			std::string get_str_name() const;
			
			static constexpr int  str_in = 1;
			std::string get_str_in() const;

			static constexpr int kernel_w = 0;
			int get_kernel_w() const;

			static constexpr int kernel_h = 1;
			int get_kernel_h() const;
			
			Builder& set_str_name(std::string v);
			Builder& set_str_in(std::string v);
			Builder& set_kernel_w(int v);
			Builder& set_kernel_h(int v);
			
			static std::regex& get_regex_pattern() ;
			bool Parse(const std::string &line);
			
			std::string DebugString() const;

			LCONV build();	
			
		private:
			std::array<int, 2> number_fields_;
			std::array<std::string, 2> string_fields_;
	};

   LCONV(const std::array<int, 2>& number_fields, 
		   const std::array<std::string, 2>& string_fields) 
			: number_fields_(number_fields), 
			  string_fields_(string_fields){ }

			static constexpr int  str_name = 0;
			std::string get_str_name() const;
			
			static constexpr int  str_in = 1;
			std::string get_str_in() const;

			static constexpr int kernel_w = 0;
			int get_kernel_w() const;

			static constexpr int kernel_h = 1;
			int get_kernel_h() const;
		
		const char *get_layer_type() const { return "LCONV"; }

	public:
		const std::array<int, 2>& GetNumberFields() const{
			return number_fields_;
		}
		const std::array<std::string, 2> &GetStringFields() const{
			return string_fields_;
		}
		
		std::string DebugString() const;

	private:
		const std::array<int, 2> number_fields_;
		const std::array<std::string, 2> string_fields_;
};
template <> 
struct is_layer<LCONV> {
	static constexpr bool value = true;
};


struct LPOOL{
	public:
	struct Builder{
		public:
			Builder() : number_fields_{{0}} {}
			Builder(const std::array<int, 2>& number_fields, 
				const std::array<std::string, 1>& string_fields) 
				: number_fields_{{number_fields[0],number_fields[1]}},
				  string_fields_{{string_fields[0]}}{}
			
			static constexpr int  str_name = 0;
			std::string get_str_name() const;

			static constexpr int kernel_w = 0;
			int get_kernel_w() const;

			static constexpr int kernel_h = 1;
			int get_kernel_h() const;
			
			Builder& set_str_name(std::string v);
			Builder& set_kernel_w(int v);
			Builder& set_kernel_h(int v);
			
			static std::regex& get_regex_pattern() ;
			bool Parse(const std::string &line);
			
			std::string DebugString() const;

			LPOOL build();	
			
		private:
			std::array<int, 2> number_fields_;
			std::array<std::string, 1> string_fields_;
	};

   LPOOL(const std::array<int, 2>& number_fields, 
		   const std::array<std::string, 1>& string_fields) 
			: number_fields_(number_fields), 
			  string_fields_(string_fields){ }

			static constexpr int  str_name = 0;
			std::string get_str_name() const;

			static constexpr int kernel_w = 0;
			int get_kernel_w() const;

			static constexpr int kernel_h = 1;
			int get_kernel_h() const;
		
		const char *get_layer_type() const { return "LPOOL"; }

	public:
		const std::array<int, 2>& GetNumberFields() const{
			return number_fields_;
		}
		const std::array<std::string, 1> &GetStringFields() const{
			return string_fields_;
		}
		
		std::string DebugString() const;

	private:
		const std::array<int, 2> number_fields_;
		const std::array<std::string, 1> string_fields_;
};
template <> 
struct is_layer<LPOOL> {
	static constexpr bool value = true;
};


struct LELEW{
	public:
	struct Builder{
		public:
			Builder() : number_fields_{{0}} {}
			Builder(const std::array<int, 1>& number_fields, 
				const std::array<std::string, 1>& string_fields) 
				: number_fields_{{number_fields[0]}},
				  string_fields_{{string_fields[0]}}{}
			
			static constexpr int  str_name = 0;
			std::string get_str_name() const;

			static constexpr int kernel_w = 0;
			int get_kernel_w() const;
			
			Builder& set_str_name(std::string v);
			Builder& set_kernel_w(int v);
			
			static std::regex& get_regex_pattern() ;
			bool Parse(const std::string &line);

			
			std::string DebugString() const;

			LELEW build();	
			
		private:
			std::array<int, 1> number_fields_;
			std::array<std::string, 1> string_fields_;
	};

   LELEW(const std::array<int, 1>& number_fields, 
		   const std::array<std::string, 1>& string_fields) 
			: number_fields_(number_fields), 
			  string_fields_(string_fields){ }

			static constexpr int  str_name = 0;
			std::string get_str_name() const;

			static constexpr int kernel_w = 0;
			int get_kernel_w() const;
		
		const char *get_layer_type() const { return "LELEW"; }

	public:
		const std::array<int, 1>& GetNumberFields() const{
			return number_fields_;
		}
		const std::array<std::string, 1> &GetStringFields() const{
			return string_fields_;
		}
		
		std::string DebugString() const;

	private:
		const std::array<int, 1> number_fields_;
		const std::array<std::string, 1> string_fields_;
};
template <> 
struct is_layer<LELEW> {
	static constexpr bool value = true;
};

}
