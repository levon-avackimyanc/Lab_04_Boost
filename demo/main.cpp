// Copyright 2020 Avackimyanc Levon levon.avakimyanc.01@mail.ru

#include "BoostSort.h"

int main(int argc, char* argv[]) {
  std::string path;
  if (argc > 1) {
    path = argv[1];
  } else {
    path = "";
  }
  BoostSort Bs(path);
  Bs.DirectoriesPass(path);
  Bs.PrintAllInformation(std::cout);
  return 0;
}