// gaussian_distribution.hpp
#ifndef GAUSSIAN_DISTRIBUTION_HPP
#define GAUSSIAN_DISTRIBUTION_HPP

#include <random>
#include <stdexcept>
#include <cstdio>

void print_gaussian_dist(int expected_value, int std_deviation, int amount_of_values, FILE* output_stream) {
    if (amount_of_values < 100) {
        throw std::invalid_argument("Amount of values must be at least 100.");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist(expected_value, std_deviation);

    for (int i = 0; i < amount_of_values; ++i) {
        fprintf(output_stream, "%f\n", dist(gen));
    }
}

#endif // GAUSSIAN_DISTRIBUTION_HPP

