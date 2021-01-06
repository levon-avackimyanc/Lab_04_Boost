// Copyright 2020 Avackimyanc Levon levon.avakimyanc.01@mail.ru

#include "BoostSort.hpp"

#include <iomanip>
#include <regex>
const unsigned int TimePos = 17;
const unsigned int TimeLength = 8;
BoostSort::BoostSort(const std::string& _path) {
  const std::regex re("^(balance)\\w\\d{8}\\w\\d{8}");
  if (!_path.empty()) {
    if (bfs::exists(_path)) {
      Path = _path;
      for (const bfs::directory_entry& itdir : bfs::directory_iterator{Path}) {
        if (bfs::is_directory(itdir.path())) {
          for (const bfs::directory_entry& itfile :
               bfs::directory_iterator{itdir.path()}) {
            if ((itfile.path().stem().extension() == "") &&
                (itfile.path().extension() == ".txt") &&
                (std::regex_search(itfile.path().stem().string(), re))) {
              std::cout << std::left << std::setw(10)
                        << itfile.path().parent_path().filename().string()
                        << " " << itfile.path().filename().string()
                        << std::endl;
              ArrPath.emplace_back(itfile.path());
              AccountNames.insert(itfile.path().stem().string().substr(8, 8));
            }
          }
        }
      }
    } else {
      throw std::exception();
    }
  } else {
    Path = bfs::path("..");
    ArrPath.emplace_back(Path);
  }
}

std::ostream& operator<<(std::ostream& out, const BoostSort& B) {
  for (const auto& item : B.AccountNames) {
    std::vector<bfs::path> buff;
    for (const auto& it : B.ArrPath) {
      if (item == it.stem().string().substr(8, 8)) {
        buff.emplace_back(it);
      }
    }
    bfs::path TimeMax = buff[0];
    size_t n = 0;
    for (const bfs::path& it : buff) {
      if (TimeMax.stem().string().substr(TimePos, TimeLength) <
          it.stem().string().substr(TimePos, TimeLength)) {
        TimeMax = it;
      }
      n++;
    }
    out << B.PrintAcc(TimeMax, n).str() << std::endl;
  }
  return out;
}

std::stringstream BoostSort::PrintAcc(const bfs::path& _path,
                                      const size_t& n) const {
  std::stringstream ss;
  ss << "broker: " << std::left << std::setw(8)
     << _path.parent_path().filename().string()
     << " account: " << _path.stem().string().substr(8, 8)
     << " files: " << std::setw(3) << n
     << " lastdate: " << _path.stem().string().substr(TimePos, 4) << "."
     << _path.stem().string().substr(TimePos + 4, 2) << "."
     << _path.stem().string().substr(TimePos + 6, 2);
  return ss;
}

const bfs::path& BoostSort::GetPath(const size_t& n) const {
  return ArrPath.at(n);
}
