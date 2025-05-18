//
// Created by elms on 5/16/25.
//

#include "Sequence.h"
#include <algorithm>

Sequence::Sequence(size_t history_size): history_size(history_size) {
  history = new int[history_size];
  history_len = 0;
}

Sequence::~Sequence() {
  if (nullptr != history) {
    delete[] history;
  }
}

int Sequence::Next() {
  if (history_len == history_size) {
    for(size_t i = 1; i < history_len; i++) {
      history[i-1] = history[i];
    }
  }

  size_t next = std::min(history_size - 1, history_len);
  history_len = std::min(history_size, history_len + 1);

  if (next >= 1) {
    history[next] = history[next - 1] + 1;
  } else {
    history[next] = 1;
  }

  return history[next];
}

int Sequence::GetPast(size_t n) {
  if (history_len < 1) {
    throw std::range_error("Sequence has no history");
  }
  if (n > history_len - 1) {
    throw std::range_error("input exceeds Sequence history");
  }
  return history[history_len - n];
}
