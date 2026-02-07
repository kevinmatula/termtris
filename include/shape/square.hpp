#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "tetromino.hpp"

class Square : public Tetromino {
private:
  static constexpr std::string_view stringRep = "##\n##";
  bool falling;

public:
  Square() : falling(true) {};

  std::string_view getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};

#endif
