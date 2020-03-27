#include "../helpers_event.h"

#include "df/history_event_change_hf_jobst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_change_hf_jobst *event)
{
    auto hf = df::historical_figure::find(event->hfid);
    event_link(s, context, hf);
    if (event->new_job != profession::STANDARD)
    {
        s << " became a " << profession_name(hf, event->new_job);
        do_location_2(s, context, event);
        if (event->old_job != profession::STANDARD)
        {
            s << ", leaving ";
            if (hf->sex == 0)
            {
                s << "her";
            }
            else if (hf->sex == 1)
            {
                s << "his";
            }
            else
            {
                ASSUME_EQUAL(hf->sex, -1, stl_sprintf("hf-%d sex", hf->id));
                s << "its";
            }
            s << " previous job as a " << profession_name(hf, event->old_job);
        }
    }
    else
    {
        s << " left ";
        if (hf->sex == 0)
        {
            s << "her";
        }
        else if (hf->sex == 1)
        {
            s << "his";
        }
        else
        {
            ASSUME_EQUAL(hf->sex, -1, stl_sprintf("hf-%d sex", hf->id));
            s << "its";
        }
        s << " job as a " << profession_name(hf, event->old_job);
        do_location_2(s, context, event);
    }
}
