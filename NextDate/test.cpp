#include <iostream>
#include "nextDate.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Normal_Boundary_Value_Test, bound_in_year) {
    EXPECT_EQ("16,6,1812", nextDate(15, 6, 1812));
    EXPECT_EQ("16,6,1813", nextDate(15, 6, 1813));
    EXPECT_EQ("16,6,2011", nextDate(15, 6, 2011));
    EXPECT_EQ("16,6,2012", nextDate(15, 6, 2012));
}

TEST(Normal_Boundary_Value_Test, bound_in_month) {
    EXPECT_EQ("16,1,1900", nextDate(15, 1, 1900));
    EXPECT_EQ("16,2,1900", nextDate(15, 2, 1900));
    EXPECT_EQ("16,11,1900", nextDate(15, 11, 1900));
    EXPECT_EQ("16,12,1900", nextDate(15, 12, 1900));
}

TEST(Normal_Boundary_Value_Test, bound_in_day) {
    //  30 days per month
    EXPECT_EQ("2,6,1900", nextDate(1, 6, 1900));
    EXPECT_EQ("3,6,1900", nextDate(2, 6, 1900));
    EXPECT_EQ("30,6,1900", nextDate(29, 6, 1900));
    EXPECT_EQ("1,7,1900", nextDate(30, 6, 1900));
    //  31 days per month
    EXPECT_EQ("2,7,1900", nextDate(1, 7, 1900));
    EXPECT_EQ("3,7,1900", nextDate(2, 7, 1900));
    EXPECT_EQ("31,7,1900", nextDate(30, 7, 1900));
    EXPECT_EQ("1,8,1900", nextDate(31, 7, 1900));
    //  28 or 29 dayse per month
    EXPECT_EQ("2,2,1900", nextDate(1, 2, 1900));
    EXPECT_EQ("3,2,1900", nextDate(2, 2, 1900));
    EXPECT_EQ("28,2,1900", nextDate(27, 2, 1900));
    EXPECT_EQ("1,3,1900", nextDate(28, 2, 1900));
    EXPECT_EQ("1,3,1904", nextDate(29, 2, 1904));
}

TEST(Robust_Boundary_Value_Test, bound_in_year) {
    EXPECT_EQ("invalid input date", nextDate(15, 6, 1811));
    EXPECT_EQ("invalid input date", nextDate(15, 6, 2013));
}

TEST(Robust_Boundary_Value_Test, bound_in_month) {
    EXPECT_EQ("invalid input date", nextDate(15, 0, 1900));
    EXPECT_EQ("invalid input date", nextDate(15, 13, 1900));
}

TEST(Robust_Boundary_Value_Test, bound_in_day) {
    //  30 days per month
    EXPECT_EQ("invalid input date", nextDate(0, 6, 1900));
    EXPECT_EQ("invalid input date", nextDate(31, 6, 1900));
    //  31 days per month
    EXPECT_EQ("invalid input date", nextDate(0, 7, 1900));
    EXPECT_EQ("invalid input date", nextDate(32, 7, 1900));
    //  28 or 29 dayse per month
    EXPECT_EQ("invalid input date", nextDate(0, 2, 1900));
    EXPECT_EQ("invalid input date", nextDate(29, 2, 1900));
    EXPECT_EQ("invalid input date", nextDate(0, 2, 1904));
    EXPECT_EQ("invalid input date", nextDate(30, 2, 1904));
}

TEST(Worst_Case_Boundary_Value_Test, Jan) {
	EXPECT_EQ("2,1,1812", nextDate(1, 1, 1812));
	EXPECT_EQ("2,1,1813", nextDate(1, 1, 1813));
	EXPECT_EQ("2,1,1912", nextDate(1, 1, 1912));
	EXPECT_EQ("2,1,2011", nextDate(1, 1, 2011));
	EXPECT_EQ("2,1,2012", nextDate(1, 1, 2012));
	EXPECT_EQ("3,1,1812", nextDate(2, 1, 1812));
	EXPECT_EQ("3,1,1813", nextDate(2, 1, 1813));
	EXPECT_EQ("3,1,1912", nextDate(2, 1, 1912));
	EXPECT_EQ("3,1,2011", nextDate(2, 1, 2011));
	EXPECT_EQ("3,1,2012", nextDate(2, 1, 2012));
	EXPECT_EQ("16,1,1812", nextDate(15, 1, 1812));
	EXPECT_EQ("16,1,1813", nextDate(15, 1, 1813));
	EXPECT_EQ("16,1,1912", nextDate(15, 1, 1912));
	EXPECT_EQ("16,1,2011", nextDate(15, 1, 2011));
	EXPECT_EQ("16,1,2012", nextDate(15, 1, 2012));
	EXPECT_EQ("31,1,1812", nextDate(30, 1, 1812));
	EXPECT_EQ("31,1,1813", nextDate(30, 1, 1813));
	EXPECT_EQ("31,1,1912", nextDate(30, 1, 1912));
	EXPECT_EQ("31,1,2011", nextDate(30, 1, 2011));
	EXPECT_EQ("31,1,2012", nextDate(30, 1, 2012));
	EXPECT_EQ("1,2,1812", nextDate(31, 1, 1812));
	EXPECT_EQ("1,2,1813", nextDate(31, 1, 1813));
	EXPECT_EQ("1,2,1912", nextDate(31, 1, 1912));
	EXPECT_EQ("1,2,2011", nextDate(31, 1, 2011));
	EXPECT_EQ("1,2,2012", nextDate(31, 1, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Feb) {
	EXPECT_EQ("2,2,1812", nextDate(1, 2, 1812));
	EXPECT_EQ("2,2,1813", nextDate(1, 2, 1813));
	EXPECT_EQ("2,2,1912", nextDate(1, 2, 1912));
	EXPECT_EQ("2,2,2011", nextDate(1, 2, 2011));
	EXPECT_EQ("2,2,2012", nextDate(1, 2, 2012));
	EXPECT_EQ("3,2,1812", nextDate(2, 2, 1812));
	EXPECT_EQ("3,2,1813", nextDate(2, 2, 1813));
	EXPECT_EQ("3,2,1912", nextDate(2, 2, 1912));
	EXPECT_EQ("3,2,2011", nextDate(2, 2, 2011));
	EXPECT_EQ("3,2,2012", nextDate(2, 2, 2012));
	EXPECT_EQ("16,2,1812", nextDate(15, 2, 1812));
	EXPECT_EQ("16,2,1813", nextDate(15, 2, 1813));
	EXPECT_EQ("16,2,1912", nextDate(15, 2, 1912));
	EXPECT_EQ("16,2,2011", nextDate(15, 2, 2011));
	EXPECT_EQ("16,2,2012", nextDate(15, 2, 2012));
	EXPECT_EQ("29,2,1812", nextDate(28, 2, 1812));
	EXPECT_EQ("1,3,1813", nextDate(28, 2, 1813));
	EXPECT_EQ("29,2,1912", nextDate(28, 2, 1912));
	EXPECT_EQ("1,3,2011", nextDate(28, 2, 2011));
	EXPECT_EQ("29,2,2012", nextDate(28, 2, 2012));
	EXPECT_EQ("1,3,1812", nextDate(29, 2, 1812));
	EXPECT_EQ("invalid input date", nextDate(29, 2, 1813));
	EXPECT_EQ("1,3,1912", nextDate(29, 2, 1912));
	EXPECT_EQ("invalid input date", nextDate(29, 2, 2011));
	EXPECT_EQ("1,3,2012", nextDate(29, 2, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Mar) {
	EXPECT_EQ("2,3,1812", nextDate(1, 3, 1812));
	EXPECT_EQ("2,3,1813", nextDate(1, 3, 1813));
	EXPECT_EQ("2,3,1912", nextDate(1, 3, 1912));
	EXPECT_EQ("2,3,2011", nextDate(1, 3, 2011));
	EXPECT_EQ("2,3,2012", nextDate(1, 3, 2012));
	EXPECT_EQ("3,3,1812", nextDate(2, 3, 1812));
	EXPECT_EQ("3,3,1813", nextDate(2, 3, 1813));
	EXPECT_EQ("3,3,1912", nextDate(2, 3, 1912));
	EXPECT_EQ("3,3,2011", nextDate(2, 3, 2011));
	EXPECT_EQ("3,3,2012", nextDate(2, 3, 2012));
	EXPECT_EQ("16,3,1812", nextDate(15, 3, 1812));
	EXPECT_EQ("16,3,1813", nextDate(15, 3, 1813));
	EXPECT_EQ("16,3,1912", nextDate(15, 3, 1912));
	EXPECT_EQ("16,3,2011", nextDate(15, 3, 2011));
	EXPECT_EQ("16,3,2012", nextDate(15, 3, 2012));
	EXPECT_EQ("31,3,1812", nextDate(30, 3, 1812));
	EXPECT_EQ("31,3,1813", nextDate(30, 3, 1813));
	EXPECT_EQ("31,3,1912", nextDate(30, 3, 1912));
	EXPECT_EQ("31,3,2011", nextDate(30, 3, 2011));
	EXPECT_EQ("31,3,2012", nextDate(30, 3, 2012));
	EXPECT_EQ("1,4,1812", nextDate(31, 3, 1812));
	EXPECT_EQ("1,4,1813", nextDate(31, 3, 1813));
	EXPECT_EQ("1,4,1912", nextDate(31, 3, 1912));
	EXPECT_EQ("1,4,2011", nextDate(31, 3, 2011));
	EXPECT_EQ("1,4,2012", nextDate(31, 3, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Apr) {
	EXPECT_EQ("2,4,1812", nextDate(1, 4, 1812));
	EXPECT_EQ("2,4,1813", nextDate(1, 4, 1813));
	EXPECT_EQ("2,4,1912", nextDate(1, 4, 1912));
	EXPECT_EQ("2,4,2011", nextDate(1, 4, 2011));
	EXPECT_EQ("2,4,2012", nextDate(1, 4, 2012));
	EXPECT_EQ("3,4,1812", nextDate(2, 4, 1812));
	EXPECT_EQ("3,4,1813", nextDate(2, 4, 1813));
	EXPECT_EQ("3,4,1912", nextDate(2, 4, 1912));
	EXPECT_EQ("3,4,2011", nextDate(2, 4, 2011));
	EXPECT_EQ("3,4,2012", nextDate(2, 4, 2012));
	EXPECT_EQ("16,4,1812", nextDate(15, 4, 1812));
	EXPECT_EQ("16,4,1813", nextDate(15, 4, 1813));
	EXPECT_EQ("16,4,1912", nextDate(15, 4, 1912));
	EXPECT_EQ("16,4,2011", nextDate(15, 4, 2011));
	EXPECT_EQ("16,4,2012", nextDate(15, 4, 2012));
	EXPECT_EQ("30,4,1812", nextDate(29, 4, 1812));
	EXPECT_EQ("30,4,1813", nextDate(29, 4, 1813));
	EXPECT_EQ("30,4,1912", nextDate(29, 4, 1912));
	EXPECT_EQ("30,4,2011", nextDate(29, 4, 2011));
	EXPECT_EQ("30,4,2012", nextDate(29, 4, 2012));
	EXPECT_EQ("1,5,1812", nextDate(30, 4, 1812));
	EXPECT_EQ("1,5,1813", nextDate(30, 4, 1813));
	EXPECT_EQ("1,5,1912", nextDate(30, 4, 1912));
	EXPECT_EQ("1,5,2011", nextDate(30, 4, 2011));
	EXPECT_EQ("1,5,2012", nextDate(30, 4, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, May) {
	EXPECT_EQ("2,5,1812", nextDate(1, 5, 1812));
	EXPECT_EQ("2,5,1813", nextDate(1, 5, 1813));
	EXPECT_EQ("2,5,1912", nextDate(1, 5, 1912));
	EXPECT_EQ("2,5,2011", nextDate(1, 5, 2011));
	EXPECT_EQ("2,5,2012", nextDate(1, 5, 2012));
	EXPECT_EQ("3,5,1812", nextDate(2, 5, 1812));
	EXPECT_EQ("3,5,1813", nextDate(2, 5, 1813));
	EXPECT_EQ("3,5,1912", nextDate(2, 5, 1912));
	EXPECT_EQ("3,5,2011", nextDate(2, 5, 2011));
	EXPECT_EQ("3,5,2012", nextDate(2, 5, 2012));
	EXPECT_EQ("16,5,1812", nextDate(15, 5, 1812));
	EXPECT_EQ("16,5,1813", nextDate(15, 5, 1813));
	EXPECT_EQ("16,5,1912", nextDate(15, 5, 1912));
	EXPECT_EQ("16,5,2011", nextDate(15, 5, 2011));
	EXPECT_EQ("16,5,2012", nextDate(15, 5, 2012));
	EXPECT_EQ("31,5,1812", nextDate(30, 5, 1812));
	EXPECT_EQ("31,5,1813", nextDate(30, 5, 1813));
	EXPECT_EQ("31,5,1912", nextDate(30, 5, 1912));
	EXPECT_EQ("31,5,2011", nextDate(30, 5, 2011));
	EXPECT_EQ("31,5,2012", nextDate(30, 5, 2012));
	EXPECT_EQ("1,6,1812", nextDate(31, 5, 1812));
	EXPECT_EQ("1,6,1813", nextDate(31, 5, 1813));
	EXPECT_EQ("1,6,1912", nextDate(31, 5, 1912));
	EXPECT_EQ("1,6,2011", nextDate(31, 5, 2011));
	EXPECT_EQ("1,6,2012", nextDate(31, 5, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Jun) {
	EXPECT_EQ("2,6,1812", nextDate(1, 6, 1812));
	EXPECT_EQ("2,6,1813", nextDate(1, 6, 1813));
	EXPECT_EQ("2,6,1912", nextDate(1, 6, 1912));
	EXPECT_EQ("2,6,2011", nextDate(1, 6, 2011));
	EXPECT_EQ("2,6,2012", nextDate(1, 6, 2012));
	EXPECT_EQ("3,6,1812", nextDate(2, 6, 1812));
	EXPECT_EQ("3,6,1813", nextDate(2, 6, 1813));
	EXPECT_EQ("3,6,1912", nextDate(2, 6, 1912));
	EXPECT_EQ("3,6,2011", nextDate(2, 6, 2011));
	EXPECT_EQ("3,6,2012", nextDate(2, 6, 2012));
	EXPECT_EQ("16,6,1812", nextDate(15, 6, 1812));
	EXPECT_EQ("16,6,1813", nextDate(15, 6, 1813));
	EXPECT_EQ("16,6,1912", nextDate(15, 6, 1912));
	EXPECT_EQ("16,6,2011", nextDate(15, 6, 2011));
	EXPECT_EQ("16,6,2012", nextDate(15, 6, 2012));
	EXPECT_EQ("30,6,1812", nextDate(29, 6, 1812));
	EXPECT_EQ("30,6,1813", nextDate(29, 6, 1813));
	EXPECT_EQ("30,6,1912", nextDate(29, 6, 1912));
	EXPECT_EQ("30,6,2011", nextDate(29, 6, 2011));
	EXPECT_EQ("30,6,2012", nextDate(29, 6, 2012));
	EXPECT_EQ("1,7,1812", nextDate(30, 6, 1812));
	EXPECT_EQ("1,7,1813", nextDate(30, 6, 1813));
	EXPECT_EQ("1,7,1912", nextDate(30, 6, 1912));
	EXPECT_EQ("1,7,2011", nextDate(30, 6, 2011));
	EXPECT_EQ("1,7,2012", nextDate(30, 6, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Jul) {
	EXPECT_EQ("2,7,1812", nextDate(1, 7, 1812));
	EXPECT_EQ("2,7,1813", nextDate(1, 7, 1813));
	EXPECT_EQ("2,7,1912", nextDate(1, 7, 1912));
	EXPECT_EQ("2,7,2011", nextDate(1, 7, 2011));
	EXPECT_EQ("2,7,2012", nextDate(1, 7, 2012));
	EXPECT_EQ("3,7,1812", nextDate(2, 7, 1812));
	EXPECT_EQ("3,7,1813", nextDate(2, 7, 1813));
	EXPECT_EQ("3,7,1912", nextDate(2, 7, 1912));
	EXPECT_EQ("3,7,2011", nextDate(2, 7, 2011));
	EXPECT_EQ("3,7,2012", nextDate(2, 7, 2012));
	EXPECT_EQ("16,7,1812", nextDate(15, 7, 1812));
	EXPECT_EQ("16,7,1813", nextDate(15, 7, 1813));
	EXPECT_EQ("16,7,1912", nextDate(15, 7, 1912));
	EXPECT_EQ("16,7,2011", nextDate(15, 7, 2011));
	EXPECT_EQ("16,7,2012", nextDate(15, 7, 2012));
	EXPECT_EQ("31,7,1812", nextDate(30, 7, 1812));
	EXPECT_EQ("31,7,1813", nextDate(30, 7, 1813));
	EXPECT_EQ("31,7,1912", nextDate(30, 7, 1912));
	EXPECT_EQ("31,7,2011", nextDate(30, 7, 2011));
	EXPECT_EQ("31,7,2012", nextDate(30, 7, 2012));
	EXPECT_EQ("1,8,1812", nextDate(31, 7, 1812));
	EXPECT_EQ("1,8,1813", nextDate(31, 7, 1813));
	EXPECT_EQ("1,8,1912", nextDate(31, 7, 1912));
	EXPECT_EQ("1,8,2011", nextDate(31, 7, 2011));
	EXPECT_EQ("1,8,2012", nextDate(31, 7, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Aug) {
	EXPECT_EQ("2,8,1812", nextDate(1, 8, 1812));
	EXPECT_EQ("2,8,1813", nextDate(1, 8, 1813));
	EXPECT_EQ("2,8,1912", nextDate(1, 8, 1912));
	EXPECT_EQ("2,8,2011", nextDate(1, 8, 2011));
	EXPECT_EQ("2,8,2012", nextDate(1, 8, 2012));
	EXPECT_EQ("3,8,1812", nextDate(2, 8, 1812));
	EXPECT_EQ("3,8,1813", nextDate(2, 8, 1813));
	EXPECT_EQ("3,8,1912", nextDate(2, 8, 1912));
	EXPECT_EQ("3,8,2011", nextDate(2, 8, 2011));
	EXPECT_EQ("3,8,2012", nextDate(2, 8, 2012));
	EXPECT_EQ("16,8,1812", nextDate(15, 8, 1812));
	EXPECT_EQ("16,8,1813", nextDate(15, 8, 1813));
	EXPECT_EQ("16,8,1912", nextDate(15, 8, 1912));
	EXPECT_EQ("16,8,2011", nextDate(15, 8, 2011));
	EXPECT_EQ("16,8,2012", nextDate(15, 8, 2012));
	EXPECT_EQ("31,8,1812", nextDate(30, 8, 1812));
	EXPECT_EQ("31,8,1813", nextDate(30, 8, 1813));
	EXPECT_EQ("31,8,1912", nextDate(30, 8, 1912));
	EXPECT_EQ("31,8,2011", nextDate(30, 8, 2011));
	EXPECT_EQ("31,8,2012", nextDate(30, 8, 2012));
	EXPECT_EQ("1,9,1812", nextDate(31, 8, 1812));
	EXPECT_EQ("1,9,1813", nextDate(31, 8, 1813));
	EXPECT_EQ("1,9,1912", nextDate(31, 8, 1912));
	EXPECT_EQ("1,9,2011", nextDate(31, 8, 2011));
	EXPECT_EQ("1,9,2012", nextDate(31, 8, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Sep) {
	EXPECT_EQ("2,9,1812", nextDate(1, 9, 1812));
	EXPECT_EQ("2,9,1813", nextDate(1, 9, 1813));
	EXPECT_EQ("2,9,1912", nextDate(1, 9, 1912));
	EXPECT_EQ("2,9,2011", nextDate(1, 9, 2011));
	EXPECT_EQ("2,9,2012", nextDate(1, 9, 2012));
	EXPECT_EQ("3,9,1812", nextDate(2, 9, 1812));
	EXPECT_EQ("3,9,1813", nextDate(2, 9, 1813));
	EXPECT_EQ("3,9,1912", nextDate(2, 9, 1912));
	EXPECT_EQ("3,9,2011", nextDate(2, 9, 2011));
	EXPECT_EQ("3,9,2012", nextDate(2, 9, 2012));
	EXPECT_EQ("16,9,1812", nextDate(15, 9, 1812));
	EXPECT_EQ("16,9,1813", nextDate(15, 9, 1813));
	EXPECT_EQ("16,9,1912", nextDate(15, 9, 1912));
	EXPECT_EQ("16,9,2011", nextDate(15, 9, 2011));
	EXPECT_EQ("16,9,2012", nextDate(15, 9, 2012));
	EXPECT_EQ("30,9,1812", nextDate(29, 9, 1812));
	EXPECT_EQ("30,9,1813", nextDate(29, 9, 1813));
	EXPECT_EQ("30,9,1912", nextDate(29, 9, 1912));
	EXPECT_EQ("30,9,2011", nextDate(29, 9, 2011));
	EXPECT_EQ("30,9,2012", nextDate(29, 9, 2012));
	EXPECT_EQ("1,10,1812", nextDate(30, 9, 1812));
	EXPECT_EQ("1,10,1813", nextDate(30, 9, 1813));
	EXPECT_EQ("1,10,1912", nextDate(30, 9, 1912));
	EXPECT_EQ("1,10,2011", nextDate(30, 9, 2011));
	EXPECT_EQ("1,10,2012", nextDate(30, 9, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Oct) {
	EXPECT_EQ("2,10,1812", nextDate(1, 10, 1812));
	EXPECT_EQ("2,10,1813", nextDate(1, 10, 1813));
	EXPECT_EQ("2,10,1912", nextDate(1, 10, 1912));
	EXPECT_EQ("2,10,2011", nextDate(1, 10, 2011));
	EXPECT_EQ("2,10,2012", nextDate(1, 10, 2012));
	EXPECT_EQ("3,10,1812", nextDate(2, 10, 1812));
	EXPECT_EQ("3,10,1813", nextDate(2, 10, 1813));
	EXPECT_EQ("3,10,1912", nextDate(2, 10, 1912));
	EXPECT_EQ("3,10,2011", nextDate(2, 10, 2011));
	EXPECT_EQ("3,10,2012", nextDate(2, 10, 2012));
	EXPECT_EQ("16,10,1812", nextDate(15, 10, 1812));
	EXPECT_EQ("16,10,1813", nextDate(15, 10, 1813));
	EXPECT_EQ("16,10,1912", nextDate(15, 10, 1912));
	EXPECT_EQ("16,10,2011", nextDate(15, 10, 2011));
	EXPECT_EQ("16,10,2012", nextDate(15, 10, 2012));
	EXPECT_EQ("31,10,1812", nextDate(30, 10, 1812));
	EXPECT_EQ("31,10,1813", nextDate(30, 10, 1813));
	EXPECT_EQ("31,10,1912", nextDate(30, 10, 1912));
	EXPECT_EQ("31,10,2011", nextDate(30, 10, 2011));
	EXPECT_EQ("31,10,2012", nextDate(30, 10, 2012));
	EXPECT_EQ("1,11,1812", nextDate(31, 10, 1812));
	EXPECT_EQ("1,11,1813", nextDate(31, 10, 1813));
	EXPECT_EQ("1,11,1912", nextDate(31, 10, 1912));
	EXPECT_EQ("1,11,2011", nextDate(31, 10, 2011));
	EXPECT_EQ("1,11,2012", nextDate(31, 10, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Nov) {
	EXPECT_EQ("2,11,1812", nextDate(1, 11, 1812));
	EXPECT_EQ("2,11,1813", nextDate(1, 11, 1813));
	EXPECT_EQ("2,11,1912", nextDate(1, 11, 1912));
	EXPECT_EQ("2,11,2011", nextDate(1, 11, 2011));
	EXPECT_EQ("2,11,2012", nextDate(1, 11, 2012));
	EXPECT_EQ("3,11,1812", nextDate(2, 11, 1812));
	EXPECT_EQ("3,11,1813", nextDate(2, 11, 1813));
	EXPECT_EQ("3,11,1912", nextDate(2, 11, 1912));
	EXPECT_EQ("3,11,2011", nextDate(2, 11, 2011));
	EXPECT_EQ("3,11,2012", nextDate(2, 11, 2012));
	EXPECT_EQ("16,11,1812", nextDate(15, 11, 1812));
	EXPECT_EQ("16,11,1813", nextDate(15, 11, 1813));
	EXPECT_EQ("16,11,1912", nextDate(15, 11, 1912));
	EXPECT_EQ("16,11,2011", nextDate(15, 11, 2011));
	EXPECT_EQ("16,11,2012", nextDate(15, 11, 2012));
	EXPECT_EQ("30,11,1812", nextDate(29, 11, 1812));
	EXPECT_EQ("30,11,1813", nextDate(29, 11, 1813));
	EXPECT_EQ("30,11,1912", nextDate(29, 11, 1912));
	EXPECT_EQ("30,11,2011", nextDate(29, 11, 2011));
	EXPECT_EQ("30,11,2012", nextDate(29, 11, 2012));
	EXPECT_EQ("1,12,1812", nextDate(30, 11, 1812));
	EXPECT_EQ("1,12,1813", nextDate(30, 11, 1813));
	EXPECT_EQ("1,12,1912", nextDate(30, 11, 1912));
	EXPECT_EQ("1,12,2011", nextDate(30, 11, 2011));
	EXPECT_EQ("1,12,2012", nextDate(30, 11, 2012));
}

TEST(Worst_Case_Boundary_Value_Test, Dec) {
	EXPECT_EQ("2,12,1812", nextDate(1, 12, 1812));
	EXPECT_EQ("2,12,1813", nextDate(1, 12, 1813));
	EXPECT_EQ("2,12,1912", nextDate(1, 12, 1912));
	EXPECT_EQ("2,12,2011", nextDate(1, 12, 2011));
	EXPECT_EQ("2,12,2012", nextDate(1, 12, 2012));
	EXPECT_EQ("3,12,1812", nextDate(2, 12, 1812));
	EXPECT_EQ("3,12,1813", nextDate(2, 12, 1813));
	EXPECT_EQ("3,12,1912", nextDate(2, 12, 1912));
	EXPECT_EQ("3,12,2011", nextDate(2, 12, 2011));
	EXPECT_EQ("3,12,2012", nextDate(2, 12, 2012));
	EXPECT_EQ("16,12,1812", nextDate(15, 12, 1812));
	EXPECT_EQ("16,12,1813", nextDate(15, 12, 1813));
	EXPECT_EQ("16,12,1912", nextDate(15, 12, 1912));
	EXPECT_EQ("16,12,2011", nextDate(15, 12, 2011));
	EXPECT_EQ("16,12,2012", nextDate(15, 12, 2012));
	EXPECT_EQ("31,12,1812", nextDate(30, 12, 1812));
	EXPECT_EQ("31,12,1813", nextDate(30, 12, 1813));
	EXPECT_EQ("31,12,1912", nextDate(30, 12, 1912));
	EXPECT_EQ("31,12,2011", nextDate(30, 12, 2011));
	EXPECT_EQ("31,12,2012", nextDate(30, 12, 2012));
	EXPECT_EQ("1,1,1813", nextDate(31, 12, 1812));
	EXPECT_EQ("1,1,1814", nextDate(31, 12, 1813));
	EXPECT_EQ("1,1,1913", nextDate(31, 12, 1912));
	EXPECT_EQ("1,1,2012", nextDate(31, 12, 2011));
	EXPECT_EQ("not in range", nextDate(31, 12, 2012));
}

TEST(Equivalence_Class, weak_normal) {
	EXPECT_EQ("15,6,2000", nextDate(14, 6, 2000));
	EXPECT_EQ("30,7,1996", nextDate(29, 7, 1996));
	EXPECT_EQ("invalid input date", nextDate(30, 2, 2002));
	EXPECT_EQ("invalid input date", nextDate(31, 6, 2000));
}

TEST(Equivalence_Class, strong_normal) {
	EXPECT_EQ("15,6,2000", nextDate(14, 6, 2000));
	EXPECT_EQ("15,6,1996", nextDate(14, 6, 1996));
	EXPECT_EQ("15,6,2002", nextDate(14, 6, 2002));
	EXPECT_EQ("30,6,2000", nextDate(29, 6, 2000));
	EXPECT_EQ("30,6,1996", nextDate(29, 6, 1996));
	EXPECT_EQ("30,6,2002", nextDate(29, 6, 2002));
	EXPECT_EQ("1,7,2000", nextDate(30, 6, 2000));
	EXPECT_EQ("1,7,1996", nextDate(30, 6, 1996));
	EXPECT_EQ("1,7,2002", nextDate(30, 6, 2002));
	EXPECT_EQ("invalid input date", nextDate(31, 6, 2000));
	EXPECT_EQ("invalid input date", nextDate(31, 6, 1996));
	EXPECT_EQ("invalid input date", nextDate(31, 6, 2002));
	EXPECT_EQ("15,7,2000", nextDate(14, 7, 2000));
	EXPECT_EQ("15,7,1996", nextDate(14, 7, 1996));
	EXPECT_EQ("15,7,2002", nextDate(14, 7, 2002));
	EXPECT_EQ("30,7,2000", nextDate(29, 7, 2000));
	EXPECT_EQ("30,7,1996", nextDate(29, 7, 1996));
	EXPECT_EQ("30,7,2002", nextDate(29, 7, 2002));
	EXPECT_EQ("31,7,2000", nextDate(30, 7, 2000));
	EXPECT_EQ("31,7,1996", nextDate(30, 7, 1996));
	EXPECT_EQ("31,7,2002", nextDate(30, 7, 2002));
	EXPECT_EQ("1,8,2000", nextDate(31, 7, 2000));
	EXPECT_EQ("1,8,1996", nextDate(31, 7, 1996));
	EXPECT_EQ("1,8,2002", nextDate(31, 7, 2002));
	EXPECT_EQ("15,2,2000", nextDate(14, 2, 2000));
	EXPECT_EQ("15,2,1996", nextDate(14, 2, 1996));
	EXPECT_EQ("15,2,2002", nextDate(14, 2, 2002));
	EXPECT_EQ("1,3,2000", nextDate(29, 2, 2000));
	EXPECT_EQ("1,3,1996", nextDate(29, 2, 1996));
	EXPECT_EQ("invalid input date", nextDate(29, 2, 2002));
	EXPECT_EQ("invalid input date", nextDate(30, 2, 2000));
	EXPECT_EQ("invalid input date", nextDate(30, 2, 1996));
	EXPECT_EQ("invalid input date", nextDate(30, 2, 2002));
	EXPECT_EQ("invalid input date", nextDate(31, 2, 2000));
	EXPECT_EQ("invalid input date", nextDate(31, 2, 1996));
	EXPECT_EQ("invalid input date", nextDate(31, 2, 2002));
}

TEST(Equivalence_Class, weak_robust) {
	EXPECT_EQ("invalid input date", nextDate(0, 6, 2000));
	EXPECT_EQ("invalid input date", nextDate(32, 7, 1996));
	EXPECT_EQ("invalid input date", nextDate(0, 2, 2002));
	EXPECT_EQ("invalid input date", nextDate(32, 6, 2000));
}

TEST(Equivalence_Class, strong_robust) {
	EXPECT_EQ("invalid input date", nextDate(0, 6, 2000));
	EXPECT_EQ("invalid input date", nextDate(32, 6, 2000));
	EXPECT_EQ("invalid input date", nextDate(0, 6, 1996));
	EXPECT_EQ("invalid input date", nextDate(32, 6, 1996));
	EXPECT_EQ("invalid input date", nextDate(0, 6, 2002));
	EXPECT_EQ("invalid input date", nextDate(32, 6, 2002));
	EXPECT_EQ("invalid input date", nextDate(0, 7, 2000));
	EXPECT_EQ("invalid input date", nextDate(32, 7, 2000));
	EXPECT_EQ("invalid input date", nextDate(0, 7, 1996));
	EXPECT_EQ("invalid input date", nextDate(32, 7, 1996));
	EXPECT_EQ("invalid input date", nextDate(0, 7, 2002));
	EXPECT_EQ("invalid input date", nextDate(32, 7, 2002));
	EXPECT_EQ("invalid input date", nextDate(0, 2, 2000));
	EXPECT_EQ("invalid input date", nextDate(32, 2, 2000));
	EXPECT_EQ("invalid input date", nextDate(0, 2, 1996));
	EXPECT_EQ("invalid input date", nextDate(32, 2, 1996));
	EXPECT_EQ("invalid input date", nextDate(0, 2, 2002));
	EXPECT_EQ("invalid input date", nextDate(32, 2, 2002));
	EXPECT_EQ("invalid input date", nextDate(14, 0, 2000));
	EXPECT_EQ("invalid input date", nextDate(29, 0, 2000));
	EXPECT_EQ("invalid input date", nextDate(30, 0, 2000));
	EXPECT_EQ("invalid input date", nextDate(31, 0, 2000));
	EXPECT_EQ("invalid input date", nextDate(14, 13, 2000));
	EXPECT_EQ("invalid input date", nextDate(29, 13, 2000));
	EXPECT_EQ("invalid input date", nextDate(30, 13, 2000));
	EXPECT_EQ("invalid input date", nextDate(31, 13, 2000));
	EXPECT_EQ("invalid input date", nextDate(14, 0, 1996));
	EXPECT_EQ("invalid input date", nextDate(29, 0, 1996));
	EXPECT_EQ("invalid input date", nextDate(30, 0, 1996));
	EXPECT_EQ("invalid input date", nextDate(31, 0, 1996));
	EXPECT_EQ("invalid input date", nextDate(14, 13, 1996));
	EXPECT_EQ("invalid input date", nextDate(29, 13, 1996));
	EXPECT_EQ("invalid input date", nextDate(30, 13, 1996));
	EXPECT_EQ("invalid input date", nextDate(31, 13, 1996));
	EXPECT_EQ("invalid input date", nextDate(14, 0, 2002));
	EXPECT_EQ("invalid input date", nextDate(29, 0, 2002));
	EXPECT_EQ("invalid input date", nextDate(30, 0, 2002));
	EXPECT_EQ("invalid input date", nextDate(31, 0, 2002));
	EXPECT_EQ("invalid input date", nextDate(14, 13, 2002));
	EXPECT_EQ("invalid input date", nextDate(29, 13, 2002));
	EXPECT_EQ("invalid input date", nextDate(30, 13, 2002));
	EXPECT_EQ("invalid input date", nextDate(31, 13, 2002));
	EXPECT_EQ("invalid input date", nextDate(14, 6, 0));
	EXPECT_EQ("invalid input date", nextDate(14, 6, 3000));
	EXPECT_EQ("invalid input date", nextDate(29, 6, 0));
	EXPECT_EQ("invalid input date", nextDate(29, 6, 3000));
	EXPECT_EQ("invalid input date", nextDate(30, 6, 0));
	EXPECT_EQ("invalid input date", nextDate(30, 6, 3000));
	EXPECT_EQ("invalid input date", nextDate(31, 6, 0));
	EXPECT_EQ("invalid input date", nextDate(31, 6, 3000));
	EXPECT_EQ("invalid input date", nextDate(14, 7, 0));
	EXPECT_EQ("invalid input date", nextDate(14, 7, 3000));
	EXPECT_EQ("invalid input date", nextDate(29, 7, 0));
	EXPECT_EQ("invalid input date", nextDate(29, 7, 3000));
	EXPECT_EQ("invalid input date", nextDate(30, 7, 0));
	EXPECT_EQ("invalid input date", nextDate(30, 7, 3000));
	EXPECT_EQ("invalid input date", nextDate(31, 7, 0));
	EXPECT_EQ("invalid input date", nextDate(31, 7, 3000));
	EXPECT_EQ("invalid input date", nextDate(14, 2, 0));
	EXPECT_EQ("invalid input date", nextDate(14, 2, 3000));
	EXPECT_EQ("invalid input date", nextDate(29, 2, 0));
	EXPECT_EQ("invalid input date", nextDate(29, 2, 3000));
	EXPECT_EQ("invalid input date", nextDate(30, 2, 0));
	EXPECT_EQ("invalid input date", nextDate(30, 2, 3000));
	EXPECT_EQ("invalid input date", nextDate(31, 2, 0));
	EXPECT_EQ("invalid input date", nextDate(31, 2, 3000));
}

TEST(Edge_Test, normal) {
    //  M1 D1
	EXPECT_EQ("29,11,2000", nextDate(28, 11, 2000));
	EXPECT_EQ("29,11,2012", nextDate(28, 11, 2012));
	EXPECT_EQ("29,11,2011", nextDate(28, 11, 2011));
    //  M1 D2
	EXPECT_EQ("30,11,2000", nextDate(29, 11, 2000));
	EXPECT_EQ("30,11,2012", nextDate(29, 11, 2012));
	EXPECT_EQ("30,11,2011", nextDate(29, 11, 2011));
    //  M1 D3
	EXPECT_EQ("1,12,2000", nextDate(30, 11, 2000));
	EXPECT_EQ("1,12,2012", nextDate(30, 11, 2012));
	EXPECT_EQ("1,12,2011", nextDate(30, 11, 2011));
    //  M1 D4
	EXPECT_EQ("invalid input date", nextDate(31, 11, 2000));
	EXPECT_EQ("invalid input date", nextDate(31, 11, 2012));
	EXPECT_EQ("invalid input date", nextDate(31, 11, 2011));
    //  M2 D1
	EXPECT_EQ("29,12,2000", nextDate(28, 12, 2000));
	EXPECT_EQ("29,12,2012", nextDate(28, 12, 2012));
	EXPECT_EQ("29,12,2011", nextDate(28, 12, 2011));
    //  M2 D2
	EXPECT_EQ("30,12,2000", nextDate(29, 12, 2000));
	EXPECT_EQ("30,12,2012", nextDate(29, 12, 2012));
	EXPECT_EQ("30,12,2011", nextDate(29, 12, 2011));
    //  M2 D3
	EXPECT_EQ("31,12,2000", nextDate(30, 12, 2000));
	EXPECT_EQ("31,12,2012", nextDate(30, 12, 2012));
	EXPECT_EQ("31,12,2011", nextDate(30, 12, 2011));
    //  M2 D4
	EXPECT_EQ("1,1,2001", nextDate(31, 12, 2000));
	EXPECT_EQ("not in range", nextDate(31, 12, 2012));
	EXPECT_EQ("1,1,2012", nextDate(31, 12, 2011));
    //  M3 D1
	EXPECT_EQ("29,2,2000", nextDate(28, 2, 2000));
	EXPECT_EQ("29,2,2012", nextDate(28, 2, 2012));
	EXPECT_EQ("1,3,2011", nextDate(28, 2, 2011));
    //  M3 D2
	EXPECT_EQ("1,3,2000", nextDate(29, 2, 2000));
	EXPECT_EQ("1,3,2012", nextDate(29, 2, 2012));
	EXPECT_EQ("invalid input date", nextDate(29, 2, 2011));
    //  M3 D3
	EXPECT_EQ("invalid input date", nextDate(30, 2, 2000));
	EXPECT_EQ("invalid input date", nextDate(30, 2, 2012));
	EXPECT_EQ("invalid input date", nextDate(30, 2, 2011));
    //  M3 D4
	EXPECT_EQ("invalid input date", nextDate(31, 2, 2000));
	EXPECT_EQ("invalid input date", nextDate(31, 2, 2012));
	EXPECT_EQ("invalid input date", nextDate(31, 2, 2011));
}

TEST(Decision_Table, M1) {
	EXPECT_EQ("16,4,2001", nextDate(15, 4, 2001));
	EXPECT_EQ("1,5,2001", nextDate(30, 4, 2001));
	EXPECT_EQ("invalid input date", nextDate(31, 4, 2001));
}

TEST(Decision_Table, M2) {
	EXPECT_EQ("16,1,2001", nextDate(15, 1, 2001));
	EXPECT_EQ("1,2,2001", nextDate(31, 1, 2001));
}

TEST(Decision_Table, M3) {
	EXPECT_EQ("16,12,2001", nextDate(15, 12, 2001));
	EXPECT_EQ("1,1,2002", nextDate(31, 12, 2001));
}

TEST(Decision_Table, M4) {
	EXPECT_EQ("16,2,2001", nextDate(15, 2, 2001));
	EXPECT_EQ("29,2,2004", nextDate(28, 2, 2004));
	EXPECT_EQ("1,3,2001", nextDate(28, 2, 2001));
	EXPECT_EQ("1,3,2004", nextDate(29, 2, 2004));
	EXPECT_EQ("invalid input date", nextDate(29, 2, 2001));
	EXPECT_EQ("invalid input date", nextDate(30, 2, 2001));
}
