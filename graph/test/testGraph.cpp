
#include "common.hpp"
#include "stringgraph.hpp"

void testGraph(){
	auto sg = make_shared<StringGraph>();
	sg->CreateNode("apple");
	sg->CreateNode("banana");
	sg->CreateNode("cup");
	sg->CreateNode("dog");
	//sg->CreateNode("egg");
	StringNode *node = new StringNode("egg");
	sg->addNode(node);

	std::unordered_map<int, StringNode*> idx2node;
	for(auto nit : sg->nodes()){
		cout <<"\tid: " <<nit->id()<<", \tval:"<<nit->val()<<endl;
		idx2node[nit->id()] = nit;
	}
	sg->addStringEdge(idx2node[0], 1, idx2node[1], 0);
	sg->addStringEdge(idx2node[0], 2, idx2node[2], 0);
	sg->addStringEdge(idx2node[2], 3, idx2node[3], 2);
	sg->addStringEdge(idx2node[1], 3, idx2node[3], 1);
	sg->addStringEdge(idx2node[0], 4, idx2node[4], 0);
	sg->addStringEdge(idx2node[3], 4, idx2node[4], 3);
	
	sg->dump("stringGraph.gv");
	//save to jpg
	// dot -Tjpg stringGraph.gv -O stringGraph.jpg
	
}

int main(int argc, char*argv[]){
	testGraph();	
	return 0;
}
