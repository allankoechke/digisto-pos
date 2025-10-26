# option(MANTIS_EMBEDDED "MantisApp embedded in the client application" OFF)

target_include_directories(digisto
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/mantis/include
)

target_link_libraries(digisto
    PRIVATE mantis
)
