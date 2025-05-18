/*
 *
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <cstdlib>
#include <iostream>

/*
 * Generate a sequence of numbers with some history.
 *
 */
class Sequence {
public:
  Sequence(size_t history_size = DEFAULT_HISTORY_SIZE);
  ~Sequence();

  /*
   * Calculate and return next number in the sequence
   */
  int Next();

  /*
   * Retrieve the sequence value n values in the past from the current
   *
   * For n=0, the return value should be the same as last returned by Next()
   * n = 1 would be the value returned by the 2 calls ago to Next()
   *
   * If a value outside of the allowed history, then a std::range_error exception is thrown
   */
    int GetPast(size_t n);


//private:
  static const size_t DEFAULT_HISTORY_SIZE = 20;
  int* history;
  size_t history_len;
  size_t history_size;
};



#endif //SEQUENCE_H
