#ifndef CONFIG_HPP_IN
#define CONFIG_HPP_IN

#define DIGISTO_VERSION_MAJOR 0
#define DIGISTO_VERSION_MINOR 2
#define DIGISTO_VERSION_PATCH 3
#define DIGISTO_VERSION "0.2.3"

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
