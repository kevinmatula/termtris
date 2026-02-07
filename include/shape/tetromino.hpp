#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <string_view>
// This class is the standard interface for a Tetris tetromino (block in game)
class Tetromino {
public:
  virtual std::string_view getShape() const = 0;
  virtual bool isFalling() const = 0;

  virtual ~Tetromino() = default;
};

#endif
