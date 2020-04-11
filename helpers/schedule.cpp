#include "../helpers_event.h"

#include "df/dance_form.h"
#include "df/entity_occasion_schedule_feature.h"
#include "df/musical_form.h"
#include "df/poetic_form.h"

void schedule_feature(std::ostream & s, const event_context & context, df::entity_occasion_schedule_feature *feature, df::history_event *event)
{
    BEFORE_SWITCH(feat, feature->feature);
    switch (feat)
    {
    case occasion_schedule_feature::STORYTELLING:
        if (auto ref = df::history_event::find(feature->reference))
        {
            s << "telling of how ";
            event_reverse(s, context, ref);
        }
        else
        {
            s << "storytelling";
        }
        BREAK(feat);
    case occasion_schedule_feature::POETRY_RECITAL:
        if (auto form = df::poetic_form::find(feature->reference))
        {
            s << "a recital of the poetry ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a poetry recital";
        }
        BREAK(feat);
    case occasion_schedule_feature::MUSICAL_PERFORMANCE:
        if (auto form = df::musical_form::find(feature->reference))
        {
            s << "a performance of the music ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a musical performance";
        }
        BREAK(feat);
    case occasion_schedule_feature::DANCE_PERFORMANCE:
        if (auto form = df::dance_form::find(feature->reference))
        {
            s << "a performance of the dance ";
            name_translated(s, form->name);
        }
        else
        {
            s << "a dance performance";
        }
        BREAK(feat);
    case occasion_schedule_feature::CRIERS_IN_FRONT:
        s << "criers in front";
        ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: criers in front (event-%d)", event->id));
        BREAK(feat);
    case occasion_schedule_feature::ORDER_OF_PRECEDENCE:
        s << "an order of precedence";
        ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: order of precedence (event-%d)", event->id));
        BREAK(feat);
    case occasion_schedule_feature::BANNERS:
        s << "banners";
        ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: banners (event-%d)", event->id));
        BREAK(feat);
    case occasion_schedule_feature::IMAGES:
        s << "images";
        if (auto hf = df::historical_figure::find(feature->reference))
        {
            s << " of ";
            link(s, hf);
        }
        BREAK(feat);
    case occasion_schedule_feature::ACROBATS:
        s << "acrobats";
        ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: acrobats (event-%d)", event->id));
        BREAK(feat);
    case occasion_schedule_feature::INCENSE_BURNING:
        s << "the burning of incense";
        ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: incense burning (event-%d)", event->id));
        BREAK(feat);
    case occasion_schedule_feature::COSTUMES:
        s << "costumes";
        ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: costumes (event-%d)", event->id));
        BREAK(feat);
    case occasion_schedule_feature::CANDLES:
        s << "candles";
        ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: candles (event-%d)", event->id));
        BREAK(feat);
    case occasion_schedule_feature::THE_GIVING_OF_ITEMS:
        s << "the giving of items";
        ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: the giving of items (event-%d)", event->id));
        BREAK(feat);
    case occasion_schedule_feature::THE_SACRIFICE_OF_ITEMS:
        s << "the sacrifice of items";
        ASSUME_EQUAL(feature->reference, -1, stl_sprintf("feature: the sacrifice of items (event-%d)", event->id));
        BREAK(feat);
    default:
        s << enum_item_key_str(feat);
        s << ":";
        s << feature->reference;
        break;
    }
    AFTER_SWITCH(feat, stl_sprintf("feature: reference=%d (event-%d)", feature->reference, event->id));
}
