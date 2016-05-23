#include "weblegends.h"
#include "helpers.h"

#include "df/artifact_record.h"

void WebLegends::render_item(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto item = df::artifact_record::find(id);
    if (item == nullptr)
    {
        return;
    }

    simple_header(s, item);

    s << "<p>";
    categorize(s, item);
    s << "</p>";

    history(s, item);
    // TODO
    s << "</body></html>";
}
