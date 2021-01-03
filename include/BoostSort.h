// Copyright 2020 Avackimyanc Levon levon.avakimyanc.01@mail.ru

#ifndef INCLUDE_BOOSTSORT_H_
#define INCLUDE_BOOSTSORT_H_
#include <algorithm>
#include <boost/filesystem.hpp>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
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
  const bfs::path& getPath() const;
  void DirectoriesPass(const bfs::path&);
  void DirectoryEvent(const bfs::path&);
  void FileEvent(const bfs::path&);
  FileEx ConstructFile(std::string);
  void printAllFiles(std::ostream&);
  void PrintAllInformation(std::ostream&);
  ~BoostSort();

 private:
  bfs::path Path;
  std::vector<std::string> DirectoriesArr;
  std::map<size_t, std::vector<FileEx>> AccountParams;
  std::vector<FileEx> FilesArr;
};

#endif  // INCLUDE_BOOSTSORT_H_
