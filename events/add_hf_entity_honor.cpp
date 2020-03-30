#include "../helpers_event.h"

#include "df/history_event_add_hf_entity_honorst.h"
#include "df/honors_type.h"

void do_event(std::ostream & s, const event_context & context, df::history_event_add_hf_entity_honorst *event)
{
    auto figure = df::historical_figure::find(event->hfid);
    auto entity = df::historical_entity::find(event->entity_id);
    auto honor = entity ? binsearch_in_vector(entity->honors, event->honor_id) : nullptr;

    if (!honor)
    {
        do_event_missing(s, context, event, __FILE__, __LINE__);
        return;
    }

    event_link(s, context, figure);
    s << " received the title of " << honor->name << " in ";
    event_link(s, context, entity);
    if (honor->flags.bits.granted_to_all_new_members)
    {
        s << ", given to all new members";
        return;
    }

    std::vector<std::string> requirements;
    if (honor->required_skill_points > 0)
    {
        bool melee = honor->required_skill_type.bits.melee_weapon;
        bool ranged = honor->required_skill_type.bits.ranged_weapon;
        std::string req = "attaining sufficient skill with ";
        if (melee && ranged)
        {
            req += "a weapon or technique";
        }
        else if (melee)
        {
            req += "a melee weapon or technique";
        }
        else if (ranged)
        {
            req += "a ranged weapon";
        }
        else
        {
            BEFORE_SWITCH(req_skill, honor->required_skill);
            switch (req_skill) {
            case job_skill::AXE:
                req += "the axe";
                BREAK(req_skill);
            case job_skill::SWORD:
                req += "the sword";
                BREAK(req_skill);
            case job_skill::MACE:
                req += "the mace";
                BREAK(req_skill);
            case job_skill::HAMMER:
                req += "the hammer";
                BREAK(req_skill);
            case job_skill::SPEAR:
                req += "the spear";
                BREAK(req_skill);
            case job_skill::CROSSBOW:
                req += "the crossbow";
                BREAK(req_skill);
            case job_skill::SHIELD:
                req += "the shield";
                BREAK(req_skill);
            case job_skill::PIKE:
                req += "the pike";
                BREAK(req_skill);
            case job_skill::WHIP:
                req += "the whip";
                BREAK(req_skill);
            case job_skill::BOW:
                req += "the bow";
                BREAK(req_skill);
            case job_skill::BLOWGUN:
                req += "the blowgun";
                BREAK(req_skill);
            case job_skill::WRESTLING:
                req += "grappling";
                BREAK(req_skill);
            case job_skill::BITE:
                req += "the tooth";
                BREAK(req_skill);
            case job_skill::GRASP_STRIKE:
                req += "strikes";
                BREAK(req_skill);
            case job_skill::STANCE_STRIKE:
                req += "kicks";
                BREAK(req_skill);
            case job_skill::DODGING:
                req += "dodging";
                BREAK(req_skill);
            default:
                req += toLower(enum_item_key_str(req_skill));
                break;
            }
            AFTER_SWITCH(req_skill, stl_sprintf("event-%d (ADD_HF_ENTITY_HONOR) skill", event->id));

            requirements.push_back(req);
        }
    }

    if (honor->required_battles > 0)
    {
        if (honor->required_battles == 1)
        {
            requirements.push_back("serving in combat");
        }
        else
        {
            requirements.push_back(stl_sprintf("participating in %d battles", honor->required_battles));
        }
    }

    if (honor->required_kills > 0)
    {
        if (honor->required_kills == 1)
        {
            requirements.push_back("slaying an enemy");
        }
        else
        {
            requirements.push_back(stl_sprintf("slaying %d enemies", honor->required_kills));
        }
    }


    if (honor->required_years_of_membership > 0)
    {
        if (honor->required_years_of_membership == 1)
        {
            requirements.push_back("being a member for a year");
        }
        else
        {
            requirements.push_back(stl_sprintf("%d years of membership", honor->required_years_of_membership));
        }
    }

    if (!requirements.empty())
    {
        s << " after ";
        list<std::string>(s, requirements, [](std::ostream& s, std::string str) { s << str; });
    }
}
