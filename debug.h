#pragma once

#define WEBLEGENDS_DEBUG

#ifdef WEBLEGENDS_DEBUG

template<typename E>
struct weblegends_switch_debug_enum_base
{
	weblegends_switch_debug_enum_base(E var) : var(var) {}
	E var;
};

template<typename E>
struct weblegends_switch_debug_enum : public weblegends_switch_debug_enum_base<E>
{
	weblegends_switch_debug_enum(E var) : weblegends_switch_debug_enum_base<E>(var) {}
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
            std::cerr << "[weblegends] [" << __FILE__ << ":" << __LINE__ << "] missing enum-item: " << weblegends_switch_debug_enum<decltype(var)>(var) << ": " << (message) << std::endl; \
        } \
    } \
	catch (...) \
	{ \
		std::cerr << "[weblegends] [" << __FILE__ << ":" << __LINE__ << "] exception in switch: " << weblegends_switch_debug_enum<decltype(var)>(var) << ": " << (message) << std::endl; \
		throw; \
	} \
}

#define ASSUME_EQUAL(actual, expected, message) \
if ((actual) != (expected)) \
{ \
	typedef typename std::remove_reference<decltype((actual))>::type T; \
	std::cerr << "[weblegends] [" << __FILE__ << ":" << __LINE__ << "] expected " << weblegends_switch_debug_enum<T>((actual)) << " to equal " << weblegends_switch_debug_enum<T>(static_cast<T>((expected))) << ": " << (message) << std::endl; \
}

#else

#define BEFORE_SWITCH(var, expr) { auto var = expr
#define BREAK(var) break
#define AFTER_SWITCH(var, message) }
#define ASSUME_EQUAL(actual, expected, message)

#endif
