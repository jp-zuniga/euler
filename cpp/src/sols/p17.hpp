// https://projecteuler.net/problem=17
// --------------------------------------------------------------------------------------
// If all the numbers from to 1 to 1,000 (inclusive)
// were written out in words, how many letters would be used?

// optimize < 1ms
// expand range of supported inputs

#include <chrono>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>

#include "include/stopwatch.hpp"

using namespace std::chrono;

inline std::string to_word(const uint32_t &num) {
  // store easy cases in a dictionary
  static const std::map<uint32_t, std::string> num_words{
      {1, "one"},        {2, "two"},       {3, "three"},     {4, "four"},
      {5, "five"},       {6, "six"},       {7, "seven"},     {8, "eight"},
      {9, "nine"},       {10, "ten"},      {11, "eleven"},   {12, "twelve"},
      {13, "thirteen"},  {14, "fourteen"}, {15, "fifteen"},  {16, "sixteen"},
      {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
  };

  // if the number's an easy case, use the dictionary
  if (num >= 1 && num <= 19) {
    return num_words.at(num);
  }

  if (num >= 20 && num <= 99) {
    // extract individual digits to deduce words
    // ex: num = 73
    //  -> num % 10 = 3
    //  -> num / 10 = 7
    // from there, use num_words to get "three"
    // and the switch statement to combine it with "seventy"

    uint32_t ones = num % 10;
    uint32_t tens = num / 10;

    // if the ones place is a 0, leave it blank;
    // else add a hyphen and that number's word
    std::string ones_word = (ones == 0) ? "" : "-" + num_words.at(ones);

    switch (tens) {
    case 2:
      return "twenty" + ones_word;
    case 3:
      return "thirty" + ones_word;
    case 4:
      return "forty" + ones_word;
    case 5:
      return "fifty" + ones_word;
    case 6:
      return "sixty" + ones_word;
    case 7:
      return "seventy" + ones_word;
    case 8:
      return "eighty" + ones_word;
    case 9:
      return "ninety" + ones_word;
    default:
      break;
    }
  }

  if (num >= 100 && num <= 999) {
    uint32_t tens = num % 100;
    uint32_t hundreds = uint32_t(num / 100);

    // recursion to deal with the possibility of a 2-digit tens
    std::string tens_word = (tens == 0) ? "" : " and " + to_word(tens);

    return num_words.at(hundreds) + " hundred" + tens_word;
  }

  if (num == 1000) {
    return "one thousand";
  }

  // no solution today, sorry
  return "";
}

inline uint32_t count_letters(const std::string &num_word) {
  uint32_t count = 0;

  for (const char &letter : num_word) {
    // ignore spaces/hyphens
    if (std::isalpha(letter)) {
      count++;
    }
  }

  return count;
}

inline void solve_p17() {
  auto start = steady_clock::now();

  constexpr uint32_t limit = 1e3;
  uint32_t letter_count = 0;

  for (uint32_t i = 1; i <= limit; i++) {
    letter_count += count_letters(to_word(i));
  }

  auto end = steady_clock::now();

  std::cout << "Number of letters used: " << letter_count << "\n";

  stopwatch(start, end);
}
