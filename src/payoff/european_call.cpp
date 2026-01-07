#include "pricing/payoff/european_call.hpp"
#include "pricing/core/exceptions.hpp"

#include <algorithm>

namespace pricing {

EuropeanCall::EuropeanCall(Real strike)
    : strike_(strike)
{
    if (strike_ <= 0.0)
        throw PricingException("Strike must be positive");
}

Real EuropeanCall::operator()(Real spot) const
{
    return std::max(spot - strike_, 0.0);
}

} // namespace pricing
