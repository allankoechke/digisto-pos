# Version companion for MantisBaseConfig.cmake (find_package version matching).
#
# 0.4.5-beta.1 is the full release string (e.g. "0.4.3" or "0.4.3-rc.1").
# Compatibility is decided on the numeric major.minor.patch triple so that a
# prerelease suffix never poisons the comparison; EXACT requests still compare
# the full string. Requested versions must be plain numeric dotted versions,
# e.g. find_package(MantisBase 0.4 REQUIRED).
set(PACKAGE_VERSION "0.4.5-beta.1")
set(_MB_PKG_TRIPLE "0.4.5")
set(_MB_PKG_MAJOR "0")
set(_MB_PKG_MINOR "4")

if(PACKAGE_VERSION VERSION_EQUAL PACKAGE_FIND_VERSION)
    set(PACKAGE_VERSION_EXACT TRUE)
endif()

if(NOT PACKAGE_FIND_VERSION)
    # No version requested: any version is compatible.
    set(PACKAGE_VERSION_COMPATIBLE TRUE)
elseif(_MB_PKG_TRIPLE VERSION_LESS PACKAGE_FIND_VERSION)
    set(PACKAGE_VERSION_COMPATIBLE FALSE)
elseif(_MB_PKG_MAJOR GREATER 0)
    # >= 1.0 (semver): same major version is compatible.
    if(PACKAGE_FIND_VERSION_MAJOR EQUAL _MB_PKG_MAJOR)
        set(PACKAGE_VERSION_COMPATIBLE TRUE)
    else()
        set(PACKAGE_VERSION_COMPATIBLE FALSE)
    endif()
else()
    # 0.x (semver: anything may break): major AND minor must match.
    if(PACKAGE_FIND_VERSION_MAJOR EQUAL _MB_PKG_MAJOR
       AND PACKAGE_FIND_VERSION_MINOR EQUAL _MB_PKG_MINOR)
        set(PACKAGE_VERSION_COMPATIBLE TRUE)
    else()
        set(PACKAGE_VERSION_COMPATIBLE FALSE)
    endif()
endif()

unset(_MB_PKG_TRIPLE)
unset(_MB_PKG_MAJOR)
unset(_MB_PKG_MINOR)
