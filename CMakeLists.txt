cmake_minimum_required(VERSION 3.16)

project(digistoapp VERSION 0.2.3 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS
    Core
    Quick
    Widgets
    WebView
)

qt_standard_project_setup()

set(CMAKE_AUTORCC ON)

set(SOURCES
    src/main.cpp
    resources.qrc
    src/globals.h
    src/dscontroller.cpp src/dscontroller.h
    src/requests.cpp src/requests.h
    src/qaesencryption.h src/qaesencryption.cpp

    src/permissionmanager.h src/permissionmanager.cpp
    src/singleinstanceguard.h src/singleinstanceguard.cpp
    src/mb/mantisbaseimpl.h src/mb/mantisbaseimpl.cpp
)

if (WIN32)
    set(APP_ICON_RESOURCE_FILES icon.rc)
    list(APPEND SOURCES ${APP_ICON_RESOURCE_FILES})
endif()

qt_add_executable(digisto ${SOURCES}
    src/mb/checkout.cpp
    src/mb/dashboard.cpp
    src/mb/organization.cpp
    src/mb/supply.cpp)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(digisto PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER app.digisto
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# MantisBase dependency for digisto
add_subdirectory(3rdParty/mantisbase)

target_link_libraries(digisto
    PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Widgets
    Qt6::WebView
    mb::static
)

include(GNUInstallDirs)
install(TARGETS digisto
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
