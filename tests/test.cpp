// Copyright 2020 Avackimyanc Levon levon.avakimyanc.01@mail.ru

#include <gtest/gtest.h>
#include "BoostSort.h"

std::string currentDir() {
  std::string s = __FILE__;
  return s.substr(0, s.find("test.cpp"));
}

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}
TEST(BoostSort, PathConstruct){
  bfs::path Path;
  ASSERT_EQ(BoostSort{Path}.getPath().string(), "..");
  bfs::path MiscPath{"../misc"};
  ASSERT_EQ(BoostSort{MiscPath}.getPath().string(), "../misc");
}
TEST(BoostSort, PrintAllFiles){
BoostSort Bs{bfs::path{currentDir()}};
Bs.DirectoriesPass(Bs.getPath());
std::stringstream ss;
Bs.printAllFiles(ss);
EXPECT_EQ(ss.str(), "Broker balance_00122223_20180901.txt\n");
}