#include "tetromino.hpp"
#include <string>

class Vertical : public Tetromino {
private:
  const std::string stringRep = "#\n#\n#\n#";
  const bool falling;

public:
  Vertical() : falling(true) {};

  std::string getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};
