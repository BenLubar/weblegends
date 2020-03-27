#include "../helpers_event.h"

#include "df/history_event_hf_learns_secretst.h"
#include "df/interaction.h"
#include "df/interaction_source.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_learns_secretst *event)
{
    auto student = df::historical_figure::find(event->student);
    auto teacher = df::historical_figure::find(event->teacher);
    auto artifact = df::artifact_record::find(event->artifact);
    auto interaction = df::interaction::find(event->interaction);

    if (teacher)
    {
        event_link(s, context, teacher);
        s << " taught ";
        event_link(s, context, student);
        s << " ";
    }
    else
    {
        event_link(s, context, student);
        s << " learned ";
    }
    s << (interaction && !interaction->sources.empty() ? interaction->sources.at(0)->name : "[unknown interaction]");
    if (artifact)
    {
        s << (teacher ? " using " : " from ");
        event_link(s, context, artifact);
    }

    // TODO: int32_t anon_1;
}
