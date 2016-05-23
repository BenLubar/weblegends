#include "weblegends.h"
#include "helpers.h"

#include "modules/Items.h"
#include "modules/Materials.h"

#include "df/artifact_record.h"
#include "df/creature_raw.h"
#include "df/general_ref_historical_eventst.h"
#include "df/historical_figure.h"
#include "df/history_event.h"
#include "df/item_constructed.h"
#include "df/itemimprovement.h"
#include "df/itemimprovement_pagesst.h"
#include "df/written_content.h"

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
                    s << "ITEMSPECIFIC";
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
                        s << "The " << ItemTypeInfo(item->item).toString() << " contains " << imp->count << " " << MaterialInfo(imp).toString() << " pages.";
                        for (auto it2 = imp->contents.begin(); it2 != imp->contents.end(); it2++)
                        {
                            if (auto content = df::written_content::find(*it2))
                            {
                                s << " Pages " << content->page_start << " to " << content->page_end << " are a ";
                                typedef std::pair<df::written_content_style, int32_t> style_t;
                                std::vector<style_t> styles;
                                styles.resize(content->styles.size());
                                for (auto style = styles.begin(); style != styles.end(); style++)
                                {
                                    style->first = content->styles.at(style - styles.begin());
                                    style->second = content->style_strength.at(style - styles.begin());
                                }
                                list<style_t>(s, styles, [](std::ostream & out, style_t style)
                                        {
                                            if (style.second > 1)
                                            {
                                                out << "somewhat ";
                                            }
                                            else if (style.second < 1)
                                            {
                                                out << "very ";
                                            }
                                            switch (style.first)
                                            {
                                                case written_content_style::Meandering:
                                                    out << "meandering";
                                                    break;
                                                case written_content_style::Cheerful:
                                                    out << "cheerful";
                                                    break;
                                                case written_content_style::Depressing:
                                                    out << "depressing";
                                                    break;
                                                case written_content_style::Rigid:
                                                    out << "rigid";
                                                    break;
                                                case written_content_style::Serious:
                                                    out << "serious";
                                                    break;
                                                case written_content_style::Disjointed:
                                                    out << "disjointed";
                                                    break;
                                                case written_content_style::Ornate:
                                                    out << "ornate";
                                                    break;
                                                case written_content_style::Forceful:
                                                    out << "forceful";
                                                    break;
                                                case written_content_style::Humorous:
                                                    out << "humorous";
                                                    break;
                                                case written_content_style::Immature:
                                                    out << "immature";
                                                    break;
                                                case written_content_style::SelfIndulgent:
                                                    out << "self-indulgent";
                                                    break;
                                                case written_content_style::Touching:
                                                    out << "touching";
                                                    break;
                                                case written_content_style::Compassionate:
                                                    out << "compassionate";
                                                    break;
                                                case written_content_style::Vicious:
                                                    out << "vicious";
                                                    break;
                                                case written_content_style::Concise:
                                                    out << "concise";
                                                    break;
                                                case written_content_style::Scornful:
                                                    out << "scornful";
                                                    break;
                                                case written_content_style::Witty:
                                                    out << "witty";
                                                    break;
                                                case written_content_style::Ranting:
                                                    out << "ranting";
                                                    break;
                                            }
                                        });
                                if (!styles.empty())
                                {
                                    s << " ";
                                }
                                switch (content->type)
                                {
                                    case written_content_type::Manual:
                                        s << "manual";
                                        break;
                                    case written_content_type::Guide:
                                        s << "guide";
                                        break;
                                    case written_content_type::Chronicle:
                                        s << "chronicle";
                                        break;
                                    case written_content_type::ShortStory:
                                        s << "short story";
                                        break;
                                    case written_content_type::Novel:
                                        s << "novel";
                                        break;
                                    case written_content_type::Biography:
                                        s << "biography";
                                        break;
                                    case written_content_type::Autobiography:
                                        s << "autobiography";
                                        break;
                                    case written_content_type::Poem:
                                        s << "poem";
                                        break;
                                    case written_content_type::Play:
                                        s << "play";
                                        break;
                                    case written_content_type::Letter:
                                        s << "letter";
                                        break;
                                    case written_content_type::Essay:
                                        s << "essay";
                                        break;
                                    case written_content_type::Dialog:
                                        s << "dialog";
                                        break;
                                    case written_content_type::MusicalComposition:
                                        s << "musical composition";
                                        break;
                                    case written_content_type::Choreography:
                                        s << "choreography";
                                        break;
                                }
                                if (auto author = df::historical_figure::find(content->author))
                                {
                                    s << " by ";
                                    link(s, author);
                                }
                                s << " titled " << content->title << ".";

                                for (auto ref = content->refs.begin(); ref != content->refs.end(); ref++)
                                {
                                    switch ((*ref)->getType())
                                    {
                                        case general_ref_type::HISTORICAL_EVENT:
                                            if (auto r = virtual_cast<df::general_ref_historical_eventst>(*ref))
                                            {
                                                if (auto e = df::history_event::find(r->event_id))
                                                {
                                                    int32_t last_year = 0;
                                                    int32_t last_seconds = -1;
                                                    s << " ";
                                                    event(s, item, e, last_year, last_seconds);
                                                }
                                            }
                                            break;
                                        default:
                                            s << " " << ENUM_KEY_STR(general_ref_type, (*ref)->getType());
                                    }
                                }
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
                    s << "WRITING";
                    break;
            }
            s << "</p>";
        }
    }

    history(s, item);
    // TODO
    s << "</body></html>";
}
