#include "filterStrategy.h"
#include <algorithm>

class ReverseFilter : public FilterStrategy
{
public:
    std::string apply(const std::string& text) const override
    {
        std::string result = text;
        std::reverse(result.begin(), result.end());
        return result;
    }
};
