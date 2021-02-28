#include "../helpers_event.h"

#include "df/agreement.h"
#include "df/agreement_details.h"
#include "df/agreement_details_data_join_party.h"
#include "df/agreement_party.h"
#include "df/history_event_agreement_formedst.h"
#include "df/intrigue.h"

void do_agreement_party(std::ostream & s, const event_context & context, df::agreement *agreement, int32_t id)
{
    if (auto party = binsearch_in_vector(agreement->parties, id))
    {
        std::vector<std::pair<bool, int32_t>> members;
        for (int32_t id : party->histfig_ids)
        {
            members.push_back(std::make_pair(false, id));
        }

        for (int32_t id : party->entity_ids)
        {
            members.push_back(std::make_pair(true, id));
        }

        list<std::pair<bool, int32_t>>(s, members, [&](std::ostream & out, std::pair<bool, int32_t> member)
            {
                if (member.first)
                {
                    event_link(out, context, df::historical_entity::find(member.second));
                }
                else
                {
                    event_link(out, context, df::historical_figure::find(member.second));
                }
            });
    }
    else
    {
        s << "an unknown party";
    }
}

void do_event(std::ostream & s, const event_context & context, df::history_event_agreement_formedst *event)
{
    auto agreement = df::agreement::find(event->agreement_id);
    if (!agreement || agreement->parties.empty() || agreement->details.empty())
    {
        s << "a corrupt agreement was formed";
        return;
    }

    auto details = agreement->details.at(0);
    BEFORE_SWITCH(type, details->type);
    switch (type)
    {
    case agreement_details_type::JoinParty:
        do_agreement_party(s, context, agreement, details->data.JoinParty->member);
        s << " joined with ";
        do_agreement_party(s, context, agreement, details->data.JoinParty->party);


        BEFORE_SWITCH(reason, details->data.JoinParty->reason);
        switch (reason) {
        case history_event_reason::insurrection:
            s << " to oust ";
            event_link(s, context, df::historical_entity::find(details->data.JoinParty->entity));
            s << " from ";
            event_link(s, context, df::world_site::find(details->data.JoinParty->site));
            BREAK(reason);
        case history_event_reason::adventure:
            s << " to live a life of adventure";
            BREAK(reason);
        case history_event_reason::guide:
            s << " as a guide";
            if (details->data.JoinParty->figure != -1)
            {
                s << " to find ";
                event_link(s, context, df::historical_figure::find(details->data.JoinParty->figure));
            }
            else if (details->data.JoinParty->entity != -1)
            {
                s << " to find ";
                do_identity(s, context, nullptr, df::identity::find(details->data.JoinParty->entity));
            }
            else if (details->data.JoinParty->site != -1)
            {
                s << " to ";
                event_link(s, context, df::world_site::find(details->data.JoinParty->site));
            }
            BREAK(reason);
        case history_event_reason::be_brought_to_safety:
            s << " in order to be brought to safety";
            BREAK(reason);
        case history_event_reason::help_with_rescue:
            s << " to help rescue ";
            if (details->data.JoinParty->figure != -1)
            {
                event_link(s, context, df::historical_figure::find(details->data.JoinParty->figure));
            }
            else if (details->data.JoinParty->entity != -1)
            {
                do_identity(s, context, nullptr, df::identity::find(details->data.JoinParty->entity));
            }
            else
            {
                s << "someone";
            }
            BREAK(reason);
        case history_event_reason::true_name_invocation:
            s << " after being compelled to serve";
            BREAK(reason);
        case history_event_reason::entertain_people:
            s << " to entertain the world";
            BREAK(reason);
        default:
            break;
        }
        AFTER_SWITCH(reason, stl_sprintf("event-%d (AGREEMENT_FORMED) JoinParty", event->id));

        BREAK(type);
    default:
        // TODO
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (AGREEMENT_FORMED)", event->id));

    auto intrigue = df::intrigue::find(event->id);
    if (intrigue && intrigue->corruption)
    {
        // TODO
        do_event_missing(s, context, event, __FILE__, __LINE__);
    }
}
