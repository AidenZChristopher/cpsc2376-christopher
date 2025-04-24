#include "rectangle.h"
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<Rectangle> r1 = std::make_shared<Rectangle>(10, 10);
    std::shared_ptr<Rectangle> r2 = r1;

    std::cout << "Use count: " << r1.use_count() << std::endl;

    r1.reset();

    std::cout << "After r1.reset(), use count: " << r2.use_count() << std::endl;

    return 0;
}