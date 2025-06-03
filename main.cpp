#include "board.h"
#include <iostream>
using namespace std;

const int BOARD_SIZE = 10;

int main () {
  board first_board(BOARD_SIZE);
  board second_board(BOARD_SIZE);

  first_board.set_cell(0, 0, true);
  first_board.set_cell(0, 1, true);
  first_board.set_cell(1, 1, true);

  first_board.print_board();

  int alive = first_board.count_alive_neighbours(0, 1);

  std::cout << "\n" << alive << "\n";

  // std::this_thread::sleep_for(std::chrono::milliseconds(100));

  return 0;
}