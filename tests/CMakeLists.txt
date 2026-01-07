cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(pricing_core_tests
    test_payoff.cpp
    test_black_scholes.cpp
    test_montecarlo_convergence.cpp 
)

target_link_libraries(pricing_core_tests
    pricing_core
    gtest_main
)

# ✅ ENREGISTRE LE TEST EXPLICITEMENT
add_test(
    NAME pricing_core_tests
    COMMAND pricing_core_tests
)
