#include "../helpers_event.h"

#include "df/history_event_body_abusedst.h"
#include "df/itemdef_weaponst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_body_abusedst *event)
{
    if (auto hf = df::historical_figure::find(event->histfig))
    {
        event_link(s, context, hf);
        if (auto ent = df::historical_entity::find(event->civ))
        {
            s << " of ";
            event_link(s, context, ent);
        }
    }
    else if (auto ent = df::historical_entity::find(event->civ))
    {
        event_link(s, context, ent);
    }
    BEFORE_SWITCH(type, event->abuse_type);
    switch (type)
    {
    case df::history_event_body_abusedst::T_abuse_type::Impaled:
        s << " impaled";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Piled:
        s << " added";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Flayed:
        s << " flayed";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Hung:
        s << " hung";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Mutilated:
        s << " horribly mutilated";
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Animated:
        s << " animated";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (BODY_ABUSED)", event->id));
    if (event->bodies.size() == 1)
    {
        s << " the body of ";
    }
    else
    {
        s << " the bodies of ";
    }
    list_event_link<df::historical_figure>(s, context, event->bodies);
    BEFORE_SWITCH(type, event->abuse_type);
    switch (type)
    {
    case df::history_event_body_abusedst::T_abuse_type::Impaled:
    {
        ASSUME_EQUAL(event->abuse_data.Impaled.item_type, item_type::WEAPON, stl_sprintf("event-%d (BODY_ABUSED) impaled", event->id));
        auto idef = df::itemdef_weaponst::find(event->abuse_data.Impaled.item_subtype);
        s << " on ";
        if (event->bodies.size() == 1)
        {
            s << "a ";
            material(s, context, &event->abuse_data.Impaled);
            s << " " << idef->name;
        }
        else
        {
            material(s, context, &event->abuse_data.Impaled);
            s << " " << idef->name_plural;
        }
        BREAK(type);
    }
    case df::history_event_body_abusedst::T_abuse_type::Piled:
    {
        using pile_type = df::history_event_body_abusedst::T_abuse_data::T_Piled::T_pile_type;
        s << " to a ";
        BEFORE_SWITCH(pile, event->abuse_data.Piled.pile_type);
        switch (pile)
        {
        case pile_type::GrislyMound:
            s << "grisly mound";
            BREAK(pile);
        case pile_type::GrotesquePillar:
            s << "grotesque pillar";
            BREAK(pile);
        case pile_type::GruesomeSculpture:
            s << "gruesome sculpture";
            BREAK(pile);
        }
        AFTER_SWITCH(pile, stl_sprintf("event-%d (BODY_ABUSED)", event->id));
        BREAK(type);
    }
    case df::history_event_body_abusedst::T_abuse_type::Flayed:
    {
        s << " and stretched ";
        if (event->bodies.size() == 1)
        {
            auto hf = df::historical_figure::find(event->bodies.at(0));
            if (hf->sex == 0)
            {
                s << "her skin";
            }
            else if (hf->sex == 1)
            {
                s << "his skin";
            }
            else
            {
                s << "its skin";
            }
        }
        else
        {
            s << "their skins";
        }
        s << " over ";
        auto site = df::world_site::find(event->site);
        auto structure = binsearch_in_vector(site->buildings, event->abuse_data.Flayed.structure);
        event_link(s, context, structure);
        BREAK(type);
    }
    case df::history_event_body_abusedst::T_abuse_type::Hung:
        s << " from ";
        if (auto tree = df::plant_raw::find(event->abuse_data.Hung.tree))
        {
            s << "a " << tree->name << " tree with ";
        }
        if (event->bodies.size() == 1)
        {
            s << "a ";
            material(s, context, &event->abuse_data.Hung);
            s << " rope";
        }
        else
        {
            material(s, context, &event->abuse_data.Hung);
            s << " ropes";
        }
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Mutilated:
        BREAK(type);
    case df::history_event_body_abusedst::T_abuse_type::Animated:
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (BODY_ABUSED)", event->id));
    // TODO: int32_t anon_1;
    do_location_2(s, context, event);
}
