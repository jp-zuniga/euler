#include <chrono>
#include <iostream>

using namespace std::chrono;

inline void print_time(const steady_clock::time_point &start,
                       const steady_clock::time_point &end) {
  std::cout << "Execution time: "
            << duration<double, std::milli>(end - start).count() << "ms\n";
}
