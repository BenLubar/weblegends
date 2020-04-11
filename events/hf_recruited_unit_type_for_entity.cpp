#include "../helpers_event.h"

#include "df/history_event_hf_recruited_unit_type_for_entityst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_recruited_unit_type_for_entityst *event)
{
    auto entity = df::historical_entity::find(event->entity);
    auto histfig = df::historical_figure::find(event->histfig);

    event_link(s, context, histfig);
    s << " recruited " << toLower(ENUM_ATTR(profession, caption, event->profession)) << "s into "; // XXX: plural
    event_link(s, context, entity);

    do_location(s, context, event);
}
