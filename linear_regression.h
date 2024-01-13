// linear_regression.h

#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>

double estimate_price(double theta0, double theta1, double mileage);
void gradient_descent(std::vector<double>& mileage, std::vector<double>& price, double& theta0, double& theta1, int iterations);
double calculate_mean_squared_error(const std::vector<double>& mileage, const std::vector<double>& price, double theta0, double theta1) ;
double calculate_mean_relative_error(const std::vector<double>& mileage, const std::vector<double>& price, double theta0, double theta1);
void read_csv(const std::string& filename, std::vector<double>& mileage, std::vector<double>& price);
void graph(const std::vector<double>& mileage, const std::vector<double>& price, double theta0, double theta1);

#endif
