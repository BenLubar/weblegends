#include "../helpers_event.h"

#include "df/art_image.h"
#include "df/art_image_chunk.h"
#include "df/history_event_masterpiece_created_engravingst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_masterpiece_created_engravingst *event)
{
    auto maker = df::historical_figure::find(event->maker);
    auto maker_entity = df::historical_entity::find(event->maker_entity);
    auto site = df::world_site::find(event->site);
    auto art_chunk = df::art_image_chunk::find(event->art_id);
    auto art = art_chunk ? art_chunk->images[event->art_subid] : nullptr;

    event_link(s, context, maker);
    s << " created a masterful engraving";
    if (art)
    {
        s << " <em>";
        name_translated(s, art->name);
        s << "</em>";
    }

    if (maker_entity)
    {
        s << " for ";
        event_link(s, context, maker_entity);
    }

    if (site)
    {
        s << " at ";
        event_link(s, context, site);
    }
}
