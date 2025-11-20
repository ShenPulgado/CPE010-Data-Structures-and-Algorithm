#include <iostream>

double kToF(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

int main() {
    double kelvin = 500.0;
    double fahrenheit = kToF(kelvin);
    std::cout << kelvin << " K is equal to " 
              << fahrenheit << " °F" << std::endl;
    return 0;
}



