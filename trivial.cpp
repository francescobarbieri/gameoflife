#include <iostream>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

const int BOARD_SIZE = 10;
const int STEPS = 500;

class board {
  private:
    std::vector<std::vector<bool> > array;
  public:
    board(int size);
    void set_cell(int x, int y, bool value);
    int get_cell(int x, int y);
    int count_alive_neighbours(int x, int y);
    void print_board();
};

board::board(int size) : array(size, std::vector<bool>(size, false))
{
}

void board::set_cell(int x, int y, bool value)
{
  if(x < this->array.size() && y < this->array[0].size())
    this->array[x][y] = value;
}

int board::get_cell(int x, int y) {
  return this->array[x][y];
}

int board::count_alive_neighbours(int i, int j) {
  int row_limit = this->array.size() - 1;
  int col_limit = this->array[0].size() - 1;
  int counter = 0;

  for(int x = std::max(0, i-1); x <= std::min(i+1, row_limit); ++x)
  {
    for(int y = std::max(0, j-1); y <= std::min(j+1, col_limit); ++y)
    {
      if(x != i || y != j) // Excluding the center cell
      {
        if(this->array[x][y] == true) 
        {
          ++counter;
        }
      }
    }
  }

  return counter;
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
    std::cout << std::flush << std::endl;
  }
}

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