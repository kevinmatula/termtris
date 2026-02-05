#include "tetromino.hpp"
#include <string>

class Left_Snake : public Tetromino {
private:
  const std::string stringRep = "## \n ##";
  const bool falling;

public:
  Left_Snake() : falling(true) {};

  std::string getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};
