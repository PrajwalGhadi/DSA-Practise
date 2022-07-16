#include <string_view>
#include <type_traits>

#define between(a, b, c) ((a >= b) && (a <= c - 1))

#define REP(x, y) \
  for (typename std::remove_cv<typename std::remove_reference<decltype(y)>::type>::type x = 0; x <= (y); x++)

#define REPL(x, y, z) \
  for (typename std::remove_cv<typename std::remove_reference<decltype(y)>::type>::type x = y; x <= (z); x++)

#define REPD(x, y, z) \
  for (typename std::remove_cv<typename std::remove_reference<decltype(y)>::type>::type x = y; x >= (z); x--)

template <typename T>
constexpr auto type_name() {
  std::string_view name, prefix, suffix;
#ifdef __clang__
  name = __PRETTY_FUNCTION__;
  prefix = "auto type_name() [T = ";
  suffix = "]";
#elif defined(__GNUC__)
  name = __PRETTY_FUNCTION__;
  prefix = "constexpr auto type_name() [with T = ";
  suffix = "]";
#elif defined(_MSC_VER)
  name = __FUNCSIG__;
  prefix = "auto __cdecl type_name<";
  suffix = ">(void)";
#endif
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;
}

template <typename T>
inline bool update_min(T& dest, const T& val) {
  if (val < dest) {
    dest = val;
    return true;
  }
  return false;
}

template <typename T>
inline bool update_max(T& dest, const T& val) {
  if (dest < val) {
    dest = val;
    return true;
  }
  return false;
}