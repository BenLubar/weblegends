#include "../helpers_event.h"

#include "df/dance_form.h"
#include "df/general_ref_abstract_buildingst.h"
#include "df/general_ref_artifact.h"
#include "df/general_ref_dance_formst.h"
#include "df/general_ref_entity.h"
#include "df/general_ref_feature_layerst.h"
#include "df/general_ref_historical_eventst.h"
#include "df/general_ref_historical_figurest.h"
#include "df/general_ref_interactionst.h"
#include "df/general_ref_knowledge_scholar_flagst.h"
#include "df/general_ref_languagest.h"
#include "df/general_ref_musical_formst.h"
#include "df/general_ref_poetic_formst.h"
#include "df/general_ref_sitest.h"
#include "df/general_ref_subregionst.h"
#include "df/general_ref_value_levelst.h"
#include "df/general_ref_written_contentst.h"
#include "df/interaction.h"
#include "df/interaction_source.h"
#include "df/musical_form.h"
#include "df/poetic_form.h"
#include "df/written_content.h"

void written_content(std::ostream & s, const event_context & context, df::written_content *content, df::historical_figure *omit_author, bool show_refs)
{
    s << "a ";
    typedef std::pair<df::written_content_style, int32_t> style_t;
    std::vector<style_t> styles;
    styles.resize(content->styles.size());
    for (auto style = styles.begin(); style != styles.end(); style++)
    {
        style->first = content->styles.at(style - styles.begin());
        style->second = content->style_strength.at(style - styles.begin());
    }
    list<style_t>(s, styles, [content](std::ostream & out, style_t style)
    {
        if (style.second > 1)
        {
            out << "somewhat ";
        }
        else if (style.second < 1)
        {
            out << "very ";
        }
        BEFORE_SWITCH(wcs, style.first);
        switch (wcs)
        {
        case written_content_style::Meandering:
            out << "meandering";
            BREAK(wcs);
        case written_content_style::Cheerful:
            out << "cheerful";
            BREAK(wcs);
        case written_content_style::Depressing:
            out << "depressing";
            BREAK(wcs);
        case written_content_style::Rigid:
            out << "rigid";
            BREAK(wcs);
        case written_content_style::Serious:
            out << "serious";
            BREAK(wcs);
        case written_content_style::Disjointed:
            out << "disjointed";
            BREAK(wcs);
        case written_content_style::Ornate:
            out << "ornate";
            BREAK(wcs);
        case written_content_style::Forceful:
            out << "forceful";
            BREAK(wcs);
        case written_content_style::Humorous:
            out << "humorous";
            BREAK(wcs);
        case written_content_style::Immature:
            out << "immature";
            BREAK(wcs);
        case written_content_style::SelfIndulgent:
            out << "self-indulgent";
            BREAK(wcs);
        case written_content_style::Touching:
            out << "touching";
            BREAK(wcs);
        case written_content_style::Compassionate:
            out << "compassionate";
            BREAK(wcs);
        case written_content_style::Vicious:
            out << "vicious";
            BREAK(wcs);
        case written_content_style::Concise:
            out << "concise";
            BREAK(wcs);
        case written_content_style::Scornful:
            out << "scornful";
            BREAK(wcs);
        case written_content_style::Witty:
            out << "witty";
            BREAK(wcs);
        case written_content_style::Ranting:
            out << "ranting";
            BREAK(wcs);
        }
        AFTER_SWITCH(wcs, stl_sprintf("content-%d", content->id));
    });
    if (!styles.empty())
    {
        s << " ";
    }
    BEFORE_SWITCH(type, content->type);
    switch (type)
    {
    case written_content_type::Manual:
        s << "manual";
        BREAK(type);
    case written_content_type::Guide:
        s << "guide";
        BREAK(type);
    case written_content_type::Chronicle:
        s << "chronicle";
        BREAK(type);
    case written_content_type::ShortStory:
        s << "short story";
        BREAK(type);
    case written_content_type::Novel:
        s << "novel";
        BREAK(type);
    case written_content_type::Biography:
        s << "biography";
        BREAK(type);
    case written_content_type::Autobiography:
        s << "autobiography";
        BREAK(type);
    case written_content_type::Poem:
        s << "poem";
        BREAK(type);
    case written_content_type::Play:
        s << "play";
        BREAK(type);
    case written_content_type::Letter:
        s << "letter";
        BREAK(type);
    case written_content_type::Essay:
        s << "essay";
        BREAK(type);
    case written_content_type::Dialog:
        s << "dialog";
        BREAK(type);
    case written_content_type::MusicalComposition:
        s << "musical composition";
        BREAK(type);
    case written_content_type::Choreography:
        s << "choreography";
        BREAK(type);
    case written_content_type::ComparativeBiography:
        s << "comparative biography";
        BREAK(type);
    case written_content_type::BiographicalDictionary:
        s << "biographical dictionary";
        BREAK(type);
    case written_content_type::Genealogy:
        s << "genealogy";
        BREAK(type);
    case written_content_type::Encyclopedia:
        s << "encyclopedia";
        BREAK(type);
    case written_content_type::CulturalHistory:
        s << "cultural history";
        BREAK(type);
    case written_content_type::CulturalComparison:
        s << "cultural comparison";
        BREAK(type);
    case written_content_type::AlternateHistory:
        s << "alternate history";
        BREAK(type);
    case written_content_type::TreatiseOnTechnologicalEvolution:
        s << "treatise on technological evolution";
        BREAK(type);
    case written_content_type::Dictionary:
        s << "dictionary";
        BREAK(type);
    case written_content_type::StarChart:
        s << "star chart";
        BREAK(type);
    case written_content_type::StarCatalogue:
        s << "star catalogue";
        BREAK(type);
    case written_content_type::Atlas:
        s << "atlas";
        BREAK(type);
    }
    AFTER_SWITCH(type, stl_sprintf("content-%d", content->id));
    if (auto author = df::historical_figure::find(content->author))
    {
        if (author != omit_author)
        {
            s << " by ";
            link(s, author);
        }
    }
    if (!content->title.empty())
    {
        s << " titled <em>" << content->title << "</em>";
    }

    if (show_refs)
    {
        for (auto ref : content->refs)
        {
            BEFORE_SWITCH(type, ref->getType());
            switch (type)
            {
            case general_ref_type::ARTIFACT:
                if (auto r = virtual_cast<df::general_ref_artifact>(ref))
                {
                    if (auto item = df::artifact_record::find(r->artifact_id))
                    {
                        s << ". The writing concerns the";
                        categorize(s, item);
                        s << " ";
                        event_link(s, context, item);
                    }
                }
                BREAK(type);
            case general_ref_type::INTERACTION:
                if (auto r = virtual_cast<df::general_ref_interactionst>(ref))
                {
                    if (auto interaction = df::interaction::find(r->interaction_id))
                    {
                        if (auto source = binsearch_in_vector(interaction->sources, r->source_id))
                        {
                            s << ". The writing teaches the reader " << source->name;
                        }
                    }
                }
                BREAK(type);
            case general_ref_type::ABSTRACT_BUILDING:
                if (auto r = virtual_cast<df::general_ref_abstract_buildingst>(ref))
                {
                    if (auto site = df::world_site::find(r->site_id))
                    {
                        if (auto structure = binsearch_in_vector(site->buildings, r->building_id))
                        {
                            s << ". The writing concerns the";
                            categorize(s, structure);
                            s << " ";
                            event_link(s, context, structure);
                        }
                    }
                }
                BREAK(type);
            case general_ref_type::ENTITY:
                if (auto r = virtual_cast<df::general_ref_entity>(ref))
                {
                    if (auto ent = df::historical_entity::find(r->entity_id))
                    {
                        s << ". The writing concerns the";
                        categorize(s, ent);
                        s << " ";
                        event_link(s, context, ent);
                    }
                }
                BREAK(type);
            case general_ref_type::HISTORICAL_EVENT:
                if (auto r = virtual_cast<df::general_ref_historical_eventst>(ref))
                {
                    if (auto e = df::history_event::find(r->event_id))
                    {
                        s << ". <em>";
                        event_reverse(s, context, e);
                        s << "</em>";
                    }
                }
                BREAK(type);
            case general_ref_type::SITE:
                if (auto r = virtual_cast<df::general_ref_sitest>(ref))
                {
                    if (auto site = df::world_site::find(r->site_id))
                    {
                        s << ". The writing concerns the";
                        categorize(s, site);
                        s << " ";
                        event_link(s, context, site);
                    }
                }
                BREAK(type);
            case general_ref_type::SUBREGION:
                if (auto r = virtual_cast<df::general_ref_subregionst>(ref))
                {
                    if (auto region = df::world_region::find(r->region_id))
                    {
                        s << ". The writing concerns the";
                        categorize(s, region);
                        s << " ";
                        event_link(s, context, region);
                    }
                }
                BREAK(type);
            case general_ref_type::FEATURE_LAYER:
                if (auto r = virtual_cast<df::general_ref_feature_layerst>(ref))
                {
                    if (auto layer = df::world_underground_region::find(r->underground_region_id))
                    {
                        s << ". The writing concerns the";
                        categorize(s, layer);
                        s << " ";
                        event_link(s, context, layer);
                    }
                }
                BREAK(type);
            case general_ref_type::HISTORICAL_FIGURE:
                if (auto r = virtual_cast<df::general_ref_historical_figurest>(ref))
                {
                    if (auto hf = df::historical_figure::find(r->hist_figure_id))
                    {
                        s << ". The writing concerns the";
                        categorize(s, hf);
                        s << " ";
                        event_link(s, context, hf);
                    }
                }
                BREAK(type);
            case general_ref_type::KNOWLEDGE_SCHOLAR_FLAG:
                if (auto r = virtual_cast<df::general_ref_knowledge_scholar_flagst>(ref))
                {
                    s << ". The writing concerns ";
                    knowledge(s, r->knowledge);
                }
                BREAK(type);
            case general_ref_type::VALUE_LEVEL:
                if (auto r = virtual_cast<df::general_ref_value_levelst>(ref))
                {
                    s << ". The author ";
                    value_level(s, r->value, r->level);
                }
                BREAK(type);
            case general_ref_type::LANGUAGE:
                if (auto r = virtual_cast<df::general_ref_languagest>(ref))
                {
                    if (auto lang = df::language_translation::find(r->anon_1))
                    {
                        s << ". The writing concerns the " << Translation::capitalize(toLower(lang->name)) << " language";
                    }
                }
                BREAK(type);
            case general_ref_type::WRITTEN_CONTENT:
                if (auto r = virtual_cast<df::general_ref_written_contentst>(ref))
                {
                    if (auto target = df::written_content::find(r->written_content_id))
                    {
                        s << ". The writing concerns ";
                        written_content(s, context, target);
                    }
                    else
                    {
                        s << ". The writing concerns an unknown writing";
                    }
                }
                BREAK(type);
            case general_ref_type::POETIC_FORM:
                if (auto r = virtual_cast<df::general_ref_poetic_formst>(ref))
                {
                    if (auto form = df::poetic_form::find(r->poetic_form_id))
                    {
                        s << ". The writing concerns the poetic form ";
                        name_translated(s, form->name);
                    }
                    else
                    {
                        s << ". The writing concerns a poetic form";
                    }
                }
                BREAK(type);
            case general_ref_type::MUSICAL_FORM:
                if (auto r = virtual_cast<df::general_ref_musical_formst>(ref))
                {
                    if (auto form = df::musical_form::find(r->musical_form_id))
                    {
                        s << ". The writing concerns the musical form ";
                        name_translated(s, form->name);
                    }
                    else
                    {
                        s << ". The writing concerns a musical form";
                    }
                }
                BREAK(type);
            case general_ref_type::DANCE_FORM:
                if (auto r = virtual_cast<df::general_ref_dance_formst>(ref))
                {
                    if (auto form = df::dance_form::find(r->dance_form_id))
                    {
                        s << ". The writing concerns the dance form ";
                        name_translated(s, form->name);
                    }
                    else
                    {
                        s << ". The writing concerns a dance form";
                    }
                }
                BREAK(type);
            default:
                break;
            }
            AFTER_SWITCH(type, stl_sprintf("content-%d", content->id));
        }
    }
}
