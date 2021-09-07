#include <iterator>
#include <cmath>
#include <cassert>

template<typename T> class ArangeIterator;

template<typename T>
inline auto get_num_values(const T& start, const T& stop, const T& step) {
  const auto zero = static_cast<T>(0);
  assert(stop != zero);
  if (stop > start) {
    assert(step > zero);
  } else if (stop < start) {
    assert(step < zero);
  }
  return static_cast<size_t>(ceil((stop - start) / step));
}

template<typename T>
inline constexpr T get_default_step() {
  return static_cast<T>(1);
}

template<typename T>
class Arange {
  using iterator = ArangeIterator<T>;
public:
  using value_type = T;

  Arange(T start, T stop, T step=get_default_step<T>()): start_(start), step_(step),
  num_values_(get_num_values(start_, stop, step_)) {}

  auto begin() const { return iterator{start_, step_, 0}; }
  auto end() const { return iterator{start_, step_, num_values_}; }

private:
  T start_;
  T step_;
  size_t num_values_;
};

template<typename T>
class ArangeIterator {
public:
  using different_type = size_t;
  using value_type = T;
  using reference = T;
  using pointer = void;
  using iterator_category = std::forward_iterator_tag;

  ArangeIterator(T start, T step, size_t index) : start_(start), step_(step),
  index_(index) {}

  auto operator==(const ArangeIterator& other) const { return index_ == other.index_; }
  auto operator!=(const ArangeIterator& other) const { return !(*this == other); }

  auto operator++() { ++index_; return *this; }
  auto operator*() const { return start_ + index_ * step_; }

private:
  size_t index_;
  T start_, step_;
};

template<typename... Args>
auto make_arange(Args&&... args) {
  return Arange(std::forward<Args>(args)...);
}

