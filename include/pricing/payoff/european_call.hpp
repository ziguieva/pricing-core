#pragma once

#include "pricing/payoff/payoff.hpp"

namespace pricing {

/**
 * European Call option payoff.
 */
class EuropeanCall : public Payoff
{
public:
    explicit EuropeanCall(Real strike);

    Real operator()(Real spot) const override;

private:
    Real strike_;
};

} // namespace pricing
