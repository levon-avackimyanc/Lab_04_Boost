//
// Copyright 2020 Avackimyanc Levon levon.avakimyanc.01@mail.ru
//

#ifndef INCLUDE_BOOST_BOOSTSORT_HPP
#define INCLUDE_BOOST_BOOSTSORT_HPP

#include <algorithm>
#include <boost/filesystem.hpp>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace bfs = boost::filesystem;

const char Dot = '.';
const char UnderScore = '_';
const char OldExt[] = ".old";
const char CorrExt[] = ".txt";

struct Time {
  unsigned int year;
  unsigned int month;
  unsigned int day;
};

struct FileEx {
  std::string Name;
  std::string BrokerName;
  std::string Type;
  size_t PersonalAccount;
  Time Date;
  std::string Extension;
};

bool Compare(const FileEx&, const FileEx&);
std::ostream& operator<<(std::ostream&, const Time&);

class BoostSort {
 public:
  explicit BoostSort(const bfs::path& path);
  [[nodiscard]] const bfs::path& getPath() const;
  void DirectoriesPass(const bfs::path&);
  void DirectoryEvent(const bfs::path&);
  void StartParsing();
  void FileEvent(const bfs::path&);
  FileEx ConstructFile(std::string);
  void printAllFiles(std::ostream&);
  void PrintAllInformation(std::ostream&);
  ~BoostSort();

 private:
  bfs::path Path;
  std::vector<std::string> DirectoriesArr;
  std::map<size_t, std::vector<FileEx>> Accounts;
  std::vector<FileEx> FilesArr;
};


#endif  // INCLUDE_BOOST_BOOSTSORT_HPP
