#include "filterStrategy.h"
#include <string>
#include <vector>
#include <algorithm>

class CensorFilter : public FilterStrategy
{
public:
    std::string apply(const std::string& text) const override
    {
        std::string result = text;
        std::vector<std::string> badWords = { "bad", "ugly", "dumb" };
        for (const auto& word : badWords)
        {
            auto pos = result.find(word);
            while (pos != std::string::npos)
            {
                result.replace(pos, word.length(), std::string(word.length(), '*'));
                pos = result.find(word, pos + 1);
            }
        }
        return result;
    }
};
