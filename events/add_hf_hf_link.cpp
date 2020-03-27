#include "../helpers_event.h"

#include "df/history_event_add_hf_hf_linkst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_hf_linkst *event)
{
    auto hf = df::historical_figure::find(event->hf);
    auto hf_target = df::historical_figure::find(event->hf_target);
    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
    case histfig_hf_link_type::MOTHER:
        event_link(s, context, hf);
        s << " was born to ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::FATHER:
        event_link(s, context, hf);
        s << " was fathered by ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::SPOUSE:
        event_link(s, context, hf);
        s << " married ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::CHILD:
        event_link(s, context, hf);
        if (hf->sex == 1)
        {
            s << " fathered ";
        }
        else
        {
            s << " gave birth to ";
        }
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::DEITY:
        event_link(s, context, hf);
        s << " began worshipping ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::LOVER:
        event_link(s, context, hf);
        s << " fell in love with ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::PRISONER:
        event_link(s, context, hf);
        s << " imprisoned ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::IMPRISONER:
        event_link(s, context, hf);
        s << " was imprisoned by ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::MASTER:
        event_link(s, context, hf);
        s << " started an apprenticeship under ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::APPRENTICE:
        event_link(s, context, hf);
        s << " accepted ";
        event_link(s, context, hf_target);
        s << " as an apprentice";
        BREAK(type);
    case histfig_hf_link_type::COMPANION:
        event_link(s, context, hf);
        s << " became the companion of ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::FORMER_MASTER:
        event_link(s, context, hf);
        s << " was no longer the master of ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::FORMER_APPRENTICE:
        event_link(s, context, hf);
        s << " was no longer the apprentice of ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::PET_OWNER:
        if (auto race = hf ? df::creature_raw::find(hf->race) : nullptr)
        {
            auto caste = race->caste.at(hf->caste);
            if (caste->flags.is_set(caste_raw_flags::ADOPTS_OWNER))
            {
                std::swap(hf, hf_target);
            }
        }
        event_link(s, context, hf);
        s << " was adopted as the pet of ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::FORMER_SPOUSE:
        event_link(s, context, hf);
        s << " was no longer the spouse of ";
        event_link(s, context, hf_target);
        BREAK(type);
    case histfig_hf_link_type::DECEASED_SPOUSE:
        event_link(s, context, hf);
        s << " became the deceased spouse of ";
        event_link(s, context, hf_target);
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_HF_LINK)", event->id));
}
