#include "Layer.hpp"
#include "LayerFactory.hpp"

int main(int argc, char*argv[]){
	auto cl = whole_fac::LayerFactory::create("Convolution", "isLayerConvolution");
	if(cl) cl->exec();
	auto pl = whole_fac::LayerFactory::create("Pooling", "Pooling");
	if(pl) pl->exec();
	auto el = whole_fac::LayerFactory::create("Eltwise", "isLayerEltwise");
	if(el) el->exec();
	return 0;
}
