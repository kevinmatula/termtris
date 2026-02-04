#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <vector>

using namespace std;

// Setting arbitrary scene width and height
const int SCENE_WIDTH = 80;
const int SCENE_HEIGHT = 30;

// cool-ass cleanup function that stops CPU mid instruction to run this command.
void cleanup(int) {
  cout << "\x1b[?1049l\x1b[?25h" << flush;
  cout << "Termtris Was Closed." << endl;
  _exit(0);
}

// places markers at top and bottom of screen to visually display bounds
void setBounds(vector<vector<char>> &buf) {
  for (int x = 0; x < SCENE_WIDTH; x++) {
    buf[0][x] = '-';
    buf[SCENE_HEIGHT - 1][x] = '-';
  }
}

int main() {

  signal(SIGINT, cleanup);
  signal(SIGTERM, cleanup);

  // Clear the screen and set cursor to home
  cout << "\x1b[?1049h\x1b[?25l" << flush;

  vector<vector<char>> buffer(SCENE_HEIGHT, vector<char>(SCENE_WIDTH, ' '));
  setBounds(buffer);

  // create visual upper and lower bounds
  while (1) {

    cout << "\x1b[2J\x1b[H";
    for (int y = 0; y < SCENE_HEIGHT; y++) {
      for (int x = 0; x < SCENE_WIDTH; x++) {
        cout << buffer[y][x];
      }
      cout << "\n";
    }
    cout << flush;
    usleep(9000);
  }
}

// TODO: consider different sized terminals, like "termtris --small" and
// "termtris --large"
// TODO: Consider writing an entire string instead of line by line via for loop
