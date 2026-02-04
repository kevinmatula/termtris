#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

int main() {

  // Setting arbitrary scene width and height
  const int SCENE_WIDTH = 60;
  const int SCENE_HEIGHT = 20;

  // Clear the screen and set cursor to home
  cout << "\x1b[?1049h\x1b[?25l" << flush;

  vector<vector<char>> buffer(SCENE_HEIGHT, vector<char>(SCENE_WIDTH, ' '));
  while (1) {

    cout << "\x1b[2J\x1b[H";
    for (int y = 0; y < SCENE_HEIGHT; y++) {
      for (int x = 0; x < SCENE_WIDTH; x++) {
        cout << buffer[y][x];
      }
      cout << "\n";
    }
    cout << flush;
    cout << "---------------------------" << endl;
    usleep(9000);
  }
  // Reset terminal
  cout << "\x1b[?1049l\x1b[?25h" << flush;

  return 0;
}
