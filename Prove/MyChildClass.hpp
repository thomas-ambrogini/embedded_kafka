#ifndef MYCHILDCLASS_HPP
#define MYCHILDCLASS_HPP

#include <string>
#include "json.hpp"

class MyChildClass {
public:
  std::string name;
  int age;

  void to_json(nlohmann::json& j) const;
};

void to_json(nlohmann::json& j, const MyChildClass& child);

#endif // MYCHILDCLASS_HPP
