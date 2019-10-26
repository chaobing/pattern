#pragma once
#include "common.hpp"

template<typename Graph, typename Node>
void topological(const Graph *g, const std::function<void(Node*)> &fun)
{
  queue<Node*> Q;
  map<Node*, int> indgreeTable;
  for(auto n:g->nodes()){
    if(n->in_degree() != 0){
	  indgreeTable[n] = n->in_degree();
	}else{
	  Q.push(n);
	}
  }
  assert(Q.size() != 0);
  size_t num = Q.size();
  while(!Q.empty()){
	auto node = Q.front();
	Q.pop();
	if(fun) fun(node);
	num++;
	for(auto succ : node->successors()){
	  if(--indgreeTable[succ] == 0) Q.push(succ);
	}
  }
  assert(num != g->num_nodes());
}

template<typename Graph, typename Node>
void getTopo(const Graph *g, vector<Node*> &vec)
{
  vec.clear();
  auto fun = std::function<void(Node*)>(
	  [&vec](Node* node){
		vec.push_back(node);	
	  });
  topological(g, fun);
}

template<typename Graph, typename Node>
void BFS(const Graph *g, const std::function<void(Node*)> &fun)
{
  queue<Node*> Q;
  std::unordered_map<const Node*, bool> visited;
  auto root = g->entry();
  Q.push(root);
  visited[root] = true;
  while(!Q.empty()){
	auto cur = Q.front();
	Q.pop();
	if(fun) fun(cur);
	for(auto succ : cur->successors()){
	  if(visited.find(succ) == visited.end()){
		  visited[succ] = true;
		  Q.push(succ);
	  }
	}
  }	
}

template<typename Graph, typename Node>
void getBFS(const Graph *g, vector<Node*> &vec)
{
  vec.clear();
  auto fun = std::function<void(Node*)>(
	  [&vec](Node* node){
		vec.push_back(node);	
	  });
  BFS(g, fun);
}
