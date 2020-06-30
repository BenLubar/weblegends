#include "../helpers_event.h"

#include "df/history_event_add_hf_hf_linkst.h"

static std::string spouse_name(historical_figure *hf)
{
   if (hf && hf->sex == pronoun_type::she)
        return "wife";
   if (hf && hf->sex == pronoun_type::he)
        return "husband";
    return "spouse";
}

void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_hf_linkst *event)
{
    auto hf = df::historical_figure::find(event->hf);
    auto hf_target = df::historical_figure::find(event->hf_target);
    bool target_is_subject = context.hf == hf_target;

    event_link(s, context, target_is_subject ? hf_target : hf);

    BEFORE_SWITCH(type, event->type);
    switch (type)
    {
    case histfig_hf_link_type::MOTHER:
        if (target_is_subject)
            s << " gave birth to ";
        else
            s << " was born to ";
        BREAK(type);
    case histfig_hf_link_type::FATHER:
        if (target_is_subject)
            s << " sired ";
        else
            s << " was sired by ";
        BREAK(type);
    case histfig_hf_link_type::SPOUSE:
        // in DF, this is just "married" with no suffix, but we can be fancy
        s << " took ";
        BREAK(type);
    case histfig_hf_link_type::CHILD:
        if (target_is_subject)
            s << " was born to ";
        else
            s << " became the parent of ";
        BREAK(type);
    case histfig_hf_link_type::DEITY:
        if (target_is_subject)
            s << " received the worship of ";
        else
            s << " began worshipping ";
        BREAK(type);
    case histfig_hf_link_type::LOVER:
        s << " became romantically involved with ";
        BREAK(type);
    case histfig_hf_link_type::PRISONER:
        if (target_is_subject)
            s << " was imprisoned by ";
        else
            s << " imprisoned ";
        BREAK(type);
    case histfig_hf_link_type::IMPRISONER:
        if (target_is_subject)
            s << " imprisoned ";
        else
            s << " was imprisoned by ";
        BREAK(type);
    case histfig_hf_link_type::MASTER:
        if (target_is_subject)
            s << " became the master of ";
        else
            s << " began an apprenticeship under ";
        BREAK(type);
    case histfig_hf_link_type::APPRENTICE:
        if (target_is_subject)
            s << " began an apprenticeship under ";
        else
            s << " became the master of ";
        BREAK(type);
    case histfig_hf_link_type::COMPANION:
        s << " began traveling with ";
        BREAK(type);
    case histfig_hf_link_type::FORMER_MASTER:
        if (target_is_subject)
            s << " ceased being the master of ";
        else
            s << " ceased being the apprentice of ";
        BREAK(type);
    case histfig_hf_link_type::FORMER_APPRENTICE:
        if (target_is_subject)
            s << " ceased being the apprentice of ";
        else
            s << " ceased being the master of ";
        BREAK(type);
    case histfig_hf_link_type::PET_OWNER:
    {
        auto creature = hf_target ? df::creature_raw::find(hf_target->race) : nullptr;
        auto caste = creature ? vector_get(creature->caste, hf_target->caste) : nullptr;
        bool adopts_owner = caste && caste->flags.is_set(caste_raw_flags::ADOPTS_OWNER);
        if (target_is_subject != adopts_owner)
            s << " became the owner of ";
        else
            s << " became the pet of ";
        BREAK(type);
    }
    case histfig_hf_link_type::FORMER_SPOUSE:
        s << " became the former ";
        s << spouse_name(target_is_subject ? hf_target : hf);
        s << " of ";
        BREAK(type);
    case histfig_hf_link_type::DECEASED_SPOUSE:
        if (target_is_subject)
        {
            s << " became the deceased ";
            s << spouse_name(hf_target);
            s << " of ";
        }
        else
        {
            s << " became the ";
            s << spouse_name(hf);
            s << " of the deceased ";
        }
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d (ADD_HF_HF_LINK)", event->id));

    event_link(s, context, target_is_subject ? hf : hf_target);

    if (event->type == histfig_hf_link_type::SPOUSE)
    {
        auto subject = target_is_subject ? hf_target : hf;
        s << " to be ";
        if (auto pronoun = subject ? ENUM_ATTR(pronoun_type, posessive, subject->sex) : nullptr)
            s << pronoun;
        else
            s << "their";
        s << " " << spouse_name(target_is_subject ? hf : hf_target);
    }
}
