#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Reading {
  int hour;
  double temperature;
  std::string period;
};

int main() {
  constexpr char file_name[] = "temperature.txt";

  std::vector<Reading> readings;
  int hour;
  double temperature;
  std::string period;

  std::ifstream file(file_name, std::ios::in);

  while (file >> hour >> temperature >> period) {
    readings.push_back(Reading{hour,temperature, period});
  }

  for(const auto& r : readings) {
    std::cout << "At " << r.hour << r.period << " temperature was " << r.temperature <<"\n";
  }

  return 0;
}

