#include "board.h"
#include <iostream>
using namespace std;

const int BOARD_SIZE = 50;
const int STEPS = 500;

int main () {
  board first_board(BOARD_SIZE);
  board second_board(BOARD_SIZE);

  first_board.set_cell(8, 8, true);
  first_board.set_cell(7, 8, true);
  first_board.set_cell(8, 7, true);
  first_board.set_cell(9, 8, true);
  first_board.set_cell(9, 9, true);

  first_board.print_board();

  // int alive_neighbours = first_board.count_alive_neighbours(9, 0);

  for (int z = 0; z < STEPS; ++z) {
    for(int i = 0; i < BOARD_SIZE; ++i)
    {
      for(int j = 0; j < BOARD_SIZE; ++j)
      {
        int alive_neighbours = first_board.count_alive_neighbours(i, j);
        bool current_cell = first_board.get_cell(i, j);
        
        if(current_cell && alive_neighbours == 2 || alive_neighbours == 3)
        {
          second_board.set_cell(i, j, true);
        }
        else if(!current_cell && alive_neighbours == 3)
        {
          second_board.set_cell(i, j, true);
        }
        else
        {
          second_board.set_cell(i, j, false);
        }
      }
    }

    second_board.print_board();

    std::swap(first_board, second_board);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}