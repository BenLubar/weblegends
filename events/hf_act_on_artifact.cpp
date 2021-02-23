#include "../helpers_event.h"

#include "df/history_event_hf_act_on_artifactst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hf_act_on_artifactst *event)
{
    event_link(s, context, df::historical_figure::find(event->histfig));

    BEFORE_SWITCH(action, event->action);
    switch (action)
    {
    case df::history_event_hf_act_on_artifactst::View:
        s << " viewed ";
        BREAK(action);
    case df::history_event_hf_act_on_artifactst::AskAbout:
        s << " asked about ";
        BREAK(action);
    }
    if (!action_found)
    {
        do_event_missing(s, context, event, __FILE__, __LINE__);
    }
    AFTER_SWITCH(action, stl_sprintf("event-%d (HF_ACT_ON_ARTIFACT)", event->id));

    event_link(s, context, df::artifact_record::find(event->artifact));

    do_location(s, context, event->site, -1, -1, event->structure);
}
