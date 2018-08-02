PROJECT (weblegends)

execute_process(COMMAND ${GIT_EXECUTABLE} describe --tags --abbrev=8 --long
    WORKING_DIRECTORY "${weblegends_SOURCE_DIR}"
    OUTPUT_VARIABLE WEBLEGENDS_GIT_DESCRIPTION)
execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
    WORKING_DIRECTORY "${weblegends_SOURCE_DIR}"
    OUTPUT_VARIABLE WEBLEGENDS_GIT_COMMIT)
execute_process(COMMAND ${GIT_EXECUTABLE} describe --tags --abbrev=8 --exact-match
    WORKING_DIRECTORY "${weblegends_SOURCE_DIR}"
    RESULT_VARIABLE WEBLEGENDS_GIT_TAGGED_RESULT
    OUTPUT_QUIET ERROR_QUIET)

set(git_describe_tmp_h ${weblegends_SOURCE_DIR}/weblegends-git-describe.tmp.h)
set(git_describe_h ${weblegends_SOURCE_DIR}/weblegends-git-describe.h)

file(WRITE ${git_describe_tmp_h} "")

macro(git_describe_definition var)
    string(STRIP "${${var}}" GIT_DEF_VALUE)
    file(APPEND ${git_describe_tmp_h} "#define ${var} \"${GIT_DEF_VALUE}\"\n")
endmacro()

git_describe_definition(WEBLEGENDS_GIT_DESCRIPTION)
git_describe_definition(WEBLEGENDS_GIT_COMMIT)
if(${WEBLEGENDS_GIT_TAGGED_RESULT} EQUAL 0)
    file(APPEND ${git_describe_tmp_h} "#define WEBLEGENDS_GIT_TAGGED\n")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${git_describe_tmp_h} ${git_describe_h})

include_directories(thirdparty/embed-resource)
add_subdirectory(thirdparty/embed-resource EXCLUDE_FROM_ALL)

SET(PROJECT_SRCS
    weblegends.cpp
    server.cpp
    http.cpp
    helpers.cpp
    helpers_content.cpp
    helpers_event.cpp
    render_home.cpp
    render_entity.cpp
    render_era.cpp
    render_figure.cpp
    render_item.cpp
    render_region.cpp
    render_site.cpp
    render_structure.cpp
    render_layer.cpp
    render_list.cpp
    debug.cpp
)

SET(PROJECT_HDRS
    weblegends.h
    helpers.h
    debug.h
    weblegends-plugin.h
    weblegends-git-describe.h
)

SET_SOURCE_FILES_PROPERTIES( ${PROJECT_HDRS} PROPERTIES HEADER_FILE_ONLY TRUE)

LIST(APPEND PROJECT_SRCS ${PROJECT_HDRS})

SET(PROJECT_EMBEDDED
    style.css
)

EMBED_RESOURCES(PROJECT_EMBEDDED_SRCS ${PROJECT_EMBEDDED})

SET_SOURCE_FILES_PROPERTIES( ${PROJECT_EMBEDDED_SRCS} PROPERTIES GENERATED TRUE)

LIST(APPEND PROJECT_SRCS ${PROJECT_EMBEDDED_SRCS})

LIST(APPEND PROJECT_LIBS clsocket dfhack-tinythread)

DFHACK_PLUGIN(weblegends ${PROJECT_SRCS} LINK_LIBRARIES ${PROJECT_LIBS} COMPILE_FLAGS_GCC "-Wall -Wextra -Werror" COMPILE_FLAGS_MSVC "/W3")
