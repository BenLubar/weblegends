#include "../weblegends.h"
#include "../helpers.h"

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
