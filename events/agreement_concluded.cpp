#include "../helpers_event.h"

#include "df/agreement.h"
#include "df/agreement_details.h"
#include "df/agreement_details_data_join_party.h"
#include "df/agreement_details_data_location.h"
#include "df/agreement_details_data_plot_conviction.h"
#include "df/agreement_party.h"
#include "df/history_event_agreement_concludedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_agreement_concludedst *event)
{
    event_link(s, context, df::historical_figure::find(event->concluder_hf));
    s << " concluded ";

    if (auto agreement = df::agreement::find(event->agreement_id))
    {
        if (agreement->details.empty())
        {
            s << "an agreement";
        }
        else
        {
            auto details = agreement->details.at(0);
            BEFORE_SWITCH(type, details->type);
            switch (type)
            {
            case agreement_details_type::JoinParty:
                BEFORE_SWITCH(reason, details->data.JoinParty->reason);
                switch (reason)
                {
                case history_event_reason::insurrection:
                    s << "in insurrection mission";
                    BREAK(reason);
                case history_event_reason::adventure:
                    s << "an adventure";
                    BREAK(reason);
                case history_event_reason::guide:
                    s << "a guide agreement";
                    BREAK(reason);
                case history_event_reason::be_brought_to_safety:
                    s << "a journey to safety";
                    BREAK(reason);
                case history_event_reason::help_with_rescue:
                    s << "a rescue mission";
                    BREAK(reason);
                case history_event_reason::true_name_invocation:
                    s << "bound service";
                    BREAK(reason);
                case history_event_reason::entertain_people:
                    s << "a performance tour";
                    BREAK(reason);
                default:
                    do_event_missing(s, context, event, __FILE__, __LINE__);
                    break;
                }
                AFTER_SWITCH(reason, stl_sprintf("event-%d (AGREEMENT_CONCLUDED/JoinParty)", event->id));
                BREAK(type);
            case agreement_details_type::DemonicBinding:
                do_event_missing(s, context, event, __FILE__, __LINE__);
                BREAK(type);
            case agreement_details_type::Residency:
                s << "a residency agreement";
                BREAK(type);
            case agreement_details_type::Citizenship:
                s << "a citizenship agreement";
                BREAK(type);
            case agreement_details_type::Parley:
                s << "a parley";
                BREAK(type);
            case agreement_details_type::PositionCorruption:
                s << "corrupt dealing";
                BREAK(type);
            case agreement_details_type::PlotStealArtifact:
                s << "a theft deal";
                BREAK(type);
            case agreement_details_type::PromisePosition:
                s << "a promise of position";
                BREAK(type);
            case agreement_details_type::PlotAssassination:
                s << "an assassination plot";
                BREAK(type);
            case agreement_details_type::PlotAbduct:
                s << "an abduction plot";
                BREAK(type);
            case agreement_details_type::PlotSabotage:
                s << "a sabotage plot";
                BREAK(type);
            case agreement_details_type::PlotConviction:
                s << "a foiled ";
                BEFORE_SWITCH(crime, details->data.PlotConviction->crime);
                switch (crime)
                {
                case crime_type::Bribery:
                    s << "bribery";
                    BREAK(crime);
                case crime_type::anon_1:
                    do_event_missing(s, context, event, __FILE__, __LINE__);
                    break;
                case crime_type::Treason:
                    s << "corruption";
                    BREAK(crime);
                case crime_type::Embezzlement:
                    s << "embezzlement";
                    BREAK(crime);
                }
                AFTER_SWITCH(crime, stl_sprintf("event-%d (AGREEMENT_CONCLUDED/PlotConviction)", event->id));
                s << " conspiracy";
                BREAK(type);
            case agreement_details_type::Location:
                s << "an agreement to establish a ";
                s << toLower(enum_item_key_str(details->data.Location->type));
                BREAK(type);
            case agreement_details_type::PlotInfiltrationCoup:
                s << "an infiltration plot";
                BREAK(type);
            case agreement_details_type::PlotFrameTreason:
                s << "a framing plot";
                BREAK(type);
            case agreement_details_type::PlotInduceWar:
                s << "a war starting plot";
                BREAK(type);
            }
            AFTER_SWITCH(type, stl_sprintf("event-%d (AGREEMENT_CONCLUDED)", event->id));
        }

        for (auto party : agreement->parties)
        {
            if (vector_contains(party->histfig_ids, event->concluder_hf))
            {
                continue;
            }

            s << " with ";
            list<int32_t>(s, party->histfig_ids, [&](std::ostream & out, int32_t hfid)
            {
                event_link(out, context, df::historical_figure::find(hfid));
            });
            list<int32_t>(s, party->entity_ids, [&](std::ostream & out, int32_t entid)
            {
                event_link(out, context, df::historical_entity::find(entid));
            });

            break;
        }
    }
    else
    {
        s << "an agreement";
    }

    df::history_event_circumstance_info circumstance;
    df::history_event_reason_info reason;
    reason.type = event->reason;
    do_circumstance_reason(s, context, event, circumstance, reason);
}
