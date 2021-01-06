//
// Copyright 2020 Avackimyanc Levon levon.avakimyanc.01@mail.ru
//

#include "BoostSort.hpp"

int main() {
  std::string path{"/Users/levon-avakimanc/Labs/Lab_04_Boost/misc/ftp"};
  /*if (argc > 1) {
    path = argv[1];
  } else {
    path = "";
  }*/
  BoostSort B{path};
  std::cout << B;
  return 0;
}
