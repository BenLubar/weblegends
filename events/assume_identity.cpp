#include "../helpers_event.h"

#include "df/history_event_assume_identityst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_assume_identityst *event)
{
    auto trickster = df::historical_figure::find(event->trickster);
    auto identity = df::identity::find(event->identity);
    auto target = df::historical_entity::find(event->target);

    event_link(s, context, trickster);
    s << " tricked ";
    event_link(s, context, target);
    s << " into thinking ";

    BEFORE_SWITCH(sex, trickster ? trickster->sex : -1);
    switch (sex)
    {
    case -1:
        s << "it";
        BREAK(sex);
    case 0:
        s << "she";
        BREAK(sex);
    case 1:
        s << "he";
        BREAK(sex);
    }
    AFTER_SWITCH(sex, stl_sprintf("event-%d (ASSUME_IDENTITY)", event->id));

    s << " was ";
    do_identity(s, context, trickster, identity);
}
