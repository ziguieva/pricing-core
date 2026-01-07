#include <gtest/gtest.h>
#include <cmath>

#include "pricing/models/black_scholes.hpp"
#include "pricing/numerical/euler_scheme.hpp"
#include "pricing/montecarlo/engine.hpp"
#include "pricing/pricer/montecarlo_pricer.hpp"
#include "pricing/payoff/european_call.hpp"
#include "pricing/math/gaussian_rng.hpp"
#include "pricing/utils/time.hpp"

using namespace pricing;

// ------------------------------------------------------------
// Black-Scholes analytical formula for European Call
// ------------------------------------------------------------
static Real normal_cdf(Real x)
{
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

static Real black_scholes_call_price(
    Real spot,
    Real strike,
    Real rate,
    Real volatility,
    Real maturity
)
{
    const Real sqrtT = std::sqrt(maturity);
    const Real d1 = (std::log(spot / strike)
                    + (rate + 0.5 * volatility * volatility) * maturity)
                    / (volatility * sqrtT);

    const Real d2 = d1 - volatility * sqrtT;

    return spot * normal_cdf(d1)
         - strike * std::exp(-rate * maturity) * normal_cdf(d2);
}

// ------------------------------------------------------------
// Monte Carlo convergence test
// ------------------------------------------------------------
TEST(MonteCarloConvergence, EuropeanCallConvergesToBlackScholes)
{
    // --- Model parameters ---
    const Real spot = 100.0;
    const Real strike = 100.0;
    const Real rate = 0.05;
    const Real volatility = 0.2;
    const Real maturity = 1.0;

    // --- Numerical parameters ---
    const Size time_steps = 100;
    const Size num_paths = 200'000;
    const unsigned int seed = 42;

    const Real tolerance = 0.5; // Monte Carlo statistical tolerance

    // --- Time grid ---
    TimeGrid grid{0.0, maturity, time_steps};

    // --- Model ---
    BlackScholesDynamics dynamics(rate, volatility);

    // --- Scheme ---
    EulerScheme scheme;

    // --- RNG ---
    GaussianRNG rng(seed);

    // --- Monte Carlo engine ---
    MonteCarloEngine engine(scheme, num_paths);

    // --- Payoff ---
    EuropeanCall payoff(strike);

    // --- Pricer ---
    MonteCarloPricer pricer(engine);

    const Real discount_factor = std::exp(-rate * maturity);

    const Real mc_price = pricer.price(
        payoff,
        dynamics,
        grid,
        rng,
        spot,
        discount_factor
    );

    const Real bs_price = black_scholes_call_price(
        spot,
        strike,
        rate,
        volatility,
        maturity
    );

    EXPECT_NEAR(mc_price, bs_price, tolerance);
}
