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

TEST(Path_Testing, 31days_month) {
    /* isValid day */
    EXPECT_EQ("invalid input date", nextDate(0, 1, 2000));
    EXPECT_EQ("invalid input date", nextDate(32, 1, 2000));
    EXPECT_EQ("invalid input date", nextDate(0, 3, 2000));
    EXPECT_EQ("invalid input date", nextDate(32, 3, 2000));
    EXPECT_EQ("invalid input date", nextDate(0, 5, 2000));
    EXPECT_EQ("invalid input date", nextDate(32, 5, 2000));
    EXPECT_EQ("invalid input date", nextDate(0, 7, 2000));
    EXPECT_EQ("invalid input date", nextDate(32, 7, 2000));
    EXPECT_EQ("invalid input date", nextDate(0, 8, 2000));
    EXPECT_EQ("invalid input date", nextDate(32, 8, 2000));
    EXPECT_EQ("invalid input date", nextDate(0, 10, 2000));
    EXPECT_EQ("invalid input date", nextDate(32, 10, 2000));
    EXPECT_EQ("invalid input date", nextDate(0, 12, 2000));
    EXPECT_EQ("invalid input date", nextDate(32, 12, 2000));
    /* plus year */
    EXPECT_EQ("1,1,2001", nextDate(31, 12, 2000));
    EXPECT_EQ("not in range", nextDate(31, 12, 2012));
    /* plus month */
    EXPECT_EQ("1,2,2000", nextDate(31, 1, 2000));
    EXPECT_EQ("1,4,2000", nextDate(31, 3, 2000));
    EXPECT_EQ("1,6,2000", nextDate(31, 5, 2000));
    EXPECT_EQ("1,8,2000", nextDate(31, 7, 2000));
    EXPECT_EQ("1,9,2000", nextDate(31, 8, 2000));
    EXPECT_EQ("1,11,2000", nextDate(31, 10, 2000));
    /* plus day */
    EXPECT_EQ("16,1,2000", nextDate(15, 1, 2000));
    EXPECT_EQ("16,3,2000", nextDate(15, 3, 2000));
    EXPECT_EQ("16,5,2000", nextDate(15, 5, 2000));
    EXPECT_EQ("16,7,2000", nextDate(15, 7, 2000));
    EXPECT_EQ("16,8,2000", nextDate(15, 8, 2000));
    EXPECT_EQ("16,10,2000", nextDate(15, 10, 2000));
    EXPECT_EQ("16,12,2000", nextDate(15, 12, 2000));
}

TEST(Path_Testing, 30days_month) {
    /* isValid day */
    EXPECT_EQ("invalid input date", nextDate(0, 4, 2000));
    EXPECT_EQ("invalid input date", nextDate(31, 4, 2000));
    EXPECT_EQ("invalid input date", nextDate(0, 6, 2000));
    EXPECT_EQ("invalid input date", nextDate(31, 6, 2000));
    EXPECT_EQ("invalid input date", nextDate(0, 9, 2000));
    EXPECT_EQ("invalid input date", nextDate(31, 9, 2000));
    EXPECT_EQ("invalid input date", nextDate(0, 11, 2000));
    EXPECT_EQ("invalid input date", nextDate(31, 11, 2000));
    /* plus month */
    EXPECT_EQ("1,5,2000", nextDate(30, 4, 2000));
    EXPECT_EQ("1,7,2000", nextDate(30, 6, 2000));
    EXPECT_EQ("1,10,2000", nextDate(30, 9, 2000));
    EXPECT_EQ("1,12,2000", nextDate(30, 11, 2000));
    /* plus day */
    EXPECT_EQ("16,4,2000", nextDate(15, 4, 2000));
}

TEST(Path_Testing, February) {
}
