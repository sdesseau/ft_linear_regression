// main.cpp
#include "linear_regression.h"

void plot_data_and_model(const std::vector<double>& mileage, const std::vector<double>& price, double theta0, double theta1) {
    std::ofstream data_file("data.txt");
    for (size_t i = 0; i < mileage.size(); ++i) {
        data_file << mileage[i] << " " << price[i] << std::endl;
    }
    data_file.close();

    std::ofstream model_file("model.txt");
    for (double x = 0.0; x <= 5.0; x += 0.1) {
        model_file << x << " " << (theta0 + theta1 * x) << std::endl;
    }
    model_file.close();

    std::string gnuplot_commands = "plot 'data.txt' with points title 'Training Data', 'model.txt' with lines title 'Linear Model'";
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "%s\n", gnuplot_commands.c_str());
    fflush(gnuplotPipe);
}

double normalize_feature(double feature, double mean, double stddev) {
    return (feature - mean) / stddev;
}

void normalize_features(std::vector<double>& features) {
    double mean = 0.0, stddev = 0.0;

    // Calculer la moyenne
    for (double feature : features) {
        mean += feature;
    }
    mean /= features.size();

    // Calculer l'écart type
    for (double feature : features) {
        stddev += (feature - mean) * (feature - mean);
    }
    stddev = std::sqrt(stddev / features.size());

    // Normaliser les features
    for (double& feature : features) {
        feature = normalize_feature(feature, mean, stddev);
    }
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
    int iterations = 1000;
    normalize_features(mileage);
    gradient_descent(mileage, price, theta0, theta1, iterations);
    std::cout << "Trained Parameters: theta0 = " << theta0 << ", theta1 = " << theta1 << std::endl;
    double new_mileage = std::stod(argv[2]);
    double predicted_price = estimate_price(new_mileage, theta0, theta1);
    std::cout << "For a mileage of " << new_mileage << " km, the estimated price is: " << predicted_price << std::endl;
    plot_data_and_model(mileage, price, theta0, theta1);
    double mean_relative_error = calculate_mean_relative_error(mileage, price, theta0, theta1);
    std::cout << "Mean Relative Error on Training Data: " << mean_relative_error << std::endl;
    return (0);
}
