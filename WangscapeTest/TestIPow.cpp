#include <gtest/gtest.h>

#include <type_traits>

#include <utils.h>

template<typename I>
class TestIPow : public ::testing::Test
{
protected:
    const I zero = 0;
    const I one = 1;
    const I two = 2;
    const I three = 3;
    const I max = std::numeric_limits<I>::max();
    const I digits = static_cast<I>(std::numeric_limits<I>::digits);
};

typedef ::testing::Types<
    char, short, int, long, long long,
    unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long>
    IntTypes;
TYPED_TEST_CASE(TestIPow, IntTypes);

TYPED_TEST(TestIPow, TestIPow00)
{
    EXPECT_EQ(this->one, ipow(this->zero, this->zero));
}

TYPED_TEST(TestIPow, TestIPowX0)
{
    EXPECT_EQ(this->one, ipow(this->one, this->zero));
    EXPECT_EQ(this->one, ipow(this->two, this->zero));
    EXPECT_EQ(this->one, ipow(this->three, this->zero));
    EXPECT_EQ(this->one, ipow(this->digits, this->zero));
    EXPECT_EQ(this->one, ipow(this->max, this->zero));
}

TYPED_TEST(TestIPow, TestIPow0X)
{
    EXPECT_EQ(this->zero, ipow(this->zero, this->one));
    EXPECT_EQ(this->zero, ipow(this->zero, this->two));
    EXPECT_EQ(this->zero, ipow(this->zero, this->three));
    EXPECT_EQ(this->zero, ipow(this->zero, this->digits));
    EXPECT_EQ(this->zero, ipow(this->zero, this->max));
}

TYPED_TEST(TestIPow, TestIPowX1)
{
    EXPECT_EQ(this->one, ipow(this->one, this->one));
    EXPECT_EQ(this->two, ipow(this->two, this->one));
    EXPECT_EQ(this->three, ipow(this->three, this->one));
    EXPECT_EQ(this->max, ipow(max, this->one));
}

TYPED_TEST(TestIPow, TestIPow1X)
{
    EXPECT_EQ(this->one, ipow(this->one, this->one));
    EXPECT_EQ(this->one, ipow(this->one, this->two));
    EXPECT_EQ(this->one, ipow(this->one, this->digits));
    EXPECT_EQ(this->one, ipow(this->one, this->max));
}

TYPED_TEST(TestIPow, TestIPowExamples)
{
    EXPECT_EQ(4, ipow(this->two, this->two));
    EXPECT_EQ(9, ipow(this->three, this->two));
    EXPECT_EQ(this->one << (this->digits - 1),
              ipow(this->two,
                   TypeParam(this->digits - 1)));

    EXPECT_EQ(8, ipow(this->two, this->three));
    EXPECT_EQ(27, ipow(this->three, this->three));
}

TYPED_TEST(TestIPow, TestIPowTooLarge)
{
    EXPECT_ANY_THROW(ipow(this->two, this->digits));
    EXPECT_ANY_THROW(ipow(this->two, this->max));
    EXPECT_ANY_THROW(ipow(this->three, this->digits));
    EXPECT_ANY_THROW(ipow(this->three, this->max));
    EXPECT_ANY_THROW(ipow(this->max, this->digits));
    EXPECT_ANY_THROW(ipow(this->max, this->max));
}
