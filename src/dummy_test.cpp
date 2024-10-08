#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(DummyTest, First) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    ASSERT_EQ(7 * 6, 42);
}// Demonstrate some basic assertions.

TEST(DummyTest, Second) {
    // Expect two strings not to be equal.
    EXPECT_EQ("world", "world");
}
