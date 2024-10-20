#include "parser.h"
#include "helper_functions_test.h"
#include <gtest/gtest.h>
#include <fstream>

class ParserTest : public testing::Test {
 protected:
  void SetUp() override {
    inputMatrixExpected = std::vector<std::vector<NCellType>>{
        {NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
        {NCellType::Dead, NCellType::Dead, NCellType::Alive, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
        {NCellType::Dead, NCellType::Dead, NCellType::Alive, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
        {NCellType::Dead, NCellType::Dead, NCellType::Alive, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
        {NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
    };
    auto nextState = gameTest.GetNextState(inputMatrixExpected);
    gameTest.WriteState(nextState);

    expectedFileOutput << "Number of generations ran: " << 1;
    expectedFileOutput << "Rows: " << 5 << " Columns: " << 8;
    expectedFileOutput << "\n";
    expectedFileOutput << nextState.GetPrintableMatrix();
  };

  CyclicMatrix<NCellType> inputMatrixExpected;
  GameOfLife gameTest;
  std::string testFileInputPath = "./rsc/test-input.txt";
  std::string testFileOutputPath = "./rsc/test-output.txt";
  std::stringstream expectedFileOutput;

};

TEST_F(ParserTest, ParseTestFile) {
  FileParser parser;
  auto parsedResult = parser.ParseGameInput(testFileInputPath);
  EXPECT_EQ(parsedResult.first, 3);
  CompareMatrices(parsedResult.second, inputMatrixExpected);
}

TEST_F(ParserTest, WriteTestFile) {
  FileParser parser;
  auto isSuccess = parser.WriteGameOutput(gameTest, testFileOutputPath);
  ASSERT_EQ(isSuccess, true);

  std::ifstream file;
  file.open(testFileOutputPath);

  std::stringstream fileContentStream;
  fileContentStream << file.rdbuf();

  EXPECT_EQ(fileContentStream.str(), expectedFileOutput.str());
}

