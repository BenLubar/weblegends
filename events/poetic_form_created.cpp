#include "../helpers_event.h"

#include "df/history_event_poetic_form_createdst.h"
#include "df/poetic_form.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_poetic_form_createdst *event)
{
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
    }
    else
    {
        s << "An unknown poet";
    }
    s << " created ";
    if (auto form = df::poetic_form::find(event->form))
    {
        s << "the poetic form ";
        name_translated(s, form->name);
    }
    else
    {
        s << "[unknown poetic form]";
    }
    do_location_2(s, context, event);
    do_circumstance_reason(s, context, event);
}
