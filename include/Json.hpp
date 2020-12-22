// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_JSON_HPP_
#define INCLUDE_JSON_HPP_

#include <ctime>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

using json = nlohmann::json;

class Json {
 public:
  void addHash(const std::string& data, const std::string& hash,
               std::time_t timestamp);
  friend std::ostream& operator<<(std::ostream& out, const Json& j);

 private:
  mutable std::mutex mut;
  json jArray;
};
#endif  // INCLUDE_JSON_HPP_
