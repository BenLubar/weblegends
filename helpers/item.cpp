#include "../helpers_event.h"

void do_item_description(std::ostream & s, const event_context & context, df::item *item)
{
    if (auto is_artifact = Items::getGeneralRef(item, general_ref_type::IS_ARTIFACT))
    {
        if (auto artifact = is_artifact->getArtifact())
        {
            event_link(s, context, artifact);
            return;
        }
    }

    std::string str;
    item->getItemDescriptionPrefix(&str, 0);
    s << str;
    str.clear();
    item->getItemDescription(&str, 0);
    if (auto corpse = virtual_cast<df::item_body_component>(item))
    {
        if (auto hf = df::historical_figure::find(corpse->hist_figure_id))
        {
            std::string name = Translation::capitalize(Translation::TranslateName(&hf->name, false), true);
            size_t start = 0;
            size_t pos;
            while ((pos = str.find(name, start)) != std::string::npos)
            {
                s << str.substr(start, pos - start);
                link(s, hf);
                start = pos + name.length();
            }
            s << str.substr(start);
            return;
        }
    }
    s << str;
}
