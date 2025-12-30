// https://projecteuler.net/problem=67
// -------------------------------------------------------------------------------------
// Given a "triangle" of numbers:
// |   3   | A sum can be found by starting at the top of the triangle
// |  7 4  | and moving to adjacent numbers on the row below. The maximum
// | 2 4 6 | total of the example triangle is: 3 + 7 + 4 = 14.
// -------------------------------------------------------------------------------------
// Find the maximum total sum from top to bottom for the given triangle.

#include <chrono>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "include/stopwatch.hpp"

using namespace std::chrono;

namespace fs = std::filesystem;

inline std::vector<std::vector<uint64_t>>
read_triangle(fs::path triangle_path) {
  std::ifstream handler(triangle_path);

  std::vector<std::vector<uint64_t>> triangle;
  std::vector<uint64_t> row;

  std::string line;
  uint64_t num;

  while (std::getline(handler, line)) {
    std::stringstream ss(line);

    while (ss >> num) {
      row.emplace_back(num);
    }

    triangle.emplace_back(row);
    row.clear();
  }

  handler.close();
  return triangle;
}

inline void solve_p67() {
  auto start = steady_clock::now();

  const fs::path file_path =
      fs::current_path().parent_path() / "inputs" / "67-triangle.txt";

  std::vector<std::vector<uint64_t>> triangle = read_triangle(file_path);

  for (size_t i = triangle.size() - 1; i > 0; i--) {
    for (size_t j = 0; j < triangle[i].size() - 1; j++) {
      triangle[i - 1][j] += std::max(triangle[i][j], triangle[i][j + 1]);
    }
  }

  auto end = steady_clock::now();

  std::cout << "Maximum sum in triangle: " << triangle[0][0] << "\n";

  stopwatch(start, end);
}
