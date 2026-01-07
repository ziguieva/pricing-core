#include "pricing/math/gaussian_rng.hpp"

namespace pricing {

GaussianRNG::GaussianRNG(unsigned int seed)
    : engine_(seed),
      distribution_(0.0, 1.0)
{
}

Real GaussianRNG::next()
{
    return distribution_(engine_);
}

} // namespace pricing
