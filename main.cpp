// main.cpp
#include "linear_regression.h"

void graph(const std::vector<double>& mileage, const std::vector<double>& price, double theta0, double theta1) {
    std::ofstream data_file("data.txt");
    for (size_t i = 0; i < mileage.size(); ++i) {
        data_file << mileage[i] << " " << price[i] << std::endl;
    }
    data_file.close();

    std::ofstream model_file("model.txt");
    for (double x = 0; x <= 300000; x += 50) {
        model_file << x << " " << (theta0 + theta1 * x) << std::endl;
    }
    model_file.close();

    std::string gnuplot_commands = "plot 'data.txt' with points title 'Real Data', 'model.txt' with lines title 'Linear Model'";
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "%s\n", gnuplot_commands.c_str());
    fflush(gnuplotPipe);
}

void read_csv(const std::string& filename, std::vector<double>& mileage, std::vector<double>& price) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open the file: " << filename << std::endl;
        exit(1);
    }
    std::string header;
    std::getline(file, header);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        std::getline(iss, token, ',');
        size_t pos = token.find_first_not_of(" \t");
        try {
            double km = std::stod(token.substr(pos));
            mileage.push_back(km);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument when converting mileage: " << token << std::endl;
            exit(1);
        }
        std::getline(iss, token, ',');
        pos = token.find_first_not_of(" \t");
        try {
            double p = std::stod(token.substr(pos));
            price.push_back(p);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument when converting price: " << token << std::endl;
            exit(1);
        }
    }
    file.close();
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <csv_filename> <new_mileage>" << std::endl;
        return 1;
    }
    std::vector<double> mileage;
    std::vector<double> price;
    read_csv(argv[1], mileage, price);
    double theta0 = 0;
    double theta1 = 0;
    int iterations = 100000;
    gradient_descent(mileage, price, theta0, theta1, iterations);
    std::cout << "Trained Parameters: theta0 = " << theta0 << ", theta1 = " << theta1 << std::endl;
    double new_mileage = std::stod(argv[2]);
    double predicted_price = estimate_price(new_mileage, theta0, theta1);
    std::cout << "For a mileage of " << new_mileage << " km, the estimated price is: " << predicted_price << std::endl;
    graph(mileage, price, theta0, theta1);
    double mean_relative_error = calculate_mean_relative_error(mileage, price, theta0, theta1);
    std::cout << "Mean Relative Error on Training Data: " << mean_relative_error << std::endl;
    double mean_squared_error = calculate_mean_squared_error(mileage, price, theta0, theta1);
    std::cout << "Mean Squared Error on Training Data: " << mean_squared_error << std::endl;
    return (0);
}
