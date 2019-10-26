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

bool StringGraph::connected()
{
  size_t node = 0;
  map<const StringNode*, bool> visited;
  queue<StringNode*> Q;
  auto randNode = *(nodes().begin());
  Q.push(randNode);
  visited[randNode] = true;
  while(!Q.empty()){
	node++;
	auto l = Q.front();
	Q.pop();
	for(auto pre : l->predecessors()){
	  if(visited.find(pre) == visited.end()){
		visited[pre] = true;
		Q.push(pre);
	  }
	}
	for(auto su : l->successors()){
	  if(visited.find(su) == visited.end()){
		visited[su] = true;
		Q.push(su);
	  }
	}
  }
  return node == this->num_nodes();
}

StringNode* StringGraph::entry() const
{
  StringNode *ret = nullptr;
  for(auto &n : nodes()){
	if(n->val() == "entry"){
		ret = n;
		break;
	}
  }
  return ret;
}

StringNode* StringGraph::exit() const
{
  StringNode *ret = nullptr;
  for(auto &n : nodes()){
	if(n->val() == "exit"){
		ret = n;
		break;
	}
  }
  return ret;
}

void StringGraph::addEntryExit()
{
  assert(connected());
  int entry_idx=0, exit_idx=0;
  vector<StringNode*> nodes(Graph::nodes().begin(), Graph::nodes().end());
  auto en = CreateNode("entry");
  auto ex = CreateNode("exit");
  for(auto &n : nodes){
	assert(n->val() != "entry" || n->val() != "exit");
	if(n->in_degree() == 0){
		this->addStringEdge(en, entry_idx++, n, 0);
	}
	if(n->out_degree() == 0){
		this->addStringEdge(n, 0, ex, exit_idx++);
	}
  }
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

