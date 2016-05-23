#include "weblegends.h"
#include "helpers.h"

#include "df/historical_entity.h"

void WebLegends::render_entity(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto ent = df::historical_entity::find(id);
    if (ent == nullptr)
    {
        return;
    }

    simple_header(s, &ent->name);

    s << "<p>";
    categorize(s, ent);
    s << "</p>";

    history(s, ent);
    // TODO
    s << "</body></html>";
}
