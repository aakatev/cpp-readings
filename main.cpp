#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void error(std::string e);

struct Reading {
  int hour;
  double temperature;
  std::string period;
};

int main() {
  constexpr char file_name[] = "temperature.txt";

  std::ifstream file(file_name, std::ios::in);
  if (!file) error("Error openning file " + std::string(file_name) + "\n");
  
  std::vector<Reading> readings;
  int hour;
  double temperature;
  std::string period;

  while (file >> hour >> temperature >> period) {
    readings.push_back(Reading{hour,temperature, period});
  }

  for(const auto& r : readings) {
    std::cout << "At " << r.hour << r.period << " temperature was " << r.temperature <<"\n";
  }

  return 0;
}

void error(std::string e) {
 throw std::runtime_error(e);
}
