#include "../helpers_event.h"

#include "df/history_event_artifact_claim_formedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_artifact_claim_formedst *event)
{
    auto artifact = df::artifact_record::find(event->artifact);
    auto histfig = df::historical_figure::find(event->histfig);
    auto entity = df::historical_entity::find(event->entity);

    event_link(s, context, artifact);

    std::string before;
    std::string after;

    BEFORE_SWITCH(type, event->claim_type);
    switch (type)
    {
    case artifact_claim_type::Symbol:
        before = " was made a symbol of ";
        BREAK(type);
    case artifact_claim_type::Heirloom:
        before = " was claimed by ";
        after = " as a family heirloom";
        BREAK(type);
    case artifact_claim_type::Treasure:
        before = " was claimed by ";
        BREAK(type);
    case artifact_claim_type::HolyRelic:
        before = " was sanctified by ";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ARTIFACT_CLAIM_FORMED)", event->id));

    s << before;

    if (histfig)
    {
        event_link(s, context, histfig);
    }
    if (!histfig || entity)
    {
        if (auto pos = entity ? vector_get(entity->positions.own, event->position_profile) : nullptr)
        {
            if (histfig)
            {
                s << ", ";
            }
            s << " the " << pos->name[0] << " of ";
        }
        else if (histfig)
        {
            s << " of ";
        }
        event_link(s, context, entity);
    }

    s << after;

    do_circumstance_reason(s, context, event);
}
