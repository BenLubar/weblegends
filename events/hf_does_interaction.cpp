#include "../helpers_event.h"

#include "df/history_event_hf_does_interactionst.h"
#include "df/interaction.h"
#include "df/interaction_source.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_does_interactionst *event)
{
    auto interaction = df::interaction::find(event->interaction);
    auto source = interaction ? binsearch_in_vector(interaction->sources, event->source) : nullptr;

    auto doer = df::historical_figure::find(event->doer);
    event_link(s, context, doer);
    if (source)
    {
        s << source->hist_string_1;
    }
    auto target = df::historical_figure::find(event->target);
    event_link(s, context, target);
    if (source)
    {
        s << source->hist_string_2;
    }
    do_location(s, context, event);
}
