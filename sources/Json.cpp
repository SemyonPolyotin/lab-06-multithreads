// Copyright 2020 Your Name <your_email>

#include "Json.hpp"

void Json::addHash(const std::string& data, const std::string& hash,
                   std::time_t timestamp) {
  std::scoped_lock<std::mutex> lock(mut);
  std::stringstream rightData;
  rightData << std::hex << std::uppercase << std::stoi(data);
  json jAdd;
  jAdd["data"] = rightData.str();
  jAdd["hash"] = hash;
  jAdd["timestamp"] = timestamp;
  jArray.push_back(jAdd);
}
std::ostream& operator<<(std::ostream& out, const Json& j) {
  std::scoped_lock<std::mutex> lock(j.mut);
  out << j.jArray.dump(4);
  return out;
}
