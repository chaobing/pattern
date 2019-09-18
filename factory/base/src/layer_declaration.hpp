
#include "layer/convolution.hpp"
namespace layer_base {
class Convolution_final : virtual public Convolution
{
};
DEFINE_LAYER_CREATOR(Convolution_final)
} // namespace layer_base

#include "layer/pooling.hpp"
namespace layer_base {
class Pooling_final : virtual public Pooling
{
};
DEFINE_LAYER_CREATOR(Pooling_final)
} // namespace layer_base


#include "layer/eltwise.hpp"
namespace layer_base {
class Eltwise_final : virtual public Eltwise
{
};
DEFINE_LAYER_CREATOR(Eltwise_final)
} // namespace layer_base
