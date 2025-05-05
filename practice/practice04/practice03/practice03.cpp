#include <iostream>
#include <vector>

class MathUtils {
public:
    static int sumRange(int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) //Bug FIXED
        {
            sum += i;
        }
        return sum;
    }

    static bool containsNegative(const std::vector<int>& numbers) {
        for (size_t i = 0; i < numbers.size(); i++) { // Bug FIXED
            if (numbers[i] < 0) { // Bug FIXED
                return true;
            }
        }
        return false;
    }

    static int findMax(const std::vector<int>& numbers) {
        if (numbers.empty()) return false; //Bug FIXED
        int maxVal = numbers[0];
        for (size_t i = 1; i < numbers.size(); i++) { // Bug FIXED
            if (numbers[i] >= maxVal) { // Bug FIXED
                maxVal = numbers[i];
            }
        }
        return maxVal;
    }
};

int main() {
    std::cout << "Sum from 1 to 5: " << MathUtils::sumRange(1, 5) << std::endl;
    std::vector<int> values = { 3, -1, 5, 7 };
    std::cout << "Contains negative? " << MathUtils::containsNegative(values) << std::endl;
    std::cout << "Max value: " << MathUtils::findMax(values) << std::endl;
    return 0;
}



//#include <iostream>
////#include "mathStuff.h"
//
//int main()
//{
//    //Rectangle r{ 3, 4 };
//    //std::cout << "add 2+3: " << add(2, 3) << "\n";
//    //std::cout << "doubleValue 5: " << doubleValue(5) << "\n";
//    //std::cout << "Area: " << r.area() << std::endl;
//}
