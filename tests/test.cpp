// Copyright 2020 Avackimyanc Levon levon.avakimyanc.01@mail.ru

#include <gtest/gtest.h>

#include "BoostSort.hpp"

std::string currentDir(const std::string& name) {
  // std::string s = "/Users/levon-avakimanc/Labs/Lab_04_Boost/tests/TestFiles";
  std::string s(__FILE__);
  for (size_t i = 0; i < 8; ++i) {
    s.pop_back();
  }
  return s + name;
}

TEST(Example, EmptyTest) { EXPECT_TRUE(true); }
TEST(BoostSort, WrongPath) { EXPECT_ANY_THROW(BoostSort("/Wrong/path")); }
TEST(BoostSort, EmptyPath) {
  BoostSort B("");
  EXPECT_EQ(B.GetPath(0), "..");
}
TEST(BoostSort, CorrectPrintAccount) {
  std::string AccPath{"/Users/levon-avakimanc/Labs/Lab_04_Boost/tests/TestFiles"};
  BoostSort B(AccPath);
  std::stringstream ss;
  ss = B.PrintAcc(B.GetPath(1), 2);
  EXPECT_EQ(
      ss.str(),
      "broker: bcs      account: 00122223 files: 2   lastdate: 2018.09.02");
}
TEST(BoostSort, CorrectOverloadPrint) {
  std::string path{currentDir("TestFiles")};
  std::stringstream ss;
  BoostSort B(path);
  ss << B;
  EXPECT_EQ(
      ss.str(),
      (R"(broker: bcs      account: 00122223 files: 2   lastdate: 2018.09.02
broker: otkr     account: 03934520 files: 3   lastdate: 2018.09.04
broker: otkr     account: 03934535 files: 2   lastdate: 2018.09.19
)"));
}
