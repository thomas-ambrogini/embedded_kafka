#include "MyChildClass.hpp"

void MyChildClass::to_json(nlohmann::json& j) const {
  j = nlohmann::json{{"name", name}, {"age", age}};
}

void to_json(nlohmann::json& j, const MyChildClass& child) {
  child.to_json(j);
}
