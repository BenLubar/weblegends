#include "../helpers_event.h"

#include "df/history_event_squad_vs_squadst.h"
#include "df/interaction.h"
#include "df/interaction_effect_animatest.h"
#include "df/squad.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_squad_vs_squadst *event)
{
    if (event->d_leader_hfid != -1 || event->a_hfid.empty() || !event->d_hfid.empty() || event->a_number != 0 || event->d_number == 0 || event->d_squad_id != -1)
    {
        // TODO: int32_t a_leader_hfid;
        // TODO: int32_t a_leadership_roll;
        // TODO: std::vector<int32_t > a_hfid;
        // TODO: int32_t a_squad_id;
        // TODO: int32_t a_race;
        // TODO: int32_t a_interaction;
        // TODO: int32_t a_effect;
        // TODO: int32_t a_number;
        // TODO: int32_t a_slain;
        // TODO: int32_t d_leader_hfid;
        // TODO: int32_t d_leadership_roll;
        // TODO: std::vector<int32_t > d_hfid;
        // TODO: int32_t d_squad_id;
        // TODO: int32_t d_race;
        // TODO: int32_t d_interaction;
        // TODO: int32_t d_effect;
        // TODO: int32_t d_number;
        // TODO: int32_t d_slain;
        do_event_missing(s, context, event, __FILE__, __LINE__);
        return;
    }

    auto d_race = df::creature_raw::find(event->d_race);
    auto d_interaction = df::interaction::find(event->d_interaction);
    auto d_effect = d_interaction ? vector_get(d_interaction->effects, event->d_effect) : nullptr;

    if (auto a_squad = df::squad::find(event->a_squad_id))
    {
        name_translated(s, a_squad->name);
        if (auto a_squad_civ = df::historical_entity::find(a_squad->entity_id))
        {
            s << " of ";
            event_link(s, context, a_squad_civ);
        }
        s << ", ";
    }
    list_event_link<df::historical_figure>(s, context, event->a_hfid);
    if (auto a_leader = df::historical_figure::find(event->a_leader_hfid))
    {
        s << ", led by ";
        event_link(s, context, a_leader);
    }
    s << " clashed with " << event->d_number;
    if (d_effect)
    {
        auto animate = virtual_cast<df::interaction_effect_animatest>(d_effect);
        if (animate && animate->syndrome.size() == 1)
        {
            //auto syn = animate->syndrome.at(0);
            do_event_missing(s, context, event, __FILE__, __LINE__);
        }
        else
        {
            do_event_missing(s, context, event, __FILE__, __LINE__);
        }
    }
    s << " " << d_race->name[event->d_number == 1 ? 0 : 1];

    do_location_1_structure(s, context, event);

    if (event->d_slain > 0)
    {
        s << ", slaying " << event->d_slain;
    }
}
