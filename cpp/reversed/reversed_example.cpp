#include <iostream>
#include <vector>
#include <forward_list>

#include "reversed.h"

int main(void) {
  auto v = std::vector<int>{0, 1, 2, 3, 4};

  std::cout << "Vector: ";
  for (auto x : v) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  std::cout << "\nVector in reverse: ";
  for (auto x : reversed(v)) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  std::cout << "\nModify vector using reverse iterator.";
  for (auto& x : reversed(v)) {
    ++x;
  }

  std::cout << "\nVector after modification: ";
  for (auto x : v) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  // An attempt to use it on std::forward_list results in a compilation error.
  /*
   * auto l = std::forward_list<int>{1,2,3};
   * for (const auto& x : reversed(l))
   *   std::cout << x << " ";
   */

  return 0;
}

