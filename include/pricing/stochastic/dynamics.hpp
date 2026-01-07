#pragma once

#include "pricing/core/types.hpp"

namespace pricing {

/**
 * Defines the drift and diffusion of a process.
 */
class Dynamics
{
public:
    virtual ~Dynamics() = default;

    virtual Real drift(Time t, Real x) const = 0;
    virtual Real diffusion(Time t, Real x) const = 0;
};

} // namespace pricing