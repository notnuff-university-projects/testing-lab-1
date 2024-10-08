#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    ASSERT_EQ(7 * 1, 42);
    EXPECT_EQ(7 * 1, 42);
}// Demonstrate some basic assertions.
TEST(HelloTest, Mock) {
    // Expect two strings not to be equal.
    EXPECT_EQ("hello", "world");
}
