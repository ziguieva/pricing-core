#pragma once

#include "pricing/core/types.hpp"
#include "pricing/stochastic/dynamics.hpp"
#include "pricing/numerical/scheme.hpp"
#include "pricing/math/random.hpp"

namespace pricing {

/**
 * Monte Carlo engine responsible for simulating multiple paths.
 */
class MonteCarloEngine
{
public:
    MonteCarloEngine(
        const NumericalScheme& scheme,
        Size number_of_paths
    );

    /**
     * @brief Run Monte Carlo simulation.
     */
    std::vector<Path> simulate(
        const Dynamics& dynamics,
        const TimeGrid& grid,
        RandomGenerator& rng,
        Real initial_value
    ) const;

private:
    const NumericalScheme& scheme_;
    Size number_of_paths_;
};

} // namespace pricing
