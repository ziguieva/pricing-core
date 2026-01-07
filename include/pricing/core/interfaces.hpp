#pragma once

#include "pricing/core/types.hpp"

namespace pricing {

/**
 * Interface for any numerical model.
 */
class Model
{
public:
    virtual ~Model() = default;

    virtual Real value() const = 0;
};

} // namespace pricing
