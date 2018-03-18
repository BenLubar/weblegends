#pragma once

#define WEBLEGENDS_DEBUG

#ifdef WEBLEGENDS_DEBUG

#define WEBLEGENDS_DEBUG_LOG weblegends_debug_log()

std::ostream & weblegends_debug_log();
void weblegends_debug_close_log();

template<typename E>
struct weblegends_switch_debug_enum_base
{
    weblegends_switch_debug_enum_base(E var) : var(var) {}
    E var;
};

template<typename E>
class weblegends_extract_enum
{
public:
    typedef typename std::enable_if<std::is_scalar<E>::value, E>::type type;
};
template<typename E, typename I>
class weblegends_extract_enum<df::enum_field<E, I>>
{
public:
    typedef E type;
};

template<typename E>
struct weblegends_switch_debug_enum : public weblegends_switch_debug_enum_base<typename weblegends_extract_enum<E>::type>
{
    weblegends_switch_debug_enum(E var) : weblegends_switch_debug_enum_base<typename weblegends_extract_enum<E>::type>(var) {}
};

template<typename E>
inline typename std::ostream & operator<<(std::ostream & s, const weblegends_switch_debug_enum_base<E> & e)
{
    return s << typeid(e.var).name() << "(" << int64_t(e.var) << ")";
}

template<typename E>
inline typename std::enable_if<std::is_same<typename df::enum_traits<E>::enum_type, E>::value, std::ostream &>::type operator<<(std::ostream & s, const weblegends_switch_debug_enum<E> e)
{
    return s << df::identity_traits<E>::get()->getName() << "(" << enum_item_key(e.var) << ")";
}

template<typename E, typename I>
inline typename std::enable_if<std::is_same<typename df::enum_traits<E>::enum_type, E>::value, std::ostream &>::type operator<<(std::ostream & s, const weblegends_switch_debug_enum<df::enum_field<E, I>> e)
{
    return s << df::identity_traits<E>::get()->getName() << "(" << enum_item_key(e.var) << ")";
}

inline constexpr const char *weblegends_basename(const char *p1, const char *p2)
{
    // https://gist.github.com/rsms/a5fa779736ea4932be91
    return *p2 == '\0' ? p1 : *p2 == '/' || *p2 == '\\' ? weblegends_basename(p2 + 1, p2 + 1) : weblegends_basename(p1, p2 + 1);
}

#define BEFORE_SWITCH(var, expr) \
{ \
    auto var = expr; \
    try \
    { \
        bool var##_found = false

#define BREAK(var) \
    var##_found = true; \
    break

#define AFTER_SWITCH(var, message) \
        if (!var##_found) \
        { \
            weblegends_debug_log() << "[weblegends] [" << weblegends_basename(__FILE__, __FILE__) << ":" << __LINE__ << "] missing enum-item: " << weblegends_switch_debug_enum<decltype(var)>(var) << ": " << (message) << std::endl; \
        } \
    } \
    catch (...) \
    { \
        weblegends_debug_log() << "[weblegends] [" << weblegends_basename(__FILE__, __FILE__) << ":" << __LINE__ << "] exception in switch: " << weblegends_switch_debug_enum<decltype(var)>(var) << ": " << (message) << std::endl; \
        throw; \
    } \
}

#define ASSUME_EQUAL(actual, expected, message) \
if ((actual) != (expected)) \
{ \
    typedef typename std::remove_reference<decltype((actual))>::type T; \
    weblegends_debug_log() << "[weblegends] [" << weblegends_basename(__FILE__, __FILE__) << ":" << __LINE__ << "] expected " << weblegends_switch_debug_enum<T>((actual)) << " to equal " << weblegends_switch_debug_enum<T>(static_cast<T>((expected))) << ": " << (message) << std::endl; \
}

#define UNEXPECTED(message) \
    weblegends_debug_log() << "[weblegends] [" << weblegends_basename(__FILE__, __FILE__) << ":" << __LINE__ << "] " << (message) << std::endl;

#else

#define WEBLEGENDS_DEBUG_LOG std::cerr
#define BEFORE_SWITCH(var, expr) { auto var = expr
#define BREAK(var) break
#define AFTER_SWITCH(var, message) }
#define ASSUME_EQUAL(actual, expected, message)
#define UNEXPECTED(message)

#endif
