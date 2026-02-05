#include "tetromino.hpp"
#include <string>

class Hat : public Tetromino {
private:
  const std::string stringRep = " # \n###";
  const bool falling;

public:
  Hat() : falling(true) {};

  std::string getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};
