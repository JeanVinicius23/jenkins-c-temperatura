#include "conversor.h"

double celsius_para_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_para_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
