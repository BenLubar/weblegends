#include "../helpers_event.h"

#include "df/history_event_topicagreement_rejectedst.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_topicagreement_rejectedst *event)
{
    auto source = df::historical_entity::find(event->source);
    auto destination = df::historical_entity::find(event->destination);
    auto site = df::world_site::find(event->site);

    BEFORE_SWITCH(topic, event->topic);
    switch (topic)
    {
    case meeting_topic::RequestPeace:
        s << "A peace agreement";
        BREAK(topic);
    case meeting_topic::TreeQuota:
        s << "A lumber agreement";
        BREAK(topic);
    case meeting_topic::BecomeLandHolder:
        s << "The establishment of landed nobility";
        BREAK(topic);
    case meeting_topic::PromoteLandHolder:
        s << "The elevation of the landed nobility";
        BREAK(topic);
    case meeting_topic::ExportAgreement:
    case meeting_topic::ImportAgreement:
        s << "A trade agreement";
        BREAK(topic);
    case meeting_topic::TributeAgreement:
        s << "A tribute agreement";
        BREAK(topic);
    default:
        do_event_missing(s, context, event, __FILE__, __LINE__);
        break;
    }
    AFTER_SWITCH(topic, stl_sprintf("event-%d (TOPICAGREEMENT_REJECTED)", event->id));

    s << " proposed by ";
    event_link(s, context, source);
    s << " was rejected by ";
    event_link(s, context, destination);
    s << " at ";
    event_link(s, context, site);
}
