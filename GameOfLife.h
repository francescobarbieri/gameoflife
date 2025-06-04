#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

enum class ProgramMode {
  DEBUG,
  DEFAULT
};

enum class BoardMode {
  DEFAULT,
  TOROIDAL
};

class GameOfLife {
  private:
    ProgramMode mode_ = ProgramMode::DEFAULT; // Default mode
    BoardMode board_mode_ = BoardMode::DEFAULT; // Default board
  public:
    GameOfLife();

    inline void setMode(ProgramMode mode) { mode_ = mode; }
    inline ProgramMode getMode() const { return mode_; }
    inline void setBoardOption(BoardMode mode) { board_mode_ = mode; }
    inline BoardMode getBoardOption() const { return board_mode_; }

};

#endif