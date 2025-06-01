// board.h
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

class board {
  private:
    std::vector<std::vector<bool> > array;
  public:
    board(int size);
    void set_cell(int x, int y, bool value);
    void print_board();
};

board::board(int size) : array(50, std::vector<bool>(size, false))
{
}

void board::set_cell(int x, int y, bool value)
{
  if(x < this->array.size() && y < this->array.size())
    this->array[x][y] = value;
}

void board::print_board()
{
  std::cout << "\033[2J\033[1;1H";
  for(int i = 0; i < this->array.size(); i++) {
    for(int j = 0; j < this->array.size(); j++) {
      if(this->array[i][j]) {
        std::cout << "█ ";
      } else {
        std::cout << ". ";
      }
    }
    std::cout << std::endl;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

#endif