#include "../helpers_event.h"

#include "df/history_event_hfs_formed_reputation_relationshipst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_hfs_formed_reputation_relationshipst *event)
{
    auto histfig1 = df::historical_figure::find(event->histfig1);
    auto identity1 = df::identity::find(event->identity1);
    auto histfig2 = df::historical_figure::find(event->histfig2);
    auto identity2 = df::identity::find(event->identity2);

    event_link(s, context, histfig1);
    if (identity1)
    {
        s << ", as ";
        do_identity(s, context, histfig1, identity1);
        s << ",";
    }

    std::string before;
    std::string after;

    BEFORE_SWITCH(rep1, event->rep1);
    switch (rep1)
    {
    case reputation_type::InformationSource:
        BEFORE_SWITCH(rep2, event->rep2);
        switch (rep2)
        {
        case reputation_type::Buddy:
            before = " formed a false friendship with ";
            after = " in order to extract information";
            BREAK(rep2);
        case reputation_type::InformationSource:
            before = " and ";
            after = " formed a false friendship where each used the other for information";
            BREAK(rep2);
        default:
            do_event_missing(s, context, event, __FILE__, __LINE__);
            break;
        }
        AFTER_SWITCH(rep2, stl_sprintf("event-%d (HFS_FORMED_REPUTATION_RELATIONSHIP:InformationSource)", event->id));
        BREAK(rep1);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(rep1, stl_sprintf("event-%d (HFS_FORMED_REPUTATION_RELATIONSHIP)", event->id));

    s << before;

    event_link(s, context, histfig2);
    if (identity2)
    {
        s << ", as ";
        do_identity(s, context, histfig2, identity2);
        if (!after.empty())
        {
            s << ",";
        }
    }

    s << after;

    do_location_2(s, context, event);
}
