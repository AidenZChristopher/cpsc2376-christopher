#include "MixedFraction.h"
#include <iostream>
#include "Fraction.h"
#include <stdexcept>

std::ostream& operator<<(std::ostream& os, const MixedFraction& mf) {
    int whole = mf.getNum() / mf.getDen(); 
    int remainder = mf.getNum() % mf.getDen();

    if (remainder == 0) 
    {
        os << whole; 
    }
    else if (whole == 0)
    {
        os << mf.getNum() << "/" << mf.getDen(); 
    }
    else {
        os << whole << " " << remainder << "/" << mf.getDen();
    }

    return os;
}