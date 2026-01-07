#pragma once

#include <vector>
#include "pricing/core/types.hpp"

namespace pricing {

/**
 * Discrete representation of a stochastic path.
 */
class Path
{
public:
    explicit Path(Size size);

    void set(Size index, Real value);
    Real get(Size index) const;

    Size size() const;

private:
    std::vector<Real> values_;
};

} // namespace pricing
