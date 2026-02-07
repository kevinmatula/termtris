#ifndef HAT_HPP
#define HAT_HPP

#include "tetromino.hpp"

class Hat : public Tetromino {
private:
  static constexpr std::string_view stringRep = " # \n###";
  bool falling;

public:
  Hat() : falling(true) {};

  std::string_view getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};

#endif
