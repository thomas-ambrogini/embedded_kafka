#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <string>
#include <vector>
#include "json.hpp"
#include "MyChildClass.hpp"

class MyClass {
public:
  std::string parentName;
  std::vector<MyChildClass> children;

  void to_json(nlohmann::json& j) const;
};

void to_json(nlohmann::json& j, const MyClass& obj);

#endif // MYCLASS_HPP
