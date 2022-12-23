#include <iterator>
#include <cmath>
#include <cassert>

template<typename T>
class ReverseView {
  using category = typename T::iterator::iterator_category;
  static_assert(std::is_same_v<category, std::bidirectional_iterator_tag>
      || std::is_same_v<category, std::random_access_iterator_tag>,
      "ReverseView is only available for containters with bidirectional "
      "iterators.");

public:
  ReverseView(T& t) : t_(t) {}

  auto begin() const {
    return t_.rbegin();
  }

  auto end() const {
    return t_.rend();
  }

private:
  T& t_;
};

template<typename... Args>
inline auto reversed(Args&&... args) {
  return ReverseView(std::forward<Args>(args)...);
}

