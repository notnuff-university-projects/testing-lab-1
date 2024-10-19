#include <fstream>
#include "matrices/matrix.h"
#include "game/cells_types.h"
#include "game/parser.h"
#include "game/game.h"

int main(int argc, char **argv) {
  // todo: normal parsing
  std::string testFile;

  if(argc > 1) {
    testFile = argv[1];
  } else {
    testFile = "./rsc/test-input.txt";
  }

  FileParser parser;
  GameOfLife game;

  auto initialState = parser.ParseGameInput(testFile);

  auto currentState = initialState.second;
  currentState.PrintMatrix();
  for(int i = 0; i < initialState.first; ++i){
    game.WriteState(currentState);
    currentState = game.GetNextState(currentState);
    currentState.PrintMatrix();

  }

  return 0;
}