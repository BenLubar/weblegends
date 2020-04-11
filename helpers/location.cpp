#include "../helpers_event.h"

void do_location(std::ostream & s, const event_context & context, int32_t site, int32_t region, int32_t layer, int32_t structure, std::string separator, bool force)
{
    if (auto loc = df::world_site::find(site))
    {
        if (auto bld = binsearch_in_vector(loc->buildings, structure))
        {
            if (bld != context.structure || force)
            {
                s << separator;
                link(s, bld);
                separator = " in ";
            }
        }

        if (loc != context.site || force)
        {
            s << separator;
            link(s, loc);
            separator = " in ";
        }
    }

    if (auto loc = df::world_region::find(region))
    {
        if (loc != context.region || force)
        {
            s << separator;
            link(s, loc);
            separator = " in ";
        }
    }

    if (auto loc = df::world_underground_region::find(layer))
    {
        if (loc != context.layer || force)
        {
            s << separator;
            link(s, loc);
            separator = " in ";
        }
    }
}
