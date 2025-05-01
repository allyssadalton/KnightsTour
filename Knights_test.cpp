/*    @file MyComplex_test.cpp   
      @author < Fill Me In >
      @date < Fill Me In >

			@description Tests for the MyComplex class
*/

#include "gtest/gtest.h"

#include "Knights.h"



TEST(CompleteTour, NotAll) {
  Knights a(3,3);
  EXPECT_EQ(a.completeTour(), false);
}

TEST(CompleteTour, Missing) {
  Knights a(3,4);
  a.at(0,0) = 0;
  a.at(1,0) = 7;
  a.at(2,0) = 2;
  a.at(0,1) = 3;
  a.at(1,1) = 10;
  a.at(2,1) = 5;
  a.at(0,2) = 6;
  a.at(1,2) = 1;
  a.at(2,2) = 8;
  a.at(0,3) = 9;
  a.at(1,3) = 4;
  EXPECT_EQ(a.completeTour(), false);
}

TEST(CompleteTour, Complete) {
  Knights a(3,4);
  a.at(0,0) = 0;
  a.at(1,0) = 7;
  a.at(2,0) = 2;
  a.at(0,1) = 3;
  a.at(1,1) = 10;
  a.at(2,1) = 5;
  a.at(0,2) = 6;
  a.at(1,2) = 1;
  a.at(2,2) = 8;
  a.at(0,3) = 9;
  a.at(1,3) = 4;
  a.at(2,3) = 11;
  EXPECT_EQ(a.completeTour(), true);
}

TEST(CompleteTour, Swap) {
  Knights a(3,4);
  a.at(0,0) = 0;
  a.at(1,0) = 7;
  a.at(2,0) = 2;
  a.at(0,1) = 3;
  a.at(1,1) = 10;
  a.at(2,1) = 5;
  a.at(0,2) = 6;
  a.at(1,2) = 1;
  a.at(2,2) = 9;
  a.at(0,3) = 8;
  a.at(1,3) = 4;
  a.at(2,3) = 11;
  EXPECT_EQ(a.completeTour(), false);
}

TEST(CompleteTour, Duplicate) {
  Knights a(3,4);
  a.at(0,0) = 0;
  a.at(1,0) = 7;
  a.at(2,0) = 2;
  a.at(0,1) = 3;
  a.at(1,1) = 10;
  a.at(2,1) = 5;
  a.at(0,2) = 6;
  a.at(1,2) = 1;
  a.at(2,2) = 7;
  a.at(0,3) = 9;
  a.at(1,3) = 4;
  a.at(2,3) = 11;
  EXPECT_EQ(a.completeTour(), false);
}

TEST(CompleteTour55, Correct) {
  Knights a(4,5);
  a.at(0,0) = 0;
  a.at(1,0) = 5;
  a.at(2,0) = 10;
  a.at(3,0) = 15;
  a.at(0,1) = 19;
  a.at(1,1) = 14;
  a.at(2,1) = 1;
  a.at(3,1) = 6;
  a.at(0,2) = 4;
  a.at(1,2) = 9;
  a.at(2,2) = 16;
  a.at(3,2) = 11;
  a.at(0,3) = 13;
  a.at(1,3) = 18;
  a.at(2,3) = 7;
  a.at(3,3) = 2;
  a.at(0,4) = 8;
  a.at(1,4) = 3;
  a.at(2,4) = 12;
  a.at(3,4) = 17;
  EXPECT_EQ(a.completeTour(), true);
}

TEST(CompleteTour55, Swap) {
  Knights a(4,5);
  a.at(0,0) = 0;
  a.at(1,0) = 5;
  a.at(2,0) = 10;
  a.at(3,0) = 15;
  a.at(0,1) = 19;
  a.at(1,1) = 14;
  a.at(2,1) = 1;
  a.at(3,1) = 6;
  a.at(0,2) = 4;
  a.at(1,2) = 9;
  a.at(2,2) = 16;
  a.at(3,2) = 11;
  a.at(0,3) = 13;
  a.at(1,3) = 18;
  a.at(2,3) = 17;
  a.at(3,3) = 8;
  a.at(0,4) = 2;
  a.at(1,4) = 3;
  a.at(2,4) = 12;
  a.at(3,4) = 17;
  EXPECT_EQ(a.completeTour(), false);
}

TEST(Solve, Doable34) {
  Knights a(3,4);
  EXPECT_EQ(a.solve(), true);
  EXPECT_EQ(a.completeTour(), true);
}

TEST(Solve, Not33) {
  Knights a(3,3);
  EXPECT_EQ(a.solve(), false);
  EXPECT_EQ(a.completeTour(), false);
}

TEST(Solve, Doable46) {
  Knights a(4,6);
  EXPECT_EQ(a.solve(), true);
  EXPECT_EQ(a.completeTour(), true);
}

TEST(toXY, Validate) {
  Knights a(3,2);
  auto [x, y] = a.toXY(0);  // Declares 2 variables and assigns.
  EXPECT_EQ(x, 0);
  EXPECT_EQ(y, 0);  

  tie(x,y) = a.toXY(3); // Extracts and assigns a tuple
  EXPECT_EQ(x, 0);
  EXPECT_EQ(y, 1);

  tie(x,y) = a.toXY(5); // Extracts and assigns a tuple
  EXPECT_EQ(x, 2);
  EXPECT_EQ(y, 1);

  EXPECT_ANY_THROW(a.toXY(6));
}

TEST(XY, Validate) {
  Knights a(3,2);
  EXPECT_EQ(a.XY(0,0), 0);
  EXPECT_EQ(a.XY(2,0), 2);
  EXPECT_EQ(a.XY(2,1), 5);

  EXPECT_ANY_THROW(a.XY(3,0));
  EXPECT_ANY_THROW(a.XY(0,2));
}


