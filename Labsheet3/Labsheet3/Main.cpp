#include <iostream>
#include "Beacon.h"
#include "Receiver.h"

int main()
{
    std::cout << "Beacon pool lab\n";

    std::cout << "\nConnection check\n";
    Beacon demoBeacon{10};
    Receiver receiver{35};
    std::cout << "Range to beacon: " << receiver.rangeTo(demoBeacon) << '\n';

    return 0;
}
