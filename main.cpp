#include <iostream>
#include <signal.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

using namespace std;

// cool-ass cleanup function that stops CPU mid instruction to run this command.
void cleanup(int) {
  cout << "\x1b[?1049l\x1b[?25h" << flush;
  cout << "Termtris Was Closed." << endl;
  _exit(0);
}

// places markers at top and bottom of screen to visually display bounds
void setBounds(vector<vector<char>> &buf, int GAME_WIDTH, int GAME_HEIGHT) {
  for (int x = 0; x < GAME_WIDTH; x++) {
    buf[0][x] = '_';
    buf[GAME_HEIGHT - 1][x] = 'T';
  }
  for (int y = 1; y < GAME_HEIGHT - 1; y++) {
    buf[y][0] = '|';
    buf[y][GAME_WIDTH - 1] = '|';
  }
}

// This function takes the entire buffer and turns it into a string
// This functions reduces flicker by rendering entire string at once and then
// outputting that!
string renderScreen(vector<vector<char>> buf, int SCENE_WIDTH,
                    int SCENE_HEIGHT) {
  string screen = "";
  for (int y = 0; y < SCENE_HEIGHT; y++) {
    for (int x = 0; x < SCENE_WIDTH; x++) {
      screen += buf[y][x];
    }
    if (y < SCENE_HEIGHT - 1) {
      screen += "\n";
    }
  }
  return screen;
}

int main() {

  winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  // Setting scene width and height depending on size of terminal
  const int SCENE_WIDTH = w.ws_col;
  const int SCENE_HEIGHT = w.ws_row;

  // Checking for minimum valid terminal size
  if (w.ws_col < 12 || w.ws_row < 22) {
    throw std::range_error("received negative value");
  }

  const int GAME_HEIGHT = 22;
  const int GAME_WIDTH = 12;

  signal(SIGINT, cleanup);
  signal(SIGTERM, cleanup);

  // Clear the screen and set cursor to home
  cout << "\x1b[?1049h\x1b[?25l" << flush;

  vector<vector<char>> buffer(SCENE_HEIGHT, vector<char>(SCENE_WIDTH, ' '));
  setBounds(buffer, GAME_WIDTH, GAME_HEIGHT);

  // create visual upper and lower bounds
  while (1) {

    // Set cursor to home
    cout << "\x1b[H";

    cout << renderScreen(buffer, SCENE_WIDTH, SCENE_HEIGHT);

    cout << flush;

    usleep(10000);
  }
}
