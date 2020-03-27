#include "../helpers_event.h"

#include "df/agreement.h"
#include "df/agreement_details.h"
#include "df/agreement_details_data_citizenship.h"
#include "df/agreement_details_data_demonic_binding.h"
#include "df/agreement_details_data_join_party.h"
#include "df/agreement_details_data_residency.h"
#include "df/agreement_party.h"
#include "df/history_event_agreement_formedst.h"

static void do_agreement_party(std::ostream & s, const event_context & context, df::history_event *event, df::agreement *agreement, df::agreement_party *party)
{
    if (!party)
    {
        UNEXPECTED(stl_sprintf("missing agreement party: event-%d %s agreement-%d", event->id, enum_item_key(event->getType()).c_str(), agreement->id));
        s << "[unknown party]";
        return;
    }

    std::vector<std::pair<int32_t, bool>> members;
    for (auto it = party->histfig_ids.begin(); it != party->histfig_ids.end(); it++)
    {
        members.push_back(std::make_pair(*it, false));
    }
    for (auto it = party->entity_ids.begin(); it != party->entity_ids.end(); it++)
    {
        members.push_back(std::make_pair(*it, true));
    }
    ASSUME_EQUAL(party->anon_1.size(), 0, stl_sprintf("event-%d %s agreement-%d party-%d anon_1", event->id, enum_item_key(event->getType()).c_str(), agreement->id, party->id));

    list<std::pair<int32_t, bool>>(s, members, [context](std::ostream & out, std::pair<int32_t, bool> member)
    {
        if (member.second)
        {
            event_link(out, context, df::historical_entity::find(member.first));
        }
        else
        {
            event_link(out, context, df::historical_figure::find(member.first));
        }
    });
}

void do_event(std::ostream & s, const event_context & context, df::history_event_agreement_formedst *event)
{
    auto agreement = df::agreement::find(event->agreement_id);
    list<df::agreement_details *>(s, agreement->details, [context, event, agreement](std::ostream & out, df::agreement_details *details)
    {
        BEFORE_SWITCH(type, details->type);
        switch (type)
        {
        case agreement_details_type::JoinParty:
        {
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, details->data.JoinParty->member));
            out << " joined with ";
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, details->data.JoinParty->party));
            BEFORE_SWITCH(reason, details->data.JoinParty->reason);
            switch (reason)
            {
            case history_event_reason::insurrection:
                out << " to oust ";
                event_link(out, context, df::historical_entity::find(details->data.JoinParty->entity));
                out << " from ";
                event_link(out, context, df::world_site::find(details->data.JoinParty->site));
                BREAK(reason);
            case history_event_reason::adventure:
                out << " to live a life of adventure";
                BREAK(reason);
            case history_event_reason::guide:
                out << " as a guide to ";
                event_link(out, context, df::world_site::find(details->data.JoinParty->site));
                BREAK(reason);
            case history_event_reason::be_brought_to_safety:
                out << " in order to be brought to safety";
                BREAK(reason);
            case history_event_reason::help_with_rescue:
                out << " to help rescue ";
                event_link(out, context, df::historical_figure::find(details->data.JoinParty->figure));
                BREAK(reason);
            case history_event_reason::true_name_invocation: // TODO: ???
                out << " after being compelled to serve";
                BREAK(reason);
            case history_event_reason::entertain_people:
                out << " to entertain the world";
                BREAK(reason);
            default:
                do_event_missing(out, context, event, __FILE__, __LINE__);
                break;
            }
            AFTER_SWITCH(reason, stl_sprintf("event-%d (AGREEMENT_FORMED) agreement-%d details-%d (joined party)", event->id, agreement->id, details->id));
            BREAK(type);
        }
        case agreement_details_type::DemonicBinding:
        {
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, details->data.DemonicBinding->summoner));
            out << " aided ";
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, details->data.DemonicBinding->demon));
            out << " in becoming a permanent part of the living world";
            BEFORE_SWITCH(reason, details->data.DemonicBinding->reason);
            switch (reason)
            {
            case history_event_reason::sphere_alignment:
                out << " after pondering the ineffable subtleties of ";
                out << toLower(enum_item_key(details->data.DemonicBinding->sphere));
                BREAK(reason);
            case history_event_reason::maintain_balance_in_universe:
                out << " in order to maintain balance in the universe";
                BREAK(reason);
            case history_event_reason::highlight_boundaries_between_worlds:
                out << " to create a monument to the boundaries between realities";
                BREAK(reason);
            case history_event_reason::sow_the_seeds_of_chaos_in_the_world:
                out << " to sow the seeds of chaos therein";
                BREAK(reason);
            case history_event_reason::provide_opportunities_for_courage:
                out << " to provide opportunities for courage to rise";
                BREAK(reason);
            case history_event_reason::bring_death_to_the_world:
                out << " that more might die";
                BREAK(reason);
            case history_event_reason::liked_appearance:
                out << " that all should gaze upon a truly gruesome visage";
                BREAK(reason);
            case history_event_reason::because_it_was_destined:
                out << " because it was destined";
                BREAK(reason);
            case history_event_reason::great_fortresses_built_and_tested:
                out << " that great fortresses might be raised and tested in siege";
                BREAK(reason);
            case history_event_reason::whim:
                out << " on a whim";
                BREAK(reason);
            case history_event_reason::bring_misery_to_the_world:
                out << " that it might bathe in misery forever";
                BREAK(reason);
            case history_event_reason::bring_murder_to_the_world:
                out << " that more might be murdered";
                BREAK(reason);
            case history_event_reason::bring_nightmares_into_reality:
                out << " in order to make nightmares reality";
                BREAK(reason);
            case history_event_reason::bring_thralldom_to_the_world:
                out << " in order to make thralls of everyone";
                BREAK(reason);
            case history_event_reason::bring_torture_to_the_world:
                out << " in order that acts of torture be perpetrated";
                BREAK(reason);
            case history_event_reason::provide_opportunities_for_acts_of_valor:
                out << " to provide opportunities for acts of valor to be performed";
                BREAK(reason);
            case history_event_reason::bring_war_to_the_world:
                out << " that war might rage forever";
                BREAK(reason);
            default:
                do_event_missing(out, context, event, __FILE__, __LINE__);
                break;
            }
            AFTER_SWITCH(reason, stl_sprintf("event-%d (AGREEMENT_FORMED) agreement-%d details-%d (demonic binding)", event->id, agreement->id, details->id));

            if (auto artifact = df::artifact_record::find(details->data.DemonicBinding->artifact))
            {
                out << " using ";
                event_link(out, context, artifact);
            }
            if (auto site = df::world_site::find(details->data.DemonicBinding->site))
            {
                out << " in ";
                event_link(out, context, site);
            }
            BREAK(type);
        }
        case agreement_details_type::Residency:
        {
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, details->data.Residency->applicant));
            out << " made an agreement with ";
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, details->data.Residency->government));
            out << ", becoming a resident of ";
            event_link(out, context, df::world_site::find(details->data.Residency->site));
            BEFORE_SWITCH(reason, details->data.Residency->reason);
            switch (reason)
            {
            case history_event_reason::eradicate_beasts:
                out << " to eradicate monsters";
                BREAK(reason);
            case history_event_reason::entertain_people:
                out << " to entertain the citizenry";
                BREAK(reason);
            case history_event_reason::make_a_living_as_a_warrior:
                out << " to work as a mercenary";
                BREAK(reason);
            default:
                do_event_missing(out, context, event, __FILE__, __LINE__);
                break;
            }
            AFTER_SWITCH(reason, stl_sprintf("event-%d (AGREEMENT_FORMED) agreement-%d details-%d (become resident)", event->id, agreement->id, details->id));
            BREAK(type);
        }
        case agreement_details_type::Citizenship:
        {
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, details->data.Citizenship->government));
            out << " made an agreement with ";
            do_agreement_party(out, context, event, agreement, binsearch_in_vector(agreement->parties, details->data.Citizenship->government));
            out << ", becoming a citizen of ";
            event_link(out, context, df::world_site::find(details->data.Citizenship->site));
            BREAK(type);
        }
        default:
            do_event_missing(out, context, event, __FILE__, __LINE__);
            break;
        }
        AFTER_SWITCH(type, stl_sprintf("event-%d (AGREEMENT_FORMED) agreement-%d details-%d type", event->id, agreement->id, details->id));
    });
    // TODO: int32_t anon_1;
    // TODO: int32_t anon_2;
    // TODO: int32_t anon_3;
}
