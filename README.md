# pricing-core

C++20 Monte Carlo pricing library for financial derivatives.

This repository is a quantitative engineering project demonstrating how
pricing engines are structured, implemented and validated in professional
Pricing & Analytics / Quantitative Development environments.

---

## Features

- Black–Scholes stochastic dynamics
- Euler–Maruyama numerical discretization
- Monte Carlo simulation engine
- European Call option pricing
- Reproducible Gaussian random number generation
- Unit tests and Monte Carlo convergence test
- Validation against analytical Black–Scholes formula

---

## Architecture

pricing-core/
├── include/pricing/
│   ├── stochastic/
│   ├── numerical/
│   ├── models/
│   ├── montecarlo/
│   ├── payoff/
│   ├── pricer/
│   └── math/
├── src/
├── tests/
├── examples/
└── CMakeLists.txt

Design principles:
- strict separation between model, numerics and pricing
- interchangeable components (models, schemes, RNG)
- reproducible Monte Carlo simulations
- production-style C++ design

---

## Mathematical Model

Black–Scholes dynamics:

dS = μ S dt + σ S dW

European Call price:

Price = exp(-rT) * E[max(S_T - K, 0)]

Monte Carlo results are validated against the analytical
Black–Scholes formula.

---

## Build

Requirements:
- C++20 compiler
- CMake >= 3.20

Build instructions:

git clone <repo-url>
cd pricing-core
mkdir build && cd build
cmake ..
cmake --build .

---

## Tests

The project includes unit tests and a Monte Carlo convergence test.

Run all tests:

ctest -V

---

## Example

Run the pricing example:

./european_call_pricing

Typical output:

European Call Price (Monte Carlo): ~10.4

---

## Purpose

This repository is a quantitative engineering portfolio project showcasing
clean C++ design, numerical methods and financial modeling at a professional
level.
