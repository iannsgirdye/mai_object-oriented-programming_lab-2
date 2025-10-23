#include "../include/eleven.hpp"
#include <iostream>


unsigned char *Eleven::getNumber() const {
  return number;
}


size_t Eleven::getSize() const {
  return size;
}


void Eleven::print() const {
  for (size_t i = size - 1; ; --i) {
    std::cout << number[i];
    if (i == 0) {
      std::cout << std::endl;
      break;
    }
  }
}


Eleven Eleven::copy() const {
  unsigned char *n = new unsigned char[size];
  for (size_t i = 0; i != size; ++i) {
    n[i] = number[i];
  }
  Eleven tmp(size, n);
  return tmp;
}
