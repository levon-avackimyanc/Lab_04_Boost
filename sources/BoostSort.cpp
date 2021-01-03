// Copyright 2020 Avackimyanc Levon levon.avakimyanc.01@mail.ru

#include "BoostSort.h"

#include <iomanip>

const int ZeroPosition = 0;
const int PathMoveOne = 1;

bool Compare(const FileEx& F1, const FileEx& F2) {
  return std::make_tuple(F1.Date.year, F1.Date.month, F1.Date.day) <
         std::make_tuple(F2.Date.year, F2.Date.month, F2.Date.year);
}

std::ostream& operator<<(std::ostream& out, const Time& Date) {
  out << Date.year << Dot << Date.month << Dot << Date.day;
  return out;
}

BoostSort::BoostSort(const bfs::path& path) {
  if (path.empty()) {
    Path = bfs::path{".."};
  } else {
    Path = path;
  }
}

void BoostSort::PrintAllInformation(std::ostream& out) {
  for (const auto& Acc : AccountParams) {
    out << "broker: " << Acc.second[0].BrokerName;
    out << " account: " << std::setw(8) << std::setfill('0') << Acc.first;
    out << " files: " << Acc.second.size();
    out << " lastdate: "
        << std::max_element(Acc.second.begin(), Acc.second.end(), Compare)->Date
        << std::endl;
  }
}

void BoostSort::DirectoriesPass(const bfs::path& path) {
  if (bfs::exists(path)) {
    for (const bfs::directory_entry& ph : bfs::directory_iterator{path}) {
      if (bfs::is_directory(ph)||bfs::is_symlink(ph)) {
        DirectoryEvent(ph);
      } else if (bfs::is_regular_file(ph)) {
        FileEvent(ph);
      }
    }
    if (!DirectoriesArr.empty()) {
      DirectoriesArr.pop_back();
    }
  }
}

void BoostSort::DirectoryEvent(const bfs::path& path) {
  DirectoriesArr.push_back(path.stem().string());
  DirectoriesPass(path);
}

FileEx BoostSort::ConstructFile(std::string filename) {
  FileEx ResFile;

  ResFile.Name = filename;

  ResFile.Type = filename.substr(ZeroPosition, filename.find(UnderScore));
  filename = filename.substr(filename.find(UnderScore) + PathMoveOne);

  ResFile.PersonalAccount =
      std::stoi(filename.substr(ZeroPosition, filename.find(UnderScore)));
  filename = filename.substr(filename.find(UnderScore) + PathMoveOne);

  ResFile.Date.year = std::stoi(filename.substr(ZeroPosition, 4));
  ResFile.Date.month = std::stoi(filename.substr(4, 2));
  ResFile.Date.day = std::stoi(filename.substr(6, 2));
  filename = filename.substr(UnderScore + PathMoveOne);

  if (filename[0] != Dot || filename.substr(0, 4) == OldExt) {
    throw std::exception();
  } else if (filename.substr(1).find(Dot) != std::string::npos) {
    throw std::exception();
  }
  if (filename != CorrExt) {
    throw std::exception();
  }
  ResFile.Extension = filename;
  return ResFile;
}

void BoostSort::FileEvent(const bfs::path& FilePath) {
  FileEx File = ConstructFile(FilePath.filename().string());
  File.BrokerName = DirectoriesArr.back();
  FilesArr.emplace_back(File);
  AccountParams[File.PersonalAccount].emplace_back(File);
}

void BoostSort::printAllFiles(std::ostream& out) {
  for (const auto& file : FilesArr) out << file.BrokerName << " " << file.Name << '\n';
}

const bfs::path& BoostSort::getPath() const { return Path; }

BoostSort::~BoostSort() = default;
