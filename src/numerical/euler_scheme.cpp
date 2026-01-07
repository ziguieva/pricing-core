#include "pricing/numerical/euler_scheme.hpp"
#include "pricing/core/exceptions.hpp"
#include "pricing/utils/time.hpp"  

#include <cmath>

namespace pricing {

Path EulerScheme::simulate(
    const Dynamics& dynamics,
    const TimeGrid& grid,
    RandomGenerator& rng,
    Real initial_value
) const
{
    if (grid.steps == 0)
        throw PricingException("TimeGrid must have at least one step");

    const Real dt = (grid.end - grid.start) / static_cast<Real>(grid.steps);

    Path path(grid.steps + 1);
    path.set(0, initial_value);

    Real current = initial_value;

    for (Size i = 1; i <= grid.steps; ++i)
    {
        const Real t = grid.start + (i - 1) * dt;
        const Real dw = std::sqrt(dt) * rng.next();

        const Real drift = dynamics.drift(t, current);
        const Real diffusion = dynamics.diffusion(t, current);

        current = current
                + drift * dt
                + diffusion * dw;

        path.set(i, current);
    }

    return path;
}

} // namespace pricing
