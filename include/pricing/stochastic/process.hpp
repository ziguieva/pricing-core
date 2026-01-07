#pragma once

#include "pricing/core/types.hpp"
#include "pricing/stochastic/path.hpp"

namespace pricing {

/**
 * Abstract representation of a stochastic process.
 *
 * A process defines how a state evolves over time.
 */
class StochasticProcess
{
public:
    virtual ~StochasticProcess() = default;

    /**
     * @brief Simulate one path of the process.
     */
    virtual Path simulate(const TimeGrid& grid) const = 0;
};

} // namespace pricing
