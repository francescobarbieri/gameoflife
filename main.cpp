#include "board.h"
#include <iostream>
using namespace std;

int main () {
  board current(50);
  current.print_board();
  current.set_cell(49, 49, true);
  current.print_board();
  current.set_cell(49, 49, false);
  current.print_board();
  current.set_cell(49, 49, true);
  current.print_board();
  current.set_cell(49, 49, false);
  current.print_board();
  current.set_cell(49, 49, true);
  current.print_board();
  current.set_cell(49, 49, false);
  current.print_board();

  return 0;
}