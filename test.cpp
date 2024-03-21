#include <iostream>

int main() {
    float chickens, days, eggs;
    
    // Part 1: User input for the first scenario.
    std::cout << "Enter the number of chickens for scenario 1: ";
    std::cin >> chickens;
    std::cout << "Enter the number of days for scenario 1: ";
    std::cin >> days;
    std::cout << "Enter the total number of eggs for scenario 1: ";
    std::cin >> eggs;

    // Calculate the rate of egg production per chicken per day.
    float ratePerDay = eggs / (chickens * days);

    // Use the rate to calculate the total number of eggs for the first scenario.
    float totalEggs1 = chickens * days * ratePerDay;
    std::cout << "Total eggs for scenario 1: " << totalEggs1 << std::endl;

    // Part 2: User input for the second scenario.
    std::cout << "Enter the number of chickens for scenario 2: ";
    std::cin >> chickens;
    std::cout << "Enter the number of days for scenario 2: ";
    std::cin >> days;

    // Use the previously calculated rate to calculate the total number of eggs for the second scenario.
    float totalEggs2 = chickens * days * ratePerDay;
    std::cout << "Total eggs for scenario 2: " << totalEggs2 << std::endl;

    return 0;
}
