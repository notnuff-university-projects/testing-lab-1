#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect equality.
    EXPECT_EQ(7 * 1, 8);
}// Demonstrate some basic assertions.
TEST(HelloTest, StringsEq) {
    // Expect two strings not to be equal.
    EXPECT_EQ("hello", "hello");
}
