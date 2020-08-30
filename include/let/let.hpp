#ifndef LET_HPP_DAA4C60A_8CFF_431A_AAFA_3B488B710CA0
#define LET_HPP_DAA4C60A_8CFF_431A_AAFA_3B488B710CA0
#pragma once

#include <type_traits>

namespace deep_const
{
template<typename T, typename = void>
struct recursive_const;

// Recurse on pointers
template<typename T>
struct recursive_const<
  T, 
  std::enable_if_t<
    std::is_pointer_v<T>
  >
> 
{
  using type = const typename recursive_const<std::remove_pointer_t<T>>::type* const;
};

// Recurse on references
template<typename T>
struct recursive_const<
  T, 
  std::enable_if_t<
    std::is_reference_v<T>
  >
> 
{
  using type = const typename recursive_const<std::remove_reference_t<T>>::type&;
};

// Normal types
template<typename T>
struct recursive_const<
  T, 
  std::enable_if_t<
    !std::is_pointer_v<T> && !std::is_reference_v<T>
  >
> 
{
  using type = const T;
};

// Utility alias
template<typename T> 
using recursive_const_t = typename recursive_const<T>::type;

template<typename T>
struct impl
{
  recursive_const_t<T> ref;
  constexpr impl(const T* const ref) noexcept: ref{ref} { }    
  constexpr auto operator->() const noexcept { return ref; }  
};
template<typename T>
impl(const T* const) -> impl<T>;
}

// Usage: let x = get_some_pointer();
#define let deep_const::impl
#endif 
