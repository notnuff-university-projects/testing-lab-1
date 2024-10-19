#include "parser.h"
#include "helper_functions_test.h"
#include <gtest/gtest.h>


TEST(ParserTest, ParseTestFile) {
  std::string testFile = "./rsc/test-input.txt";
  CyclicMatrix<NCellType> expected;
  expected = std::vector<std::vector<NCellType>>{
      {NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
      {NCellType::Dead, NCellType::Dead, NCellType::Alive, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
      {NCellType::Dead, NCellType::Dead, NCellType::Alive, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
      {NCellType::Dead, NCellType::Dead, NCellType::Alive, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
      {NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead, NCellType::Dead},
  };

  FileParser parser;
  auto parsedResult = parser.ParseGameInput(testFile);
  EXPECT_EQ(parsedResult.first, 3);
  CompareMatrices(parsedResult.second, expected);
}