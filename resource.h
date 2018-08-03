// Modified from the version of Resource.h in thirdparty/embed-resource.

#pragma once
#include <string>
#include <cstddef>

class Resource {
public:
    Resource(const char *start, const size_t len) : resource_data(start), data_len(len) {}

    const char *const & data() const { return resource_data; }
    const size_t & size() const { return data_len; }

    const char *begin() const { return resource_data; }
    const char *end() const { return resource_data + data_len; }

    std::string toString() const { return std::string(data(), size()); }

private:
    const char *const resource_data;
    const size_t data_len;
};

#define DECLARE_RESOURCE(name) \
    extern "C" const char _resource_##name[]; \
    extern "C" const size_t _resource_##name##_len; \
    const static Resource name(_resource_##name, _resource_##name##_len)
