#include "weblegends.h"
#include "helpers.h"

#include "modules/Translation.h"

#include "df/caste_raw.h"
#include "df/creature_raw.h"
#include "df/histfig_hf_link.h"
#include "df/historical_figure.h"

void WebLegends::render_figure(std::ostream & s, int32_t id)
{
    CoreSuspender suspend;

    auto hf = df::historical_figure::find(id);
    if (hf == nullptr)
    {
        return;
    }

    auto race = df::creature_raw::find(hf->race);
    auto caste = (race && hf->caste != -1) ? race->caste.at(hf->caste) : nullptr;

    s << "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>" << Translation::TranslateName(&hf->name, false, false) << "</title></head><body>";
    s << "<h1>" << Translation::TranslateName(&hf->name, false, false) << " &ldquo;" << Translation::TranslateName(&hf->name, true, false)  << "&rdquo;</h1>";
    if (caste)
    {
        s << "<p>";
        if (hf->flags.is_set(histfig_flags::rotting_deity))
        {
            s << "rotting ";
        }
        if (hf->flags.is_set(histfig_flags::skeletal_deity))
        {
            s << "skeletal ";
        }
        if (caste->caste_name[0] == race->name[0] && hf->sex != -1)
        {
            if (hf->sex == 0)
            {
                s << "female ";
            }
            else if (hf->sex == 1)
            {
                s << "male ";
            }
        }
        s << caste->caste_name[0];
        if (hf->flags.is_set(histfig_flags::deity) || hf->flags.is_set(histfig_flags::skeletal_deity) || hf->flags.is_set(histfig_flags::rotting_deity))
        {
            s << " deity";
        }
        spheres(s, hf);
        born_died(s, hf);
        s << "<br>" << caste->description << "</p>";
    }
    else if (hf->flags.is_set(histfig_flags::force))
    {
        s << "<p>force";
        spheres(s, hf);
        s << "</p>";
    }
    if (!hf->histfig_links.empty())
    {
        s << "<h2 id=\"related-figures\">Related Figures</h2><ul>";
        for (auto it = hf->histfig_links.begin(); it != hf->histfig_links.end(); it++)
        {
            if (auto target = df::historical_figure::find((*it)->target_hf))
            {
                s << "<li>";
                switch ((*it)->getType())
                {
                    case histfig_hf_link_type::MOTHER:
                        s << "Mother: ";
                        break;
                    case histfig_hf_link_type::FATHER:
                        s << "Father: ";
                        break;
                    case histfig_hf_link_type::SPOUSE:
                        if (target->sex == 0)
                        {
                            s << "Wife: ";
                        }
                        else if (target->sex == 1)
                        {
                            s << "Husband: ";
                        }
                        else
                        {
                            s << "Spouse: ";
                        }
                        break;
                    case histfig_hf_link_type::CHILD:
                        if (target->sex == 0)
                        {
                            s << "Daughter: ";
                        }
                        else if (target->sex == 1)
                        {
                            s << "Son: ";
                        }
                        else
                        {
                            s << "Child: ";
                        }
                        break;
                    case histfig_hf_link_type::LOVER:
                        s << "Lover: ";
                        break;
                    case histfig_hf_link_type::DEITY:
                        s << "Object of ";
                        // TODO: ardent, faithful, ..., casual, dubious
                        s << " worship: ";
                        break;
                    case histfig_hf_link_type::COMPANION:
                        s << "Companion: ";
                        break;
                    case histfig_hf_link_type::PRISONER:
                        s << "Prisoner: ";
                        break;
                    case histfig_hf_link_type::IMPRISONER:
                        s << "Imprisoner: ";
                        break;
                    case histfig_hf_link_type::MASTER:
                        s << "Master: ";
                        break;
                    case histfig_hf_link_type::APPRENTICE:
                        s << "Apprentice: ";
                        break;
                    case histfig_hf_link_type::FORMER_APPRENTICE:
                        s << "Former apprentice: ";
                        break;
                }
                link(s, target);
                born_died(s, target);
                s << "</li>";
            }
        }
        s << "</ul>";
    }
    history(s, hf);
    // TODO
    s << "</body></html>";
}
