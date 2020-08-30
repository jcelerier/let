#include <let/let.hpp>

static_assert(
  std::is_same_v<
    int const, 
    deep_const::recursive_const_t<int>
  >);
static_assert(
  std::is_same_v<
    int const *const, 
    deep_const::recursive_const_t<int*>
  >);
static_assert(
  std::is_same_v<
    int const &, 
    deep_const::recursive_const_t<int&>
  >);
static_assert(
  std::is_same_v<
    int const *const *const, 
    deep_const::recursive_const_t<int**>
  >);
static_assert(
  std::is_same_v<
    int const *const &, 
    deep_const::recursive_const_t<int*&>
  >);

int main() { }