#ifndef CONFIG_HPP_IN_H
#define CONFIG_HPP_IN_H

#include <tuple>

#define MB_VERSION_MAJOR 0
#define MB_VERSION_MINOR 4
#define MB_VERSION_PATCH 5
#define MB_VERSION_SUFFIX "-dev+gc60e200"
#define MB_GIT_COMMIT "c60e200"
#define MB_VERSION "0.4.5-dev+gc60e200"

namespace mb {
    inline const char* getVersionString() {
        return MB_VERSION;
    }

    inline const char* getGitCommit() {
        return MB_GIT_COMMIT;
    }

    inline constexpr std::tuple<int, int, int> getVersionTuple() {
        return { MB_VERSION_MAJOR, MB_VERSION_MINOR, MB_VERSION_PATCH };
    }

    inline constexpr bool isVersionAtLeast(int major, int minor, int patch) {
        return std::tuple(MB_VERSION_MAJOR, MB_VERSION_MINOR, MB_VERSION_PATCH)
             >= std::tuple(major, minor, patch);
    }
} // namespace mb



#endif //CONFIG_HPP_IN_H
