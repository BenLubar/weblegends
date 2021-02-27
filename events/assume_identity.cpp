#include "../helpers_event.h"

#include "df/history_event_assume_identityst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_assume_identityst *event)
{
    auto trickster = df::historical_figure::find(event->trickster);
    auto identity = df::identity::find(event->identity);
    auto target = df::historical_entity::find(event->target);

    event_link(s, context, trickster);

    if (event->target == -1)
    {
        s << " assumed the identity of ";
    }
    else
    {
        s << " tricked ";
        event_link(s, context, target);
        s << " into thinking ";

        if (auto pronoun = trickster ? ENUM_ATTR(pronoun_type, subject, trickster->sex) : nullptr)
            s << pronoun << " was ";
        else
            s << " they were ";
    }

    do_identity(s, context, trickster, identity);
}
