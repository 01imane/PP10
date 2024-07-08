#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include <vector>
#include <iostream>

std::pair<double, double> calculate_statistics(const std::vector<double>& data);

void read_values_from_stream(std::istream& input_stream, std::vector<double>& values);

#endif // STATISTICS_HPP

