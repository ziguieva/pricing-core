#include "pricing/models/black_scholes.hpp"
#include "pricing/core/exceptions.hpp"

namespace pricing {

BlackScholesDynamics::BlackScholesDynamics(Real mu, Real sigma)
    : mu_(mu), sigma_(sigma)
{
    if (sigma_ < 0.0)
        throw PricingException("Volatility must be non-negative");
}

Real BlackScholesDynamics::drift(Time /*t*/, Real x) const
{
    return mu_ * x;
}

Real BlackScholesDynamics::diffusion(Time /*t*/, Real x) const
{
    return sigma_ * x;
}

} // namespace pricing
