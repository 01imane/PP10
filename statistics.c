#include "statistics.h"
#include <cmath>
#include <numeric>
#include <stdexcept>

std::pair<double, double> calculate_statistics(const std::vector<double>& data) {
    if (data.size() < 100) {
        throw std::invalid_argument("Data must contain at least 100 values.");
    }

    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / data.size();

    double sq_sum = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
    double std_dev = std::sqrt(sq_sum / data.size() - mean * mean);

    return {mean, std_dev};
}

void read_values_from_stream(std::istream& input_stream, std::vector<double>& values) {
    double value;
    while (values.size() < 100 && input_stream >> value) {
        values.push_back(value);
    }
}

