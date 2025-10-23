#include <gtest/gtest.h>
#include "../include/eleven.hpp"

// --- Конструкторы и базовые операции ---
TEST(ElevenConstructors, DefaultConstructor) {
  Eleven a;
  EXPECT_EQ(a.getSize(), 0);
  EXPECT_EQ(a.getNumber(), nullptr);
}

TEST(ElevenConstructors, FromString) {
  Eleven a("123A");
  EXPECT_EQ(a.getSize(), 4);
  EXPECT_EQ(a.getNumber()[3], '1');
  EXPECT_EQ(a.getNumber()[0], 'A');
}

TEST(ElevenConstructors, CopyConstructor) {
  Eleven a("10A");
  Eleven b(a);
  EXPECT_EQ(b.getSize(), a.getSize());
  for (size_t i = 0; i < a.getSize(); ++i) {
      EXPECT_EQ(a.getNumber()[i], b.getNumber()[i]);
  }
}

TEST(ElevenConstructors, MoveConstructor) {
  Eleven a("345");
  size_t sizeA = a.getSize();
  unsigned char* ptr = a.getNumber();

  Eleven b(std::move(a));
  EXPECT_EQ(b.getSize(), sizeA);
  EXPECT_EQ(b.getNumber(), ptr);
  EXPECT_EQ(a.getNumber(), nullptr);
}

// --- Арифметика ---
TEST(ElevenArithmetic, SumSimple) {
  Eleven a("872634");
  Eleven b("AAAA");
  Eleven c = a.sum(b);
  EXPECT_EQ(std::string((char*)c.getNumber(), c.getSize()), "336288");
}

TEST(ElevenArithmetic, DifferenceSimple) {
  Eleven a("872634");
  Eleven b("AAAA");
  Eleven c = a.difference(b);
  EXPECT_EQ(std::string((char*)c.getNumber(), c.getSize()), "536268");
}

TEST(ElevenArithmetic, DifferenceThrowsOnNegative) {
  Eleven a("1");
  Eleven b("2");
  EXPECT_THROW(a.difference(b), Eleven::IncorrectLValueException);
}

// --- Сравнения ---
TEST(ElevenCompare, EqualAndNotEqual) {
  Eleven a("10A");
  Eleven b("10A");
  Eleven c("9");
  EXPECT_TRUE(a.equal(b));
  EXPECT_FALSE(a.equal(c));
  EXPECT_TRUE(a.notEqual(c));
}

TEST(ElevenCompare, LessGreaterVariants) {
  Eleven a("1");
  Eleven b("A");
  EXPECT_TRUE(a.less(b));
  EXPECT_TRUE(b.greater(a));
  EXPECT_TRUE(a.lessEqual(b));
  EXPECT_TRUE(b.equalGreater(a));
}

// --- Копирование и вывод ---
TEST(ElevenUtilities, CopyCreatesNewObject) {
  Eleven a("123");
  Eleven b = a.copy();
  EXPECT_EQ(a.getSize(), b.getSize());
  EXPECT_NE(a.getNumber(), b.getNumber()); // должно быть разное место в памяти
}

TEST(ElevenUtilities, PrintDoesNotThrow) {
  Eleven a("1A");
  EXPECT_NO_THROW(a.print());
}
