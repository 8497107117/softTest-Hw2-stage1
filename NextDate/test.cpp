#include <iostream>
#include "nextDate.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Path_Testing, isValid_year_month) {
    /* both year and month invalid */
    EXPECT_EQ("invalid input date", nextDate(15, 0, 1811));
    EXPECT_EQ("invalid input date", nextDate(15, 0, 2013));
    EXPECT_EQ("invalid input date", nextDate(15, 13, 1811));
    EXPECT_EQ("invalid input date", nextDate(15, 13, 2013));
    /* month invalid */
    EXPECT_EQ("invalid input date", nextDate(15, 0, 2000));
    EXPECT_EQ("invalid input date", nextDate(15, 13, 2000));
    /* year invalid */
    EXPECT_EQ("invalid input date", nextDate(15, 6, 1811));
    EXPECT_EQ("invalid input date", nextDate(15, 6, 2013));
    /* valid */
    EXPECT_EQ("16,6,2000", nextDate(15, 6, 2000));
}
