//
// Copyright 2020 Avackimyanc Levon levon.avakimyanc.01@mail.ru
//

#ifndef INCLUDE_BOOST_BOOSTSORT_HPP
#define INCLUDE_BOOST_BOOSTSORT_HPP

#include <boost/filesystem.hpp>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace bfs = boost::filesystem;

class BoostSort {
 public:
  explicit BoostSort(const std::string& path);
  ~BoostSort() = default;

  const bfs::path& GetPath(const size_t& n) const;
  std::stringstream PrintAcc(const bfs::path& elem, const size_t& n) const;
  friend std::ostream& operator<<(std::ostream& out, const BoostSort& A);

 private:
  std::set<std::string> AccountNames;
  std::vector<bfs::path> ArrPath;
  bfs::path Path;
};

#endif  // INCLUDE_BOOST_BOOSTSORT_HPP
