#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/historical_entity.h"

void WebLegends::render_entity(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto ent = df::historical_entity::find(id);
    if (ent == nullptr)
    {
        return;
    }

    s << "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>" << Translation::TranslateName(&ent->name, false, false) << "</title></head><body>";
    s << "<h1>" << Translation::TranslateName(&ent->name, false, false) << " &ldquo;" << Translation::TranslateName(&ent->name, true, false)  << "&rdquo;</h1>";
    history(s, ent);
    // TODO
    s << "</body></html>";
}
