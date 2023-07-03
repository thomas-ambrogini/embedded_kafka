#include <iostream>
#include "json.hpp"
#include "MyClass.hpp"

using json = nlohmann::json;

int main() {
  MyClass obj;
  obj.parentName = "Parent";

  MyChildClass child1;
  child1.name = "Child 1";
  child1.age = 10;

  MyChildClass child2;
  child2.name = "Child 2";
  child2.age = 8;

  obj.children.push_back(child1);
  obj.children.push_back(child2);

  json j = obj;

  std::cout << j.dump() << std::endl;

  return 0;
}
