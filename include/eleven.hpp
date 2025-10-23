#ifndef ELEVEN_HPP
#define ELEVEN_HPP


#include <string>
#include <initializer_list>
#include <cstddef>
#include <array>


class Eleven {
  private:
    unsigned char *number = nullptr;
    size_t size = 0;

    template <typename T>
    void initByCollection(const size_t s, T &t);
    
    Eleven(const size_t n, unsigned char *t);

  public:
    class IncorrectLValueException {};

    Eleven();
    Eleven(const size_t &n, unsigned char t = 0);
    Eleven(const std::initializer_list<unsigned char> &t);
    Eleven(const std::string &t);
    Eleven(const Eleven &other);
    Eleven(Eleven &&other) noexcept;
    virtual ~Eleven() noexcept;

    unsigned char *getNumber() const;
    size_t getSize() const;
    void print() const;
    Eleven copy() const;

    Eleven sum(const Eleven &other) const;
    Eleven difference(const Eleven &other) const;

    bool less(const Eleven &other) const;
    bool lessEqual(const Eleven &other) const;
    bool equal(const Eleven &other) const;
    bool notEqual(const Eleven &other) const;
    bool greater(const Eleven &other) const;
    bool equalGreater(const Eleven &other) const;
};


#endif
