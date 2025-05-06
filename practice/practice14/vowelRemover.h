#include "filterStrategy.h"
#include <string>
#include <set>

class VowelRemover : public FilterStrategy
{
public:
    std::string apply(const std::string& text) const override
    {
        std::string result;
        std::set<char> vowels = { 'a','e','i','o','u','A','E','I','O','U' };
        for (char c : text)
        {
            if (vowels.find(c) == vowels.end())
            {
                result += c;
            }
        }
        return result;
    }
};
