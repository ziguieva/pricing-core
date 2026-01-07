 #include "pricing/pricer/montecarlo_pricer.hpp"

namespace pricing {

MonteCarloPricer::MonteCarloPricer(const MonteCarloEngine& engine)
    : engine_(engine)
{
}

Real MonteCarloPricer::price(
    const Payoff& payoff,
    const Dynamics& dynamics,
    const TimeGrid& grid,
    RandomGenerator& rng,
    Real initial_value,
    Real discount_factor
) const
{
    const auto paths = engine_.simulate(dynamics, grid, rng, initial_value);

    Real sum = 0.0;

    for (const auto& path : paths)
    {
        const Real terminal_spot = path.get(path.size() - 1);
        sum += payoff(terminal_spot);
    }

    return discount_factor * (sum / static_cast<Real>(paths.size()));
}

} // namespace pricing
