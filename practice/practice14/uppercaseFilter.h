#include "filterStrategy.h"
#include <string>
#include <cctype>

class UppercaseFilter : public FilterStrategy
{
public:
    std::string apply(const std::string& text) const override
    {
        std::string result;
        for (char c : text)
        {
            result += std::toupper(static_cast<unsigned char>(c));
        }
        return result;
    }
};
