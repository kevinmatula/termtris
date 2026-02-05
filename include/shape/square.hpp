#include "tetromino.hpp"
#include <string>

class Square : public Tetromino {
private:
  const std::string stringRep = "##\n##";
  const bool falling;

public:
  Square() : falling(true) {};

  std::string getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};
