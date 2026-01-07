#include <iostream>

#include "pricing/models/black_scholes.hpp"
#include "pricing/numerical/euler_scheme.hpp"
#include "pricing/montecarlo/engine.hpp"
#include "pricing/pricer/montecarlo_pricer.hpp"
#include "pricing/payoff/european_call.hpp"
#include "pricing/math/gaussian_rng.hpp"
#include "pricing/utils/time.hpp"

using namespace pricing;

int main()
{
    // --- Model parameters ---
    const Real spot = 100.0;
    const Real strike = 100.0;
    const Real maturity = 1.0;
    const Real rate = 0.05;
    const Real volatility = 0.2;

    // --- Numerical parameters ---
    const Size time_steps = 100;
    const Size num_paths = 100'000;
    const unsigned int seed = 42;

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

    const Real price = pricer.price(
        payoff,
        dynamics,
        grid,
        rng,
        spot,
        discount_factor
    );

    std::cout << "European Call Price (Monte Carlo): "
              << price << std::endl;

    return 0;
}
