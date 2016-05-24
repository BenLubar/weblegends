#include "weblegends.h"
#include "helpers.h"

#include "modules/Items.h"
#include "modules/Materials.h"

#include "df/artifact_record.h"
#include "df/creature_raw.h"
#include "df/historical_figure.h"
#include "df/history_event.h"
#include "df/item_constructed.h"
#include "df/item_slabst.h"
#include "df/itemimprovement.h"
#include "df/itemimprovement_itemspecificst.h"
#include "df/itemimprovement_pagesst.h"
#include "df/itemimprovement_writingst.h"
#include "df/world_site.h"
#include "df/written_content.h"

static void do_written_content(std::ostream & s, const event_context & context, df::written_content *content)
{
    if (content->page_start == -1)
    {
        s << " The written contents are ";
    }
    else
    {
        s << " Pages " << content->page_start << " to " << content->page_end << " are ";
    }
    written_content(s, context, content);
    s << ".";
}

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
    if (auto crafted = virtual_cast<df::item_crafted>(item->item))
    {
        if (auto maker = df::historical_figure::find(crafted->maker))
        {
            s << " created by ";
            link(s, maker);
        }
        else if (auto race = df::creature_raw::find(crafted->maker_race))
        {
            s << " created by " << race->name[1];
        }
    }
    if (auto slab = virtual_cast<df::item_slabst>(item->item))
    {
        s << "<br>" << slab->description;
    }
    s << "</p>";
    if (auto constructed = virtual_cast<df::item_constructed>(item->item))
    {
        for (auto it = constructed->improvements.begin(); it != constructed->improvements.end(); it++)
        {
            s << "<p>";
            switch ((*it)->getType())
            {
                case improvement_type::ART_IMAGE:
                    s << "ART_IMAGE";
                    break;
                case improvement_type::COVERED:
                    s << "COVERED";
                    break;
                case improvement_type::RINGS_HANGING:
                    s << "RINGS_HANGING";
                    break;
                case improvement_type::BANDS:
                    s << "BANDS";
                    break;
                case improvement_type::SPIKES:
                    s << "SPIKES";
                    break;
                case improvement_type::ITEMSPECIFIC:
                    if (auto imp = virtual_cast<df::itemimprovement_itemspecificst>(*it))
                    {
                        switch (imp->type)
                        {
                            case itemimprovement_specific_type::HANDLE:
                                s << " It has a ";
                                material(s, item, imp);
                                s << " handle.";
                                break;
                            case itemimprovement_specific_type::ROLLERS:
                                s << " It has ";
                                material(s, item, imp);
                                s << " rollers.";
                                break;
                        }
                    }
                    break;
                case improvement_type::THREAD:
                    s << "THREAD";
                    break;
                case improvement_type::CLOTH:
                    s << "CLOTH";
                    break;
                case improvement_type::SEWN_IMAGE:
                    s << "SEWN_IMAGE";
                    break;
                case improvement_type::PAGES:
                    if (auto imp = virtual_cast<df::itemimprovement_pagesst>(*it))
                    {
                        s << "The " << ItemTypeInfo(item->item).toString() << " contains " << imp->count << " ";
                        material(s, item, imp);
                        if (imp->count == 1)
                        {
                            s << " page.";
                        }
                        else
                        {
                            s << " pages.";
                        }
                        for (auto it2 = imp->contents.begin(); it2 != imp->contents.end(); it2++)
                        {
                            if (auto content = df::written_content::find(*it2))
                            {
                                do_written_content(s, item, content);
                            }
                        }
                    }
                    break;
                case improvement_type::ILLUSTRATION:
                    s << "ILLUSTRATION";
                    break;
                case improvement_type::INSTRUMENT_PIECE:
                    s << "INSTRUMENT_PIECE";
                    break;
                case improvement_type::WRITING:
                    if (auto imp = virtual_cast<df::itemimprovement_writingst>(*it))
                    {
                        for (auto it2 = imp->anon_1.begin(); it2 != imp->anon_1.end(); it2++)
                        {
                            if (auto content = df::written_content::find(*it2))
                            {
                                do_written_content(s, item, content);
                            }
                        }
                    }
                    break;
            }
            s << "</p>";
        }
    }

    history(s, item);
    // TODO
    s << "</body></html>";
}