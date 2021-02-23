#include "../helpers_event.h"

#include "df/history_event_entity_lawst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_entity_lawst *event)
{
    event_link(s, context, df::historical_figure::find(event->histfig));

    if (event->add_flags.bits.harsh && !event->remove_flags.bits.harsh)
    {
        s << " imposed numerous harsh laws on ";
    }
    else if (!event->add_flags.bits.harsh && event->remove_flags.bits.harsh)
    {
        s << " lifted numerous harsh laws from ";
    }
    else
    {
        do_event_missing(s, context, event, __FILE__, __LINE__);
    }

    event_link(s, context, df::historical_entity::find(event->entity));
}
