#include "tetromino.hpp"
#include <string>

class Right_Snake : public Tetromino {
private:
  const std::string stringRep = " ##\n## ";
  const bool falling;

public:
  Right_Snake() : falling(true) {};

  std::string getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};
