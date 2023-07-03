#include "MyClass.hpp"

void MyClass::to_json(nlohmann::json& j) const {
  j = nlohmann::json{{"parentName", parentName}, {"children", children}};
}

void to_json(nlohmann::json& j, const MyClass& obj) {
  obj.to_json(j);
}
