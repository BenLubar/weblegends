#include "../helpers_event.h"

bool do_weapon(std::ostream & s, const event_context & context, const df::history_hit_item & weapon, const std::string & prefix)
{
    bool any = false;

    if (auto item = df::item::find(weapon.item))
    {
        s << prefix;
        do_item_description(s, context, item);
        any = true;
    }
    else if (weapon.item_type != item_type::NONE)
    {
        ItemTypeInfo type(weapon.item_type, weapon.item_subtype);
        MaterialInfo mat(weapon.mattype, weapon.matindex);
        s << prefix << "a ";
        material(s, context, mat);
        s << " " << type.toString();
        any = true;
    }

    if (auto item = df::item::find(weapon.shooter_item))
    {
        if (!any)
        {
            s << prefix << "a projectile";
            any = true;
        }
        s << " fired from ";
        do_item_description(s, context, item);
    }
    else if (weapon.shooter_item_type != item_type::NONE)
    {
        if (!any)
        {
            s << prefix << "a projectile";
            any = true;
        }
        ItemTypeInfo type(weapon.shooter_item_type, weapon.shooter_item_subtype);
        MaterialInfo mat(weapon.shooter_mattype, weapon.shooter_matindex);
        s << " fired from a ";
        material(s, context, mat);
        s << " " << type.toString();
    }

    return any;
}
