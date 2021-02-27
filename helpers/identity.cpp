#include "../helpers_event.h"

void do_identity(std::ostream & s, const event_context & context, df::historical_figure *, df::identity *identity)
{
    if (!identity)
    {
        s << "a secret identity";
        return;
    }

    if (identity->impersonated_hf != -1)
    {
        event_link(s, context, df::historical_figure::find(identity->impersonated_hf));
        return;
    }

    auto creature = df::creature_raw::find(identity->race);
    if (!creature)
    {
        s << "a secret identity";
        return;
    }
    auto caste = creature->caste.at(identity->caste);

    if (identity->name.has_name)
    {
        name_translated(s, identity->name);
        s << ", ";
    }

    s << "a ";

    if (identity->profession != profession::NONE && identity->profession != profession::STANDARD)
    {
        if (!caste->caste_name[2].empty())
        {
            s << html_escape(DF2UTF(caste->caste_name[2]));
        }
        else
        {
            s << html_escape(DF2UTF(creature->name[2]));
        }

        s << " ";
        profession_name(identity->race, identity->caste, identity->profession);
    }
    else
    {
        if (!caste->caste_name[0].empty())
        {
            s << html_escape(DF2UTF(caste->caste_name[0]));
        }
        else
        {
            s << html_escape(DF2UTF(creature->name[0]));
        }
    }

    if (identity->entity_id != -1)
    {
        s << " from ";
        event_link(s, context, df::historical_entity::find(identity->entity_id));
    }
}
