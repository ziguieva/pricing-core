#pragma once

#include "pricing/stochastic/dynamics.hpp"
#include "pricing/core/types.hpp"

namespace pricing {

/**
 * Black-Scholes dynamics for equity prices.
 *
 * dS = mu * S dt + sigma * S dW
 */
class BlackScholesDynamics : public Dynamics
{
public:
    BlackScholesDynamics(Real mu, Real sigma);

    Real drift(Time t, Real x) const override;
    Real diffusion(Time t, Real x) const override;

private:
    Real mu_;
    Real sigma_;
};

} // namespace pricing
