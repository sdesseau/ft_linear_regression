// linear_regression.h

#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>

double estimate_price(double mileage, double theta0, double theta1);
void gradient_descent(std::vector<double>& mileage, std::vector<double>& price, double& theta0, double& theta1, int iterations);
double calculate_mean_relative_error(const std::vector<double>& mileage, const std::vector<double>& price, double theta0, double theta1);
void read_csv(const std::string& filename, std::vector<double>& mileage, std::vector<double>& price);
void plot_data_and_model(const std::vector<double>& mileage, const std::vector<double>& price, double theta0, double theta1);

#endif
