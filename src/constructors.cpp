#include "../include/eleven.hpp"
#include <initializer_list>
#include <string>
#include <cstddef>


template <typename T>
void Eleven::initByCollection(const size_t s, T &t) {
  size = s;
  number = new unsigned char[size];
  size_t i = size - 1;
  for (const auto &digit : t) {
    number[i] = digit;
    --i;
  }
}


Eleven::Eleven() {}


Eleven::Eleven(const size_t n, unsigned char *t) {
  number = t;
  size = n;
}


Eleven::Eleven(const size_t &n, unsigned char t) {
  size = n;
  number = new unsigned char[size];
  for (size_t i = 0; i != size; ++i) {
    number[i] = t;
  }
}


Eleven::Eleven(const std::initializer_list<unsigned char> &t) {
  initByCollection(t.size(), t);
}


Eleven::Eleven(const std::string &t) {
  initByCollection(t.size(), t);
}


Eleven::Eleven(const Eleven &other) {
  size = other.size;
  number = new unsigned char[size];
  for (size_t i = 0; i != size; ++i) {
    number[i] = other.number[i];
  }
}


Eleven::Eleven(Eleven &&other) noexcept {
  size = other.size;
  number = other.number;
  other.number = nullptr;
  other.size = 0;
}


Eleven::~Eleven() noexcept {
  if (number == nullptr) {
    delete[] number;
    number = nullptr;
  }
}
