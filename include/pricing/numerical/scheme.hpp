#pragma once

#include "pricing/core/types.hpp"
#include "pricing/stochastic/path.hpp"
#include "pricing/stochastic/dynamics.hpp"
#include "pricing/math/random.hpp"
#include "pricing/utils/time.hpp"   // ✅ AJOUT

namespace pricing {

/**
 * Base class for numerical schemes used to simulate stochastic processes.
 */
class NumericalScheme
{
public:
    virtual ~NumericalScheme() = default;

    /**
     * @brief Simulate a path using the given dynamics and random generator.
     */
    virtual Path simulate(
        const Dynamics& dynamics,
        const TimeGrid& grid,
        RandomGenerator& rng,
        Real initial_value
    ) const = 0;
};

} // namespace pricing
