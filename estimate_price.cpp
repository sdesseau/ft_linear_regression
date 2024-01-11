// estimate_price.cpp
#include "linear_regression.h"

double estimate_price(double mileage, double theta0, double theta1) {
    return (theta0 + theta1 * mileage);
}
