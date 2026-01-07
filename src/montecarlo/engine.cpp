#include "pricing/montecarlo/engine.hpp"
#include "pricing/core/exceptions.hpp"

#include <vector>

namespace pricing {

MonteCarloEngine::MonteCarloEngine(
    const NumericalScheme& scheme,
    Size number_of_paths
)
    : scheme_(scheme),
      number_of_paths_(number_of_paths)
{
    if (number_of_paths_ == 0)
        throw PricingException("Number of paths must be positive");
}

std::vector<Path> MonteCarloEngine::simulate(
    const Dynamics& dynamics,
    const TimeGrid& grid,
    RandomGenerator& rng,
    Real initial_value
) const
{
    std::vector<Path> paths;
    paths.reserve(number_of_paths_);

    for (Size i = 0; i < number_of_paths_; ++i)
    {
        paths.push_back(
            scheme_.simulate(dynamics, grid, rng, initial_value)
        );
    }

    return paths;
}

} // namespace pricing
