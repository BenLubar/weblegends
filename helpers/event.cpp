#include "../helpers_event.h"
#include "../events.h"

void do_event_missing(std::ostream & s, const event_context &, df::history_event *event, const char *file, int line)
{
    std::string df_description;
    df::history_event_context df_context;
    event->getSentence(&df_description, &df_context);
    df_description = DF2UTF(df_description);
    s << "<abbr title=\"" << html_escape(df_description) << "\">" << enum_item_key_str(event->getType()) << ":" << event->id << "</abbr>";
#ifdef WEBLEGENDS_DEBUG
    weblegends_debug_log() << "[weblegends] [" << weblegends_basename(file, file) << ":" << line << "] missing event type handler for " << enum_item_key_str(event->getType()) << ": event-" << event->id << ": " << df_description << std::endl;
#endif
}

#define EVENT_TYPE(upper, lower) \
    void do_event(std::ostream &, const event_context &, df::history_event_ ## lower ## st *);
EVENT_TYPES
#undef EVENT_TYPE

static void event_dispatch(std::ostream & s, const event_context & context, df::history_event *event)
{
    if (event->seconds != -1)
    {
        int32_t month = (event->seconds / 28 / 1200) + 1;
        int32_t day = ((event->seconds / 1200) % 28) + 1;
        int32_t hour = (event->seconds % 1200) / 50;
        int32_t minute = (event->seconds % 50) * 60 / 50;
        s << "<!--" << event->id << ", " << stl_sprintf("%04d-%02d-%02dT%02d:%02d", event->year, month, day, hour, minute) << "-->";
    }
    else
    {
        s << "<!--" << event->id << ", year " << event->year << ", time unknown-->";
    }
    BEFORE_SWITCH(type, event->getType());
    switch (type)
    {
#define EVENT_TYPE(upper, lower) \
    case history_event_type::upper: \
        do_event(s, context, static_cast<df::history_event_ ## lower ## st *>(event)); \
        BREAK(type);
EVENT_TYPES
#undef EVENT_TYPE
    }
    if (!type_found)
    {
        do_event_missing(s, context, event, __FILE__, __LINE__);
    }
    AFTER_SWITCH(type, stl_sprintf("event-%d", event->id));
}

void event(std::ostream & s, const event_context & context, df::history_event *event, int32_t & last_year, int32_t & last_seconds)
{
    if (event->year != last_year)
    {
        if (event->year < 0)
        {
            s << "In a time before time, ";
        }
        else
        {
            s << "In " << event->year;
            if (event->seconds < 0)
            {
                s << ", ";
            }
            else
            {
                s << " on " << dayth(event->seconds) << " " << month(event->seconds) << ", ";
            }
        }
    }
    else if ((event->seconds < 0) != (last_seconds < 0) || event->seconds / 1200 != last_seconds / 1200)
    {
        s << "On " << dayth(event->seconds) << " " << month(event->seconds) << ", ";
    }
    last_year = event->year;
    last_seconds = event->seconds;

    event_dispatch(s, context, event);
    s << ". ";
}

void event_reverse(std::ostream & s, const event_context & context, df::history_event *event)
{
    event_dispatch(s, context, event);

    if (event->year < 0)
    {
        s << " in a time before time";
    }
    else
    {
        s << " in " << event->year;
        if (event->seconds >= 0)
        {
            s << " on " << dayth(event->seconds) << " " << month(event->seconds);
        }
    }
}
