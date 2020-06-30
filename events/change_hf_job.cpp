#include "../helpers_event.h"

#include "df/history_event_change_hf_jobst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_jobst *event)
{
    auto hf = df::historical_figure::find(event->hfid);
    event_link(s, context, hf);
    if (event->new_job != profession::STANDARD)
    {
        s << " became a " << profession_name(hf, event->new_job);
        do_location(s, context, event);
        if (event->old_job != profession::STANDARD)
        {
            s << ", leaving ";
            if (auto pronoun = hf ? ENUM_ATTR(pronoun_type, posessive, hf->sex) : nullptr)
                s << pronoun;
            else
                s << "their";
            s << " previous job as a " << profession_name(hf, event->old_job);
        }
    }
    else
    {
        s << " left ";
        if (auto pronoun = hf ? ENUM_ATTR(pronoun_type, posessive, hf->sex) : nullptr)
            s << pronoun;
        else
            s << "their";
        s << " job as a " << profession_name(hf, event->old_job);
        do_location(s, context, event);
    }
}
