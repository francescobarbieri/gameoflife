#include <vector>
#include <iostream>
#include <cstdint>
#include <bitset>

// Una cella in ogni bit
// 

class Nibble {
  private:
    unsigned int data : 4;
  public:
    Nibble() {}
    unsigned int getData() {
      return this->data;
    }
    void setData(unsigned int data) {
      this->data = data;
    }
};

int main () {
  std::vector<uint64_t> columns;
  Nibble t = Nibble();
  t.setData(15);

  std::bitset<4> x(t.getData());
  std::cout << x << "\n";

  return 0;
}