#include <iostream>
#include <string>

int printEvulationAndFindGCD(int& evulationA, int& evulationB, int& r) {

    int dev = evulationA / evulationB;
    r = evulationA % evulationB;
    std::cout << evulationA << "=" << evulationB << "*" << dev << "+" << r << std::endl;
    evulationA = evulationB;
    evulationB = r;

    if (r == 0) { return evulationA; }
    else {
        printEvulationAndFindGCD(evulationA, evulationB, r);
    }
}

int main()
{
    int a;
    int b;
    std::cin >> a >> b; std::cin.ignore();

    int r;
    int evulationA = a;
    int evulationB = b;


    int GCD = printEvulationAndFindGCD(evulationA, evulationB, r);

    std::cout << "GCD(" << a << "," << b << ")=" << GCD << std::endl;

    return 0;
}