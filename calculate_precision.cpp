// calculate_precision.cpp
#include "linear_regression.h"

double calculate_mean_relative_error(const std::vector<double>& mileage, const std::vector<double>& price, double theta0, double theta1) {
    double sum_relative_error = 0.0;
    int m = mileage.size();

    for (int i = 0; i < m; ++i) {
        double predicted_price = estimate_price(mileage[i], theta0, theta1);
        sum_relative_error += std::abs((predicted_price - price[i]) / price[i]);
    }
    return (sum_relative_error / m);
}
