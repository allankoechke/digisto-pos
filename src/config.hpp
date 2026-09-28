#ifndef CONFIG_HPP_IN
#define CONFIG_HPP_IN

#include <tuple>

#define DIGISTO_VERSION_MAJOR 0
#define DIGISTO_VERSION_MINOR 3
#define DIGISTO_VERSION_PATCH 0
#define DIGISTO_VERSION "0.3.0"

inline const char* getVersionString() {
    return DIGISTO_VERSION;
}

inline constexpr std::tuple<int, int, int> getVersionTuple() {
    return { DIGISTO_VERSION_MAJOR, DIGISTO_VERSION_MINOR, DIGISTO_VERSION_PATCH };
}

inline constexpr bool isVersionAtLeast(int major, int minor, int patch) {
    return std::tuple(DIGISTO_VERSION_MAJOR, DIGISTO_VERSION_MINOR, DIGISTO_VERSION_PATCH)
         >= std::tuple(major, minor, patch);
}

#endif // CONFIG_HPP_IN
