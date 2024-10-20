#include <fstream>
#include "matrices/matrix.h"
#include "game/cells_types.h"
#include "game/parser.h"
#include "game/game.h"

int main(int argc, char **argv) {
  std::string testFileIn;

  if(argc > 1) {
    testFileIn = argv[1];
  } else {
    testFileIn = "./rsc/test-input.txt";
  }

  FileParser parser;
  GameOfLife game;

  auto initialState = parser.ParseGameInput(testFileIn);

  auto currentState = initialState.second;
  std::cout << currentState.GetPrintableMatrix();
  for(int i = 0; i < initialState.first; ++i){
    game.WriteState(currentState);
    currentState = game.GetNextState(currentState);
    std::cout << currentState.GetPrintableMatrix();
  }

  std::string testFileOut;
  if(argc > 2) {
    testFileOut = argv[2];
  } else {
    testFileOut = "./rsc/test-output.txt";
  }

  parser.WriteGameOutput(game, testFileOut);
  return 0;
}