#include "../helpers_event.h"

#include "df/history_event_tradest.h"
#include "df/resource_allotment_data.h"
#include "df/resource_allotment_specifier_ammost.h"
#include "df/resource_allotment_specifier_anvilst.h"
#include "df/resource_allotment_specifier_armor_bodyst.h"
#include "df/resource_allotment_specifier_armor_bootsst.h"
#include "df/resource_allotment_specifier_armor_glovesst.h"
#include "df/resource_allotment_specifier_armor_helmst.h"
#include "df/resource_allotment_specifier_armor_pantsst.h"
#include "df/resource_allotment_specifier_backpackst.h"
#include "df/resource_allotment_specifier_bagst.h"
#include "df/resource_allotment_specifier_bedst.h"
#include "df/resource_allotment_specifier_bonest.h"
#include "df/resource_allotment_specifier_boxst.h"
#include "df/resource_allotment_specifier_cabinetst.h"
#include "df/resource_allotment_specifier_chairst.h"
#include "df/resource_allotment_specifier_cheesest.h"
#include "df/resource_allotment_specifier_clothing_bodyst.h"
#include "df/resource_allotment_specifier_clothing_bootsst.h"
#include "df/resource_allotment_specifier_clothing_glovesst.h"
#include "df/resource_allotment_specifier_clothing_helmst.h"
#include "df/resource_allotment_specifier_clothing_pantsst.h"
#include "df/resource_allotment_specifier_clothst.h"
#include "df/resource_allotment_specifier_craftsst.h"
#include "df/resource_allotment_specifier_cropst.h"
#include "df/resource_allotment_specifier_extractst.h"
#include "df/resource_allotment_specifier_flaskst.h"
#include "df/resource_allotment_specifier_gemsst.h"
#include "df/resource_allotment_specifier_hornst.h"
#include "df/resource_allotment_specifier_leatherst.h"
#include "df/resource_allotment_specifier_meatst.h"
#include "df/resource_allotment_specifier_metalst.h"
#include "df/resource_allotment_specifier_pearlst.h"
#include "df/resource_allotment_specifier_powderst.h"
#include "df/resource_allotment_specifier_quiverst.h"
#include "df/resource_allotment_specifier_shellst.h"
#include "df/resource_allotment_specifier_skinst.h"
#include "df/resource_allotment_specifier_soapst.h"
#include "df/resource_allotment_specifier_stonest.h"
#include "df/resource_allotment_specifier_tablest.h"
#include "df/resource_allotment_specifier_tallowst.h"
#include "df/resource_allotment_specifier_threadst.h"
#include "df/resource_allotment_specifier_toothst.h"
#include "df/resource_allotment_specifier_weapon_meleest.h"
#include "df/resource_allotment_specifier_weapon_rangedst.h"
#include "df/resource_allotment_specifier_woodst.h"

#define SIMPLE(TYPE) \
    if (auto TYPE = virtual_cast<df::resource_allotment_specifier_ ## TYPE ## st>(allotment)) \
        material(s, context, TYPE); \
    else \
        s << #TYPE

#define SIMPLE2(TYPE, DEFAULT) \
    if (auto TYPE = virtual_cast<df::resource_allotment_specifier_ ## TYPE ## st>(allotment)) \
        material(s, context, TYPE); \
    else \
        s << DEFAULT

#define CONSTRUCTED(TYPE, SUFFIX) \
    if (auto TYPE = virtual_cast<df::resource_allotment_specifier_ ## TYPE ## st>(allotment)) \
    { \
        material(s, context, TYPE); \
        s << " "; \
    } \
    s << SUFFIX

static void do_resource_allotment(std::ostream & s, const event_context & context, int32_t production_zone, df::resource_allotment_specifier_type allotment_type, int32_t allotment_index)
{
    auto zone = df::resource_allotment_data::find(production_zone);
    if (!zone)
    {
        s << "goods";
        return;
    }

    auto allotment = zone->resource_allotments[allotment_type].at(allotment_index);
    BEFORE_SWITCH(type, allotment_type);
    switch (type)
    {
    case resource_allotment_specifier_type::CROP:
    {
        auto crop = virtual_cast<df::resource_allotment_specifier_cropst>(allotment);
        auto plant = crop ? df::plant_raw::find(crop->mat_type) : nullptr;
        if (plant)
        {
            s << plant->name_plural;
        }
        else
        {
            s << "crops";
        }
        BREAK(type);
    }
    case resource_allotment_specifier_type::STONE:
    {
        SIMPLE(stone);
        BREAK(type);
    }
    case resource_allotment_specifier_type::METAL:
    {
        SIMPLE(metal);
        BREAK(type);
    }
    case resource_allotment_specifier_type::WOOD:
    {
        SIMPLE(wood);
        BREAK(type);
    }
    case resource_allotment_specifier_type::ARMOR_BODY:
    {
        CONSTRUCTED(armor_body, "armor");
        BREAK(type);
    }
    case resource_allotment_specifier_type::ARMOR_PANTS:
    {
        CONSTRUCTED(armor_pants, "leg armor");
        BREAK(type);
    }
    case resource_allotment_specifier_type::ARMOR_GLOVES:
    {
        CONSTRUCTED(armor_gloves, "hand armor");
        BREAK(type);
    }
    case resource_allotment_specifier_type::ARMOR_BOOTS:
    {
        CONSTRUCTED(armor_boots, "foot armor");
        BREAK(type);
    }
    case resource_allotment_specifier_type::ARMOR_HELM:
    {
        CONSTRUCTED(armor_helm, "helmets");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CLOTHING_BODY:
    {
        CONSTRUCTED(clothing_body, "bodywear");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CLOTHING_PANTS:
    {
        CONSTRUCTED(clothing_pants, "legwear");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CLOTHING_GLOVES:
    {
        CONSTRUCTED(clothing_gloves, "handwear");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CLOTHING_BOOTS:
    {
        CONSTRUCTED(clothing_boots, "footwear");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CLOTHING_HELM:
    {
        CONSTRUCTED(clothing_helm, "headwear");
        BREAK(type);
    }
    case resource_allotment_specifier_type::WEAPON_MELEE:
    {
        CONSTRUCTED(weapon_melee, "weapons");
        BREAK(type);
    }
    case resource_allotment_specifier_type::WEAPON_RANGED:
    {
        CONSTRUCTED(weapon_ranged, "ranged weapons");
        BREAK(type);
    }
    case resource_allotment_specifier_type::ANVIL:
    {
        CONSTRUCTED(anvil, "anvils");
        BREAK(type);
    }
    case resource_allotment_specifier_type::GEMS:
    {
        SIMPLE(gems);
        BREAK(type);
    }
    case resource_allotment_specifier_type::THREAD:
    {
        CONSTRUCTED(thread, "thread");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CLOTH:
    {
        SIMPLE(cloth);
        BREAK(type);
    }
    case resource_allotment_specifier_type::LEATHER:
    {
        SIMPLE(leather);
        BREAK(type);
    }
    case resource_allotment_specifier_type::QUIVER:
    {
        CONSTRUCTED(quiver, "quivers");
        BREAK(type);
    }
    case resource_allotment_specifier_type::BACKPACK:
    {
        CONSTRUCTED(backpack, "backpacks");
        BREAK(type);
    }
    case resource_allotment_specifier_type::FLASK:
    {
        CONSTRUCTED(flask, "flasks");
        BREAK(type);
    }
    case resource_allotment_specifier_type::BAG:
    {
        CONSTRUCTED(bag, "bags");
        BREAK(type);
    }
    case resource_allotment_specifier_type::TABLE:
    {
        CONSTRUCTED(table, "tables");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CABINET:
    {
        CONSTRUCTED(cabinet, "cabinets");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CHAIR:
    {
        CONSTRUCTED(chair, "chairs");
        BREAK(type);
    }
    case resource_allotment_specifier_type::BOX:
    {
        CONSTRUCTED(box, "boxes");
        BREAK(type);
    }
    case resource_allotment_specifier_type::BED:
    {
        CONSTRUCTED(bed, "beds");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CRAFTS:
    {
        CONSTRUCTED(crafts, "crafts");
        BREAK(type);
    }
    case resource_allotment_specifier_type::MEAT:
    {
        SIMPLE(meat);
        BREAK(type);
    }
    case resource_allotment_specifier_type::BONE:
    {
        SIMPLE(bone);
        BREAK(type);
    }
    case resource_allotment_specifier_type::HORN:
    {
        SIMPLE(horn);
        BREAK(type);
    }
    case resource_allotment_specifier_type::SHELL:
    {
        SIMPLE(shell);
        BREAK(type);
    }
    case resource_allotment_specifier_type::TALLOW:
    {
        SIMPLE(tallow);
        BREAK(type);
    }
    case resource_allotment_specifier_type::TOOTH:
    {
        SIMPLE2(tooth, "teeth");
        BREAK(type);
    }
    case resource_allotment_specifier_type::PEARL:
    {
        SIMPLE(pearl);
        BREAK(type);
    }
    case resource_allotment_specifier_type::SOAP:
    {
        SIMPLE(soap);
        BREAK(type);
    }
    case resource_allotment_specifier_type::EXTRACT:
    {
        SIMPLE2(extract, "extracts");
        BREAK(type);
    }
    case resource_allotment_specifier_type::CHEESE:
    {
        SIMPLE(cheese);
        BREAK(type);
    }
    case resource_allotment_specifier_type::SKIN:
    {
        SIMPLE2(skin, "raw hides");
        BREAK(type);
    }
    case resource_allotment_specifier_type::POWDER:
    {
        SIMPLE(powder);
        BREAK(type);
    }
    case resource_allotment_specifier_type::AMMO:
    {
        CONSTRUCTED(ammo, "ammunition");
        BREAK(type);
    }
    }
    if (!type_found)
    {
        s << "goods";
    }
    AFTER_SWITCH(type, "resource allotment");
}

void do_event(std::ostream & s, const event_context & context, df::history_event_tradest *event)
{
    event_link(s, context, df::historical_figure::find(event->hf));
    if (event->entity != -1)
    {
        s << " of ";
        event_link(s, context, df::historical_entity::find(event->entity));
    }

    do_account_shift(s, event->account_shift);
    s << " trading ";
    do_resource_allotment(s, context, event->production_zone, df::resource_allotment_specifier_type(event->allotment), event->allotment_index);

    s << " from ";
    event_link(s, context, df::world_site::find(event->source_site));
    s << " to ";
    event_link(s, context, df::world_site::find(event->dest_site));
}
