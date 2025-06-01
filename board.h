// board.h
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class board {
  private:
    std::vector<std::vector<bool> > array;
  public:
    board(int size);
    void print_board();
};

board::board(int size) : array(50, std::vector<bool>(size, false))
{
}

void board::print_board()
{
  for(int i = 0; i < this->array.size(); i++) {
    for(int j = 0; j < this->array.size(); j++) {
      std::cout << this->array[i][j];
    }
    std::cout << std::endl;
  }
}

#endif