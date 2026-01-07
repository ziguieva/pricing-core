#include "pricing/stochastic/path.hpp"
#include "pricing/core/exceptions.hpp"

namespace pricing {

Path::Path(Size size)
    : values_(size, 0.0)
{
    if (size == 0)
        throw PricingException("Path size must be positive");
}

void Path::set(Size index, Real value)
{
    values_.at(index) = value;
}

Real Path::get(Size index) const
{
    return values_.at(index);
}

Size Path::size() const
{
    return values_.size();
}

} // namespace pricing
