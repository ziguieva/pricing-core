#pragma once

#include "pricing/montecarlo/engine.hpp"
#include "pricing/payoff/payoff.hpp"

namespace pricing {

/**
 * Monte Carlo pricer.
 */
class MonteCarloPricer
{
public:
    explicit MonteCarloPricer(const MonteCarloEngine& engine);

    /**
     * @brief Price a product using Monte Carlo.
     */
    Real price(
        const Payoff& payoff,
        const Dynamics& dynamics,
        const TimeGrid& grid,
        RandomGenerator& rng,
        Real initial_value,
        Real discount_factor
    ) const;

private:
    const MonteCarloEngine& engine_;
};

} // namespace pricing
