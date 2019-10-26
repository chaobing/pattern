#include "stringgraph.hpp"

StringNode* StringGraph::CreateNode(string name)
{
	StringNode* node = new StringNode(name);
	node->g_ = this;
	Graph::addNode(node);
	return node;
}

const StringEdge* StringGraph::addStringEdge(StringNode* src, int src_output, StringNode* dst, int dst_input)
{
	assert(src && dst);
	assert(src_output != -1);
	assert(dst_input != -1);
	StringEdge* edge = new StringEdge();
	edge->src_ = src;
	edge->src_output_ = src_output;
	edge->dst_ = dst;
	edge->dst_input_ = dst_input;
	Graph::addEdge(edge);
	return edge;
}

void StringGraph::dump(string save_name)
{
  std::ofstream f;
  f.open(save_name, std::ios::trunc);

  string vcg = "digraph G {\n";
  vcg += "ordering = out \n";
  vcg += "node [shape=box3d, fontcolor=black, style=filled]\n";
  for(auto l : nodes()){
	vcg += to_string(l->id());
	vcg += "[";
	vcg += "label = \"" + l->val() + "\"";
	vcg += "]\n";
  }
  for(auto l : nodes()){
    for(auto &e : l->out_edges()){
		auto src = e->src();
		auto dst = e->dst();
		auto src_idx = e->src_output();
		auto dst_idx = e->dst_input();
		vcg += to_string(src->id()) + "->" + to_string(dst->id());
		vcg += "[label = \"(" + to_string(src_idx) + 
					":" + to_string(dst_idx) + ")\"]";
		vcg += "\n";
	}
  }
  vcg += "}\n";
  f<<vcg;
  f.close();
}

