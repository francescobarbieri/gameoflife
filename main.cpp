#include "board.h"
#include <iostream>
using namespace std;

const int BOARD_SIZE = 20;
const int STEPS = 10000;

int main () {
  board first_board(BOARD_SIZE);
  board second_board(BOARD_SIZE);

  first_board.set_cell(10, 10, true);
  first_board.set_cell(9, 10, true);
  first_board.set_cell(10, 9, true);
  first_board.set_cell(11, 10, true);
  first_board.set_cell(11, 11, true);

  // first_board.print_board();

  int alive_neighbours = first_board.count_alive_neighbours(9, 0);

  for (int z = 0; z < STEPS; ++z) {
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
      for(int j = 0; j < BOARD_SIZE; ++j)
      {
        int alive_neighbours = first_board.count_alive_neighbours(i, j);
        if(alive_neighbours < 2)
        {
          second_board.set_cell(i, j, false);
        }
        else if (alive_neighbours > 3)
        {
          second_board.set_cell(i, j, false);
        }
        else
        {
          second_board.set_cell(i, j, true);
        }
      }
    }
    std::swap(first_board, second_board);
  }

  second_board.print_board();

  // std::this_thread::sleep_for(std::chrono::milliseconds(100));

  return 0;
}