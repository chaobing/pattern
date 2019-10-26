#pragma once

#include "graph.hpp"

class StringGraph;
class StringEdge;

class StringNode: public Node<StringNode, StringEdge>{
  friend class StringGraph;
  public:
	StringNode(string val): val_(val){}

  public:
	string val(){ return val_; }
	const StringGraph* graph(){ return g_; }

  protected:
	string val_;
	const StringGraph *g_{nullptr};
};

class StringEdge{
  friend class StringGraph;
  public:
	StringEdge(){};
	~StringEdge(){};
	StringNode* src() const { return src_; }
	StringNode* dst() const { return dst_; }
	int src_output() const{ return src_output_;};
	int dst_input() const{ return dst_input_; };
	
  private:
	StringNode *src_{nullptr};
	StringNode *dst_{nullptr};
	int src_output_{-1};
	int dst_input_{-1};

	DISABLE_COPY_AND_ASSIGN(StringEdge)
};

class StringGraph : public Graph<StringNode, StringEdge>{
  public:
	StringGraph() = default;
	StringNode* CreateNode(string name);
	const StringEdge* addStringEdge(StringNode* src, int src_output,
								  StringNode* dst, int dst_input);
	bool connected();
	StringNode* entry() const; 
	StringNode* exit() const;
	void addEntryExit();

	void dump(string save_name);
};

