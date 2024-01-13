// gradient_descent.cpp
#include "linear_regression.h"

void gradient_descent(std::vector<double>& mileage, std::vector<double>& price, double& theta0, double& theta1, int iterations) {
    int m = mileage.size();
    double learning_rate = 0.1;
    double beta1 = 0.9;
    double beta2 = 0.999;
    double epsilon = 1e-8;
    double m_t0 = 0, m_t1 = 0, v_t0 = 0, v_t1 = 0;

    std::ofstream outfile("theta.csv");
    for (int iter = 0; iter < iterations; ++iter) {
        double sum_grad0 = 0, sum_grad1 = 0;
        for (int i = 0; i < m; ++i) {
            double error = estimate_price(mileage[i], theta0, theta1) - price[i];
            sum_grad0 += error;
            sum_grad1 += error * mileage[i];
        }
        m_t0 = beta1 * m_t0 + (1 - beta1) * sum_grad0 / m;
        m_t1 = beta1 * m_t1 + (1 - beta1) * sum_grad1 / m;
        v_t0 = beta2 * v_t0 + (1 - beta2) * (sum_grad0 / m) * (sum_grad0 / m);
        v_t1 = beta2 * v_t1 + (1 - beta2) * (sum_grad1 / m) * (sum_grad1 / m);
        double m_t0_hat = m_t0 / (1 - std::pow(beta1, iter + 1));
        double m_t1_hat = m_t1 / (1 - std::pow(beta1, iter + 1));
        double v_t0_hat = v_t0 / (1 - std::pow(beta2, iter + 1));
        double v_t1_hat = v_t1 / (1 - std::pow(beta2, iter + 1));
        theta0 -= (learning_rate / (std::sqrt(v_t0_hat) + epsilon)) * m_t0_hat;
        theta1 -= (learning_rate / (std::sqrt(v_t1_hat) + epsilon)) * m_t1_hat;
        outfile << theta0 << "," << theta1 << "," << calculate_mean_squared_error(mileage, price, theta0, theta1) << std::endl;
    }
    outfile.close();
}