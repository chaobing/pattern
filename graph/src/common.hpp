#pragma once

#include <memory>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <unordered_map>


using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::set;
using std::map;
using std::list;
using std::queue;
using std::stack;
using std::string;
using std::cout;
using std::endl;
using std::to_string;

#define DISABLE_COPY_AND_ASSIGN(classname) \
	private:\
		classname(const classname&);\
		classname& operator=(const classname&);

template <typename IteratorT>
class iterator_range {
  public:
	iterator_range() : begin_iterator_(), end_iterator_() {}
	iterator_range(IteratorT begin_iterator, IteratorT end_iterator)
		: begin_iterator_(std::move(begin_iterator)),
		  end_iterator_(std::move(end_iterator)) {}

	IteratorT begin() const { return begin_iterator_; }
	IteratorT end() const { return end_iterator_; }

  private:
	IteratorT begin_iterator_, end_iterator_;
};

template <class T>
iterator_range<T> make_range(T x, T y) {
	return iterator_range<T>(std::move(x), std::move(y));
}

