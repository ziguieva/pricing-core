#pragma once

#include "pricing/numerical/scheme.hpp"
#include "pricing/utils/time.hpp"   // ✅ AJOUT

namespace pricing {

class EulerScheme : public NumericalScheme
{
public:
    Path simulate(
        const Dynamics& dynamics,
        const TimeGrid& grid,
        RandomGenerator& rng,
        Real initial_value
    ) const override;
};

} // namespace pricing
