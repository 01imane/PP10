//Aufgabe1.c
#include "gaussian_distribution.hpp"
#include <iostream>
#include <unistd.h>
#include <cstdlib>

void print_usage() {
    std::cout << "Usage: gaussian_dist -e expected_value -s std_deviation -a amount_of_values -o output_file\n";
}

int main(int argc, char* argv[]) {
    int expected_value = 0;
    int std_deviation = 1;
    int amount_of_values = 100;
    const char* output_file = nullptr;

    int opt;
    while ((opt = getopt(argc, argv, "he:s:a:o:")) != -1) {
        switch (opt) {
        case 'h':
            print_usage();
            return 0;
        case 'e':
            expected_value = std::atoi(optarg);
            break;
        case 's':
            std_deviation = std::atoi(optarg);
            break;
        case 'a':
            amount_of_values = std::atoi(optarg);
            break;
        case 'o':
            output_file = optarg;
            break;
        default:
            print_usage();
            return 1;
        }
    }

    if (output_file == nullptr) {
        std::cerr << "Output file must be specified.\n";
        print_usage();
        return 1;
    }

    FILE* file = std::fopen(output_file, "w");
    if (!file) {
        std::cerr << "Could not open file for writing: " << output_file << "\n";
        return 1;
    }

    try {
        print_gaussian_dist(expected_value, std_deviation, amount_of_values, file);
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        std::fclose(file);
        return 1;
    }

    std::fclose(file);
    return 0;
}

