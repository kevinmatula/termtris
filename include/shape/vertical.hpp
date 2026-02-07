#ifndef VERTICAL_HPP
#define VERTICAL_HPP

#include "tetromino.hpp"

class Vertical : public Tetromino {
private:
  static constexpr std::string_view stringRep = "#\n#\n#\n#";
  bool falling;

public:
  Vertical() : falling(true) {};

  std::string_view getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};

#endif
