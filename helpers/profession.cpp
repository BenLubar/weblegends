#include "../helpers_event.h"

REQUIRE_GLOBAL(gamemode);

std::string profession_name(int32_t race, int16_t caste, df::profession prof, bool plural)
{
    std::string str;
    if (*gamemode == df::game_mode::ADVENTURE)
    {
        int32_t old_race_id = world->units.active[0]->race;
        world->units.active[0]->race = race;
        str = Units::getCasteProfessionName(race, caste, prof, plural);
        world->units.active[0]->race = old_race_id;
    }
    else
    {
        int16_t old_race_id = ui->race_id;
        ui->race_id = race;
        str = Units::getCasteProfessionName(race, caste, prof, plural);
        ui->race_id = old_race_id;
    }
    return toLower(str);
}

std::string profession_name(df::historical_figure *hf, df::profession prof, bool plural)
{
    return profession_name(hf->race, hf->caste, prof, plural);
}
