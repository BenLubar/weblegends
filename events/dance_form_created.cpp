#include "../helpers_event.h"

#include "df/dance_form.h"
#include "df/history_event_dance_form_createdst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_dance_form_createdst *event)
{
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
    }
    else
    {
        s << "An unknown choreographer";
    }
    s << " created ";
    if (auto form = df::dance_form::find(event->form))
    {
        s << "the dance form ";
        name_translated(s, form->name);
    }
    else
    {
        s << "[unknown dance form]";
    }
    do_location(s, context, event);
    do_circumstance_reason(s, context, event);
}
