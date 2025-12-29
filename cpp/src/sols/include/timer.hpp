#include <chrono>
#include <iostream>

inline void print_time(const std::chrono::steady_clock::time_point &start,
                       const std::chrono::steady_clock::time_point &end) {
  std::cout << "Execution time: "
            << std::chrono::duration<double, std::milli>(end - start).count()
            << "ms\n";
}
