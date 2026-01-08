# ---------------------------------------------------------------------------
# collect sources and headers
# ---------------------------------------------------------------------------
file(GLOB SRC_FILES *.c)
file(GLOB HDR_FILES *.h)

# export include dir
set(EXPORT_DIR ${CMAKE_CURRENT_BINARY_DIR}/libs)
file(MAKE_DIRECTORY ${EXPORT_DIR})

foreach(HDR IN LISTS HDR_FILES)
    get_filename_component(HDR_NAME ${HDR} NAME)
    configure_file(${HDR} ${EXPORT_DIR}/${HDR_NAME} COPYONLY)
endforeach()

add_library(libs_pid_pd INTERFACE)

target_include_directories(libs_pid_pd INTERFACE ${EXPORT_DIR})

target_sources(libs_pid_pd INTERFACE ${SRC_FILES})

# link default libraries
target_link_libraries(libs_pid_pd INTERFACE m)
