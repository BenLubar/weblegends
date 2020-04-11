#include "../helpers_event.h"

#include "df/history_event_musical_form_createdst.h"
#include "df/musical_form.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_musical_form_createdst *event)
{
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
    }
    else
    {
        s << "An unknown musician";
    }
    s << " created ";
    if (auto form = df::musical_form::find(event->form))
    {
        s << "the musical form ";
        name_translated(s, form->name);
    }
    else
    {
        s << "[unknown musical form]";
    }
    do_location(s, context, event);
    do_circumstance_reason(s, context, event);
}
