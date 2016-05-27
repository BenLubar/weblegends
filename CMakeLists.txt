PROJECT (weblegends)

SET(PROJECT_SRCS
    weblegends.cpp
    server.cpp
    http.cpp
    helpers.cpp
    helpers_content.cpp
    helpers_event.cpp
    render_home.cpp
    render_entity.cpp
    render_figure.cpp
    render_item.cpp
    render_region.cpp
    render_site.cpp
    render_structure.cpp
    render_layer.cpp
    render_list.cpp
)

SET(PROJECT_HDRS
    weblegends.h
    helpers.h
    debug.h
)

SET_SOURCE_FILES_PROPERTIES( ${PROJECT_HDRS} PROPERTIES HEADER_FILE_ONLY TRUE)

LIST(APPEND PROJECT_SRCS ${PROJECT_HDRS})

LIST(APPEND PROJECT_LIBS clsocket dfhack-tinythread)

DFHACK_PLUGIN(weblegends ${PROJECT_SRCS} LINK_LIBRARIES ${PROJECT_LIBS} COMPILE_FLAGS_GCC "-Wall -Wextra -Werror" COMPILE_FLAGS_MSVC "/W3")
