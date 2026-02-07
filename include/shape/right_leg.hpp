#ifndef RIGHT_LEG_HPP
#define RIGHT_LEG_HPP

#include "tetromino.hpp"

class Right_Leg : public Tetromino {
private:
  static constexpr std::string_view stringRep = "#  \n#  \n## ";
  bool falling;

public:
  Right_Leg() : falling(true) {};

  std::string_view getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};

#endif
