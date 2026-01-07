cmake_minimum_required(VERSION 3.20)

project(pricing_core
        VERSION 0.1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------
# CTest (REQUIRED for ctest to work)
# -------------------------------------------------
include(CTest)
enable_testing()

# -------------------------------------------------
# Pricing core library
# -------------------------------------------------
add_library(pricing_core
    src/stochastic/path.cpp
    src/numerical/euler_scheme.cpp
    src/models/black_scholes.cpp
    src/montecarlo/engine.cpp
    src/payoff/european_call.cpp
    src/pricer/montecarlo_pricer.cpp
    src/math/gaussian_rng.cpp
)

target_include_directories(pricing_core
    PUBLIC
        include
)

# -------------------------------------------------
# Example executable
# -------------------------------------------------
add_executable(european_call_pricing
    examples/european_call_pricing.cpp
)

target_link_libraries(european_call_pricing
    pricing_core
)

# -------------------------------------------------
# Tests
# -------------------------------------------------
add_subdirectory(tests)
