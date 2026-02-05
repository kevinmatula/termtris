#include "tetromino.hpp"
#include <string>

class Left_Leg : public Tetromino {
private:
  const std::string stringRep = "  #\n  #\n ##";
  const bool falling;

public:
  Left_Leg() : falling(true) {};

  std::string getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};
