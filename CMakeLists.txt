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

file(READ ../../library/xml/df.history.xml EVENT_TYPES)
string(REGEX MATCH "<enum-type type-name='history_event_type'(<[^/]|[^<])*</enum-type>" EVENT_TYPES "${EVENT_TYPES}")
string(REGEX MATCHALL "<enum-item[^>]* name='[^']*" EVENT_TYPES "${EVENT_TYPES}")
string(REGEX REPLACE "[^;']*'" "" EVENT_TYPES "${EVENT_TYPES}")

set(EVENT_HEADER_1 "#pragma once\n\n")
set(EVENT_HEADER_2 "\n#define EVENT_TYPES")

foreach(EVENT_TYPE IN LISTS EVENT_TYPES)
    string(TOLOWER "${EVENT_TYPE}" EVENT_TYPE_LOWER)
    string(APPEND EVENT_HEADER_1 "#include \"df/history_event_${EVENT_TYPE_LOWER}st.h\"\n")
    string(APPEND EVENT_HEADER_2 " \\\n    EVENT_TYPE(${EVENT_TYPE}, ${EVENT_TYPE_LOWER})")

    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/events/${EVENT_TYPE_LOWER}.cpp")
        file(WRITE "events/${EVENT_TYPE_LOWER}.cpp" "#include \"../helpers_event.h\"\n\n#include \"df/history_event_${EVENT_TYPE_LOWER}st.h\"\n\nvoid do_event(std::ostream & s, const event_context & context, df::history_event_${EVENT_TYPE_LOWER}st *event)\n{\n    // TODO\n    do_event_missing(s, context, event, __FILE__, __LINE__);\n}\n")
    endif()
endforeach()

file(WRITE events.h "${EVENT_HEADER_1}${EVENT_HEADER_2}\n")

add_subdirectory(thirdparty/embed-resource EXCLUDE_FROM_ALL)

SET(PROJECT_SRCS
    weblegends.cpp
    server.cpp
    http.cpp
    export.cpp
    layout.cpp
    map.cpp
    helpers.cpp
    render_home.cpp
    render_entity.cpp
    render_era.cpp
    render_eventcol.cpp
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
    helpers_event.h
    debug.h
    resource.h
    events.h
    weblegends-plugin.h
    weblegends-git-describe.h
)

SET(HELPERS_SRCS
    helpers/circumstance.cpp
    helpers/event.cpp
    helpers/identity.cpp
    helpers/item.cpp
    helpers/knowledge.cpp
    helpers/location.cpp
    helpers/population.cpp
    helpers/profession.cpp
    helpers/schedule.cpp
    helpers/value.cpp
    helpers/weapon.cpp
    helpers/written_content.cpp
)

FILE(GLOB EVENT_SRCS events/*.cpp)
LIST(APPEND PROJECT_SRCS ${HELPERS_SRCS} ${EVENT_SRCS})
source_group("Source Files\\helpers" FILES ${HELPERS_SRCS})
source_group("Source Files\\events" FILES ${EVENT_SRCS})

SET_SOURCE_FILES_PROPERTIES( ${PROJECT_HDRS} PROPERTIES HEADER_FILE_ONLY TRUE)

LIST(APPEND PROJECT_SRCS ${PROJECT_HDRS})

SET(PROJECT_EMBEDDED
    faux-wikipedia.css
)

EMBED_RESOURCES(PROJECT_EMBEDDED_SRCS ${PROJECT_EMBEDDED})

SET_SOURCE_FILES_PROPERTIES( ${PROJECT_EMBEDDED_SRCS} PROPERTIES GENERATED TRUE)

LIST(APPEND PROJECT_SRCS ${PROJECT_EMBEDDED_SRCS} ${PROJECT_EMBEDDED})

LIST(APPEND PROJECT_LIBS clsocket dfhack-tinythread dfhack-lodepng)

DFHACK_PLUGIN(weblegends ${PROJECT_SRCS} LINK_LIBRARIES ${PROJECT_LIBS} COMPILE_FLAGS_GCC "-Wall -Wextra -Werror" COMPILE_FLAGS_MSVC "/W3")
