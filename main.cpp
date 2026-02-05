#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <vector>

using namespace std;

// Setting arbitrary scene width and height
const int SCENE_WIDTH = 80;
const int SCENE_HEIGHT = 30;

const int GAME_WIDTH = 60;
const int GAME_HEIGHT = SCENE_HEIGHT;

// cool-ass cleanup function that stops CPU mid instruction to run this command.
void cleanup(int) {
  cout << "\x1b[?1049l\x1b[?25h" << flush;
  cout << "Termtris Was Closed." << endl;
  _exit(0);
}

// places markers at top and bottom of screen to visually display bounds
void setBounds(vector<vector<char>> &buf) {
  for (int x = 0; x < GAME_WIDTH; x++) {
    buf[0][x] = '-';
    buf[SCENE_HEIGHT - 1][x] = '-';
  }
}

// This function takes the entire buffer and turns it into a string
// This functions reduces flicker by rendering entire string at once and then
// outputting that!
string renderScreen(vector<vector<char>> buf) {
  string screen = "";
  for (int y = 0; y < SCENE_HEIGHT; y++) {
    for (int x = 0; x < SCENE_WIDTH; x++) {
      screen += buf[y][x];
    }
    screen += "\n";
  }
  return screen;
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

    // Set cursor to home
    cout << "\x1b[H";

    cout << renderScreen(buffer);

    cout << flush;

    usleep(10000);
  }
}
