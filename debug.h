#pragma once

#define SWITCH(var, expr) \
{ \
    auto var = expr; \
	try \
    { \
        bool var##_found = false; \
        switch (var)

#define BREAK(var) \
    var##_found = true; \
    break

#define END_SWITCH(var, message) \
        if (!var##_found) \
        { \
            std::cerr << "[weblegends] missing enum-item: " << typeid(var).name() << "(" << int32_t(var) << "): " << (message) << std::endl; \
        } \
    } \
	catch (...) \
	{ \
		std::cerr << "[weblegends] exception in switch: " << typeid(var).name() << "(" << int32_t(var) << "): " << (message) << std::endl; \
		throw; \
	} \
}
