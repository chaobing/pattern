#pragma once

#include "common.hpp"

template<typename NodeType, typename EdgeType>
class NodeNeighIter;

template<typename NodeType, typename EdgeType>
class Graph;

template<typename NodeType, typename EdgeType>
class Node{
  friend class Graph<NodeType, EdgeType>;
  public:
	Node() = default;
	virtual ~Node(){}

	int id(){ return id_ ;}
	std::list<EdgeType*> in_edges() const{
		return in_edges_;
	}
	std::list<EdgeType*> out_edges() const{
		return out_edges_;
	}

	size_t in_degree() const { return in_edges_.size(); }
	size_t out_degree() const { return out_edges_.size(); }
	
	iterator_range<NodeNeighIter<NodeType, EdgeType>> predecessors() const{
		return make_range(NodeNeighIter<NodeType, EdgeType>(in_edges_.begin(), true),
				NodeNeighIter<NodeType, EdgeType>(in_edges_.end(), true));
	}
	iterator_range<NodeNeighIter<NodeType, EdgeType>> successors() const{
		return make_range(NodeNeighIter<NodeType, EdgeType>(out_edges_.begin(), false),
				NodeNeighIter<NodeType, EdgeType>(out_edges_.end(), false));
	}

  private:
	void add_input_edge(EdgeType* e){
		assert(e != nullptr);
		in_edges_.push_back(e);
	}
	void add_output_edge(EdgeType* e){
		assert(e != nullptr);
		out_edges_.push_back(e);
	}
	void remove_input_edge(EdgeType* e){
		assert(e != nullptr);
		in_edges_.remove(e);
	}
	void remove_output_edge(EdgeType* e){
		assert(e != nullptr);
		out_edges_.remove(e);
	}
  private:
	int id_;
	std::list<EdgeType *> in_edges_;
	std::list<EdgeType *> out_edges_;
};

template<typename NodeType, typename EdgeType>
class NodeNeighIter{
  public:
	NodeNeighIter(typename std::list<EdgeType*>::const_iterator iter, bool is_input)
		: iter_(iter), is_input_(is_input){}
	~NodeNeighIter(){};
  public:
	bool operator==(const NodeNeighIter &rhs){
	  return (iter_ == rhs.iter_) && (is_input_ == rhs.is_input_);
	}
	bool operator!=(const NodeNeighIter &rhs){
	  return (iter_ != rhs.iter_) || (is_input_ != rhs.is_input_);
	}
	void operator++(){
	  ++iter_;
	}
	NodeType *operator*(){
	  return is_input_ ? ((*iter_)->src()) : ((*iter_)->dst());
	}
	NodeType *operator->(){
	  return is_input_ ? ((*iter_)->src()) : ((*iter_)->dst());
	}

  private:
	typename std::list<EdgeType*>::const_iterator iter_;
	bool is_input_;
};

template<typename NodeRef>
using NodeIter = typename std::set<NodeRef>::const_iterator;

template<typename NodeType, typename EdgeType>
class Graph{
  public:
	Graph() = default;
	~Graph(){
	  for(auto &n: nodes_) delete n;
	  for(auto &e: edges_) delete e;
	};
  public:
	void addEdge(EdgeType* e){
		assert(e != nullptr);
		assert(edges_.find(e) == edges_.end());
		auto src = e->src();
		auto dst = e->dst();
		assert(src && dst);
		src->add_output_edge(e);
		dst->add_input_edge(e);
		edges_.insert(e);
	}
	void addNode(NodeType* n){
		assert(n != nullptr);
		assert(nodes_.find(n) == nodes_.end());
		nodes_.insert(n);
		n->id_ = id_counter_++;
	}
	void removeEdge(const EdgeType* e){
		assert(e != nullptr);
		EdgeType* del = const_cast<EdgeType*>(e);
		assert(edges_.find(del) != edges_.end());
		auto src = del->src();
		auto dst = del->dst();
		assert(src && dst);
		src->remove_output_edge(del);
		dst->remove_input_edge(del);
		edges_.erase(del);
	}
	void removeNode(NodeType* n){
		assert(n != nullptr);
		assert(nodes_.find(n) != nodes_.end());
		NodeType* del = const_cast<NodeType*>(n);
		assert(del->in_degree() == 0 && del->out_degree() == 0);
		nodes_.erase(del);
	}
	size_t num_edges(){ return edges_.size(); }
	size_t num_nodes(){ return nodes_.size(); }
		
	iterator_range<NodeIter<NodeType*>> nodes() const{
		return make_range(NodeIter<NodeType*>(nodes_.begin()),
					NodeIter<NodeType*> (nodes_.end()));
	}
  private:
	int id_counter_;
	set<NodeType*> nodes_;
	set<EdgeType*> edges_;
};
