#pragma once

#include <stdexcept>
#include <string>

namespace pricing {

/**
 * Base exception for the pricing core.
 */
class PricingException : public std::runtime_error
{
public:
    explicit PricingException(const std::string& message)
        : std::runtime_error(message) {}
};

} // namespace pricing
