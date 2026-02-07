#ifndef LEFT_SNAKE_HPP
#define LEFT_SNAKE_HPP

#include "tetromino.hpp"

class Left_Snake : public Tetromino {
private:
  static constexpr std::string_view stringRep = "## \n ##";
  bool falling;

public:
  Left_Snake() : falling(true) {};

  std::string_view getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};

#endif
