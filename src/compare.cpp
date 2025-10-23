#include "../include/eleven.hpp"


enum class compareStatus {
  LESS = -1,
  EQUAL = 0,
  GREATER = 1
};


compareStatus compare(const Eleven &first, const Eleven &second) {
  const size_t firstSize = first.getSize();
  const size_t secondSize = second.getSize();

  if (firstSize < secondSize) {
    return compareStatus::LESS;
  }
  if (firstSize > secondSize) {
    return compareStatus::GREATER;
  }

  const unsigned char *firstNumber = first.getNumber();
  const unsigned char *secondNumber = second.getNumber();

  for (int i = static_cast<int>(firstSize); i != -1; --i) {
    if (firstNumber[i] < secondNumber[i]) {
      return compareStatus::LESS;
    }
    if (firstNumber[i] > secondNumber[i]) {
      return compareStatus::GREATER;
    }
  }
  return compareStatus::EQUAL;
}


bool Eleven::less(const Eleven &other) const {
  return compare(*this, other) == compareStatus::LESS;
}


bool Eleven::lessEqual(const Eleven &other) const {
  return compare(*this, other) != compareStatus::GREATER;
}


bool Eleven::equal(const Eleven &other) const {
  return compare(*this, other) == compareStatus::EQUAL;
}


bool Eleven::notEqual(const Eleven &other) const {
  return compare(*this, other) != compareStatus::EQUAL;
}


bool Eleven::greater(const Eleven &other) const {
  return compare(*this, other) == compareStatus::GREATER;
}


bool Eleven::equalGreater(const Eleven &other) const {
  return compare(*this, other) != compareStatus::LESS;
}
