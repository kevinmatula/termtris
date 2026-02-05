#include "tetromino.hpp"
#include <string>

class Right_Leg : public Tetromino {
private:
  const std::string stringRep = "#  \n#  \n## ";
  const bool falling;

public:
  Right_Leg() : falling(true) {};

  std::string getShape() const override { return stringRep; }
  bool isFalling() const override { return falling; }
};
