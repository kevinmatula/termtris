#ifndef RIGHT_SNAKE_HPP
#define RIGHT_SNAKE_HPP

#include "tetromino.hpp"

class Right_Snake : public Tetromino {
private:
  static constexpr std::string_view stringRep = " ##\n## ";
  bool falling;

public:
  Right_Snake() : falling(true) {};

  std::string_view getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};

#endif
