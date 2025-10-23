#include "../include/eleven.hpp"
#include <iostream>


#define min(a, b) (a < b) ? a : b
#define max(a, b) (a > b) ? a : b
#define SYSTEM 11


unsigned int toInt(const unsigned char digit) {
  if (digit == 'A') {
    return 10;
  }
  return digit - '0';
}


unsigned char toChar(const unsigned int digit) {
  if (digit == 10) {
    return 'A';
  }
  return digit + '0';
}


Eleven Eleven::sum(const Eleven &other) const {
  const bool thisIsMin = (*this).less(other);
  
  const Eleven &minEleven = (thisIsMin) ? *this : other;
  const Eleven &maxEleven = (!thisIsMin) ? *this : other;

  const unsigned char *minNumber = minEleven.getNumber();
  const unsigned char *maxNumber = maxEleven.getNumber();

  const size_t minSize = minEleven.getSize();
  const size_t maxSize = maxEleven.getSize();

  unsigned int minDigit;
  unsigned int maxDigit;
  unsigned int extra = 0;
  unsigned int digitSum = 0;

  size_t resultSize = maxSize + 1;
  unsigned char *resultNumber = new unsigned char[resultSize];
  
  for (size_t i = 0; i != maxSize; ++i) {
    minDigit = (i < minSize) ? toInt(minNumber[i]) : 0;
    maxDigit = toInt(maxNumber[i]);

    digitSum = minDigit + maxDigit + extra;
    extra = digitSum / SYSTEM;
    resultNumber[i] = toChar(digitSum % SYSTEM);
  }

  if (extra == 0) {
    resultSize -= 1;
  } else {
    resultNumber[resultSize - 1] = '1';
  }

  Eleven result(resultSize, resultNumber);
  return result;
}


Eleven Eleven::difference(const Eleven &other) const {
  if ((*this).less(other)) {
    throw IncorrectLValueException();
  }

  const Eleven &minEleven = other;
  const Eleven &maxEleven = *this;

  const unsigned char *minNumber = minEleven.getNumber();
  const unsigned char *maxNumber = maxEleven.getNumber();

  const size_t minSize = minEleven.getSize();
  const size_t maxSize = maxEleven.getSize();

  unsigned int minDigit;
  unsigned int maxDigit;
  unsigned int extra = 0;
  unsigned int digitDifference = 0;

  const size_t resultSize = maxSize;
  unsigned char *resultNumber = new unsigned char[resultSize];
  
  for (size_t i = 0; i != maxSize; ++i) {
    minDigit = (i < minSize) ? toInt(minNumber[i]) : 0;
    maxDigit = toInt(maxNumber[i]) - extra;

    if (maxDigit < minDigit) {
      maxDigit += SYSTEM;
      extra = 1;
    } else {
      extra = 0;
    }
    
    digitDifference = maxDigit - minDigit;
    resultNumber[i] = toChar(digitDifference % SYSTEM);
  }

  Eleven result(resultSize, resultNumber);
  return result;
}
