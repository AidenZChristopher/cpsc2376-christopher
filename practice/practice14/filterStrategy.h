#pragma once
#include <string>

class FilterStrategy
{
public:
    virtual std::string apply(const std::string& text) const = 0;
    virtual ~FilterStrategy() = default;
};