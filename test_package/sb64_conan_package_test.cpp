#include <iostream>
#include "sb64/Letter.h"

int main()
{
    std::cout << sb64::Letter{0}.to_uchar() << "\n";

    return 0;
};
