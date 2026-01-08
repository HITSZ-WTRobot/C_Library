# ---------------------------------------------------------------------------
# collect sources and headers
# ---------------------------------------------------------------------------
file(GLOB SRC_FILES *.c)
file(GLOB HDR_FILES *.h)

# export include dir
set(EXPORT_DIR ${CMAKE_CURRENT_BINARY_DIR}/include)
file(MAKE_DIRECTORY ${EXPORT_DIR})

foreach(HDR IN LISTS HDR_FILES)
    get_filename_component(HDR_NAME ${HDR} NAME)
    configure_file(${HDR} ${EXPORT_DIR}/libs/${HDR_NAME} COPYONLY)
endforeach()

add_library(libs_pid_pd STATIC ${SRC_FILES})

target_include_directories(libs_pid_pd PUBLIC ${EXPORT_DIR})

# link default libraries
target_link_libraries(libs_pid_pd PUBLIC m)
