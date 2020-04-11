#include "../helpers_event.h"

void value_level(std::ostream & s, df::value_type type, int32_t level)
{
    BEFORE_SWITCH(value, type);
    switch (value)
    {
    case value_type::NONE:
        s << "(no value)";
        BREAK(value);
    case value_type::LAW:
        if (level > 40)
        {
            s << "is an absolute believer in the rule of law";
        }
        else if (level > 25)
        {
            s << "has a great deal of respect for the law";
        }
        else if (level > 10)
        {
            s << "respects the law";
        }
        else if (level >= -10)
        {
            s << "doesn't feel strongly about the law";
        }
        else if (level >= -25)
        {
            s << "does not respect the law";
        }
        else if (level >= -40)
        {
            s << "disdains the law";
        }
        else
        {
            s << "finds the idea of laws abhorent";
        }
        BREAK(value);
    case value_type::LOYALTY:
        if (level > 40)
        {
            s << "has the highest regard for loyalty";
        }
        else if (level > 25)
        {
            s << "greatly prizes loyalty";
        }
        else if (level > 10)
        {
            s << "values loyalty";
        }
        else if (level >= -10)
        {
            s << "doesn't particularly value loyalty";
        }
        else if (level >= -25)
        {
            s << "views loyalty unfavorably";
        }
        else if (level >= -40)
        {
            s << "disdains loyalty";
        }
        else
        {
            s << "is disgusted by the idea of loyalty";
        }
        BREAK(value);
    case value_type::FAMILY:
        if (level > 40)
        {
            s << "sees family as one of the most important things in life";
        }
        else if (level > 25)
        {
            s << "values family greatly";
        }
        else if (level > 10)
        {
            s << "values family";
        }
        else if (level >= -10)
        {
            s << "does not care about family one way or the other";
        }
        else if (level >= -25)
        {
            s << "is put off by family";
        }
        else if (level >= -40)
        {
            s << "lacks any respect for family";
        }
        else
        {
            s << "finds the idea of family loathsome";
        }
        BREAK(value);
    case value_type::FRIENDSHIP:
        if (level > 40)
        {
            s << "believes friendship is a key to the ideal life";
        }
        else if (level > 25)
        {
            s << "sees friendship as one of the finer things in life";
        }
        else if (level > 10)
        {
            s << "thinks friendship is important";
        }
        else if (level >= -10)
        {
            s << "does not care about friendship";
        }
        else if (level >= -25)
        {
            s << "finds friendship burdensome";
        }
        else if (level >= -40)
        {
            s << "is completely put off by the idea of friends";
        }
        else
        {
            s << "finds the whole idea of friendship disgusting";
        }
        BREAK(value);
    case value_type::POWER:
        if (level > 40)
        {
            s << "believes that the acquisition of power over others is the ideal goal in life and worthy of the highest respect";
        }
        else if (level > 25)
        {
            s << "sees power over others as something to strive for";
        }
        else if (level > 10)
        {
            s << "respects power";
        }
        else if (level >= -10)
        {
            s << "doesn't find power particularly praiseworthy";
        }
        else if (level >= -25)
        {
            s << "has a negative view of those who exercise power over others";
        }
        else if (level >= -40)
        {
            s << "hates those who wield power over others";
        }
        else
        {
            s << "finds the acquisition and use of power abhorent and would have all masters toppled";
        }
        BREAK(value);
    case value_type::TRUTH:
        if (level > 40)
        {
            s << "believes the truth is inviolable regardless of the cost";
        }
        else if (level > 25)
        {
            s << "believes that honesty is a high ideal";
        }
        else if (level > 10)
        {
            s << "values honesty";
        }
        else if (level >= -10)
        {
            s << "does not particularly value the truth";
        }
        else if (level >= -25)
        {
            s << "finds blind honesty foolish";
        }
        else if (level >= -40)
        {
            s << "sees lying as an important means to an end";
        }
        else
        {
            s << "is repelled by the idea of honesty and lies without compunction";
        }
        BREAK(value);
    case value_type::CUNNING:
        if (level > 40)
        {
            s << "holds well-laid plans and shrewd deceptions in the highest regard";
        }
        else if (level > 25)
        {
            s << "greatly respects the shrewd and guileful";
        }
        else if (level > 10)
        {
            s << "values cunning";
        }
        else if (level >= -10)
        {
            s << "does not really value cunning and guile";
        }
        else if (level >= -25)
        {
            s << "sees guile and cunning as indirect and somewhat worthless";
        }
        else if (level >= -40)
        {
            s << "holds shrewd and crafty individuals in the lowest esteem";
        }
        else
        {
            s << "is utterly disgusted by guile and cunning";
        }
        BREAK(value);
    case value_type::ELOQUENCE:
        if (level > 40)
        {
            s << "believes that artful speech and eloquent expression are of the highest ideals";
        }
        else if (level > 25)
        {
            s << "deeply respects eloquent speakers";
        }
        else if (level > 10)
        {
            s << "values eloquence";
        }
        else if (level >= -10)
        {
            s << "doesn't value eloquence so much";
        }
        else if (level >= -25)
        {
            s << "finds eloquence and artful speech off-putting";
        }
        else if (level >= -40)
        {
            s << "finds [him/her]self somewhat disgusted with eloquent speakers";
        }
        else
        {
            s << "sees artful speech and eloquence as a wasteful form of deliberate deception and treats it as such";
        }
        BREAK(value);
    case value_type::FAIRNESS:
        if (level > 40)
        {
            s << "holds fairness as one of the highest ideals and despises cheating of any kind";
        }
        else if (level > 25)
        {
            s << "has great respect for fairness";
        }
        else if (level > 10)
        {
            s << "respects fair-dealing and fair-play";
        }
        else if (level >= -10)
        {
            s << "does not care about fairness";
        }
        else if (level >= -25)
        {
            s << "sees life as unfair and doesn't mind it that way";
        }
        else if (level >= -40)
        {
            s << "finds the idea of fair-dealing foolish and cheats when [he/she] finds it profitable";
        }
        else
        {
            s << "is disgusted by the idea of fairness and will freely cheat anybody at any time";
        }
        BREAK(value);
    case value_type::DECORUM:
        if (level > 40)
        {
            s << "views decorum as a high ideal and is deeply offended by those that fail to maintain it";
        }
        else if (level > 25)
        {
            s << "greatly respects those that observe decorum and maintain their dignity";
        }
        else if (level > 10)
        {
            s << "values decorum, dignity and proper behavior";
        }
        else if (level >= -10)
        {
            s << "doesn't care very much about decorum";
        }
        else if (level >= -25)
        {
            s << "finds maintaining decorum a silly, fumbling waste of time";
        }
        else if (level >= -40)
        {
            s << "sees those that attempt to maintain dignified and proper behavior as vain and offensive";
        }
        else
        {
            s << "is affronted by the whole notion of maintaining decorum and finds so-called dignified people disgusting";
        }
        BREAK(value);
    case value_type::TRADITION:
        if (level > 40)
        {
            s << "holds the maintenance of tradition as one of the highest ideals";
        }
        else if (level > 25)
        {
            s << "is a firm believer in the value of tradition";
        }
        else if (level > 10)
        {
            s << "values tradition";
        }
        else if (level >= -10)
        {
            s << "doesn't have any strong feelings about tradition";
        }
        else if (level >= -25)
        {
            s << "disregards tradition";
        }
        else if (level >= -40)
        {
            s << "finds the following of tradition foolish and limiting";
        }
        else
        {
            s << "is disgusted by tradition and would flout any [he/she] encounters if given a chance";
        }
        BREAK(value);
    case value_type::ARTWORK:
        if (level > 40)
        {
            s << "believes that the creation and appreciation of artwork is one of the highest ideals";
        }
        else if (level > 25)
        {
            s << "greatly respects artists and their works";
        }
        else if (level > 10)
        {
            s << "values artwork";
        }
        else if (level >= -10)
        {
            s << "doesn't care about art one way or another";
        }
        else if (level >= -25)
        {
            s << "finds artwork boring";
        }
        else if (level >= -40)
        {
            s << "sees the whole pursuit of art as silly";
        }
        else
        {
            s << "finds art offensive and would have it destroyed whenever possible";
        }
        BREAK(value);
    case value_type::COOPERATION:
        if (level > 40)
        {
            s << "places cooperation as one of the highest ideals";
        }
        else if (level > 25)
        {
            s << "sees cooperation as very important in life";
        }
        else if (level > 10)
        {
            s << "values cooperation";
        }
        else if (level >= -10)
        {
            s << "doesn't see cooperation as valuable";
        }
        else if (level >= -25)
        {
            s << "dislikes cooperation";
        }
        else if (level >= -40)
        {
            s << "views cooperation as a low ideal not worthy of any respect";
        }
        else
        {
            s << "is thoroughly disgusted by cooperation";
        }
        BREAK(value);
    case value_type::INDEPENDENCE:
        if (level > 40)
        {
            s << "believes that freedom and independence are completely non-negotiable and would fight to defend them";
        }
        else if (level > 25)
        {
            s << "treasures independence";
        }
        else if (level > 10)
        {
            s << "values independence";
        }
        else if (level >= -10)
        {
            s << "doesn't really value independence one way or another";
        }
        else if (level >= -25)
        {
            s << "finds the ideas of independence and freedom somewhat foolish";
        }
        else if (level >= -40)
        {
            s << "sees freedom and independence as completely worthless";
        }
        else
        {
            s << "hates freedom and would crush the independent spirit wherever it is found";
        }
        BREAK(value);
    case value_type::STOICISM:
        if (level > 40)
        {
            s << "views any show of emotion as offensive";
        }
        else if (level > 25)
        {
            s << "thinks it is of the utmost importance to present a bold face and never grouse, complain or even show emotion";
        }
        else if (level > 10)
        {
            s << "believes it is important to conceal emotions and refrain from complaining";
        }
        else if (level >= -10)
        {
            s << "doesn't see much value in being stoic";
        }
        else if (level >= -25)
        {
            s << "sees no value in holding back complaints and concealing emotions";
        }
        else if (level >= -40)
        {
            s << "feels that those who attempt to conceal their emotions are vain and foolish";
        }
        else
        {
            s << "sees concealment of emotions as a betrayal and tries [his/her] best never to associate with such secretive fools";
        }
        BREAK(value);
    case value_type::INTROSPECTION:
        if (level > 40)
        {
            s << "feels that introspection and all forms of self-examination are the keys to a good life and worthy of respect";
        }
        else if (level > 25)
        {
            s << "deeply values introspection";
        }
        else if (level > 10)
        {
            s << "sees introspection as important";
        }
        else if (level >= -10)
        {
            s << "doesn't really see the value in self-examination";
        }
        else if (level >= -25)
        {
            s << "finds introspection to be a waste of time";
        }
        else if (level >= -40)
        {
            s << "thinks that introspection is valueless and those that waste time in self-examination are deluded fools";
        }
        else
        {
            s << "finds the whole idea of introspection completely offensive and contrary to the ideals of a life well-lived";
        }
        BREAK(value);
    case value_type::SELF_CONTROL:
        if (level > 40)
        {
            s << "believes that self-mastery and the denial of impulses are of the highest ideals";
        }
        else if (level > 25)
        {
            s << "finds moderation and self-control to be very important";
        }
        else if (level > 10)
        {
            s << "values self-control";
        }
        else if (level >= -10)
        {
            s << "doesn't particularly value self-control";
        }
        else if (level >= -25)
        {
            s << "finds those that deny their impulses somewhat stiff";
        }
        else if (level >= -40)
        {
            s << "sees the denial of impulses as a vain and foolish pursuit";
        }
        else
        {
            s << "has abandoned any attempt at self-control and finds the whole concept deeply offensive";
        }
        BREAK(value);
    case value_type::TRANQUILITY:
        if (level > 40)
        {
            s << "views tranquility as one of the highest ideals";
        }
        else if (level > 25)
        {
            s << "strongly values tranquility and quiet";
        }
        else if (level > 10)
        {
            s << "values tranquility and a peaceful day";
        }
        else if (level >= -10)
        {
            s << "doesn't have a preference between tranquility and tumult";
        }
        else if (level >= -25)
        {
            s << "prefers a noisy, bustling life to boring days without activity";
        }
        else if (level >= -40)
        {
            s << "is greatly disturbed by quiet and a peaceful existence";
        }
        else
        {
            s << "is disgusted by tranquility and would that the world would constantly churn with noise and activity";
        }
        BREAK(value);
    case value_type::HARMONY:
        if (level > 40)
        {
            s << "would have the world operate in complete harmony without the least bit of strife or disorder";
        }
        else if (level > 25)
        {
            s << "strongly believes that a peaceful and ordered society without dissent is best";
        }
        else if (level > 10)
        {
            s << "values a harmonious existence";
        }
        else if (level >= -10)
        {
            s << "sees equal parts of harmony and discord as part of life";
        }
        else if (level >= -25)
        {
            s << "doesn't respect a society that has settled into harmony without debate and strife";
        }
        else if (level >= -40)
        {
            s << "can't fathom why anyone would want to live in an orderly and harmonious society";
        }
        else
        {
            s << "believes deeply that chaos and disorder are the truest expressions of life and would disrupt harmony wherever it is found";
        }
        BREAK(value);
    case value_type::MERRIMENT:
        if (level > 40)
        {
            s << "believes that little is better in life than a good party";
        }
        else if (level > 25)
        {
            s << "truly values merrymaking and parties";
        }
        else if (level > 10)
        {
            s << "finds merrymaking and partying worthwhile activities";
        }
        else if (level >= -10)
        {
            s << "doesn't really value merrymaking";
        }
        else if (level >= -25)
        {
            s << "sees merrymaking as a waste";
        }
        else if (level >= -40)
        {
            s << "is disgusted by merrymakers";
        }
        else
        {
            s << "is appalled by merrymaking, parties and other such worthless activities";
        }
        BREAK(value);
    case value_type::CRAFTSMANSHIP:
        if (level > 40)
        {
            s << "holds crafts[man]ship to be of the highest ideals and celebrates talented artisans and their masterworks";
        }
        else if (level > 25)
        {
            s << "has a great deal of respect for worthy crafts[man]ship";
        }
        else if (level > 10)
        {
            s << "values good crafts[man]ship";
        }
        else if (level >= -10)
        {
            s << "doesn't particularly care about crafts[man]ship";
        }
        else if (level >= -25)
        {
            s << "considers crafts[man]ship to be relatively worthless";
        }
        else if (level >= -40)
        {
            s << "sees the pursuit of good crafts[man]ship as a total waste";
        }
        else
        {
            s << "views crafts[man]ship with disgust and would desecrate a so-called masterwork or two if [he/she] could get away with it";
        }
        BREAK(value);
    case value_type::MARTIAL_PROWESS:
        if (level > 40)
        {
            s << "believes that martial prowess defines the good character of an individual";
        }
        else if (level > 25)
        {
            s << "deeply respects skill at arms";
        }
        else if (level > 10)
        {
            s << "values martial prowess";
        }
        else if (level >= -10)
        {
            s << "does not really value skills related to fighting";
        }
        else if (level >= -25)
        {
            s << "finds those that develop skill with weapons and fighting distasteful";
        }
        else if (level >= -40)
        {
            s << "thinks that the pursuit of the skills of warfare and fighting is a low pursuit indeed";
        }
        else
        {
            s << "abhors those that pursue the mastery of weapons and skill with fighting";
        }
        BREAK(value);
    case value_type::SKILL:
        if (level > 40)
        {
            s << "believes that the mastery of a skill is one of the highest pursuits";
        }
        else if (level > 25)
        {
            s << "really respects those that take the time to master a skill";
        }
        else if (level > 10)
        {
            s << "respects the development of skill";
        }
        else if (level >= -10)
        {
            s << "doesn't care if others take the time to master skills";
        }
        else if (level >= -25)
        {
            s << "finds the pursuit of skill mastery off-putting";
        }
        else if (level >= -40)
        {
            s << "believes that the time taken to master a skill is a horrible waste";
        }
        else
        {
            s << "sees the whole idea of taking time to master a skill as appalling";
        }
        BREAK(value);
    case value_type::HARD_WORK:
        if (level > 40)
        {
            s << "believes that hard work is one of the highest ideals and a key to the good life";
        }
        else if (level > 25)
        {
            s << "deeply respects those that work hard at their labors";
        }
        else if (level > 10)
        {
            s << "values hard work";
        }
        else if (level >= -10)
        {
            s << "doesn't really see the point of working hard";
        }
        else if (level >= -25)
        {
            s << "sees working hard as a foolish waste of time";
        }
        else if (level >= -40)
        {
            s << "thinks working hard is an abject idiocy";
        }
        else
        {
            s << "finds the proposition that one should work hard in life utterly abhorent";
        }
        BREAK(value);
    case value_type::SACRIFICE:
        if (level > 40)
        {
            s << "finds sacrifice to be one of the highest ideals";
        }
        else if (level > 25)
        {
            s << "believes that those who sacrifice for others should be deeply respected";
        }
        else if (level > 10)
        {
            s << "values sacrifice";
        }
        else if (level >= -10)
        {
            s << "doesn't particularly respect sacrifice as a virtue";
        }
        else if (level >= -25)
        {
            s << "sees sacrifice as wasteful and foolish";
        }
        else if (level >= -40)
        {
            s << "finds sacrifice to be the height of folly";
        }
        else
        {
            s << "thinks that the entire concept of sacrifice for others is truly disgusting";
        }
        BREAK(value);
    case value_type::COMPETITION:
        if (level > 40)
        {
            s << "holds the idea of competition among the most important and would encourage it wherever possible";
        }
        else if (level > 25)
        {
            s << "views competition as a crucial driving force in the world";
        }
        else if (level > 10)
        {
            s << "sees competition as reasonably important";
        }
        else if (level >= -10)
        {
            s << "doesn't have strong views on competition";
        }
        else if (level >= -25)
        {
            s << "sees competition as wasteful and silly";
        }
        else if (level >= -40)
        {
            s << "deeply dislikes competition";
        }
        else
        {
            s << "finds the very idea of competition obscene";
        }
        BREAK(value);
    case value_type::PERSEVERENCE:
        if (level > 40)
        {
            s << "believes that perseverence is one of the greatest qualities somebody can have";
        }
        else if (level > 25)
        {
            s << "greatly respects individuals that persevere through their trials and labors";
        }
        else if (level > 10)
        {
            s << "respects perseverence";
        }
        else if (level >= -10)
        {
            s << "doesn't think much about the idea of perseverence";
        }
        else if (level >= -25)
        {
            s << "sees perseverence in the face of adversity as bull-headed and foolish";
        }
        else if (level >= -40)
        {
            s << "thinks there is something deeply wrong with people that persevere through adversity";
        }
        else
        {
            s << "finds the notion that one would persevere through adversity completely abhorent";
        }
        BREAK(value);
    case value_type::LEISURE_TIME:
        if (level > 40)
        {
            s << "believes that it would be a fine thing if all time were leisure time";
        }
        else if (level > 25)
        {
            s << "treasures leisure time and thinks it is very important in life";
        }
        else if (level > 10)
        {
            s << "values leisure time";
        }
        else if (level >= -10)
        {
            s << "doesn't think one way or the other about leisure time";
        }
        else if (level >= -25)
        {
            s << "finds leisure time wasteful";
        }
        else if (level >= -40)
        {
            s << "is offended by leisure time and leisurely living";
        }
        else
        {
            s << "believes that those that take leisure time are evil and finds the whole idea disgusting";
        }
        BREAK(value);
    case value_type::COMMERCE:
        if (level > 40)
        {
            s << "sees engaging in commerce as a high ideal in life";
        }
        else if (level > 25)
        {
            s << "really respects commerce and those that engage in trade";
        }
        else if (level > 10)
        {
            s << "respects commerce";
        }
        else if (level >= -10)
        {
            s << "doesn't particularly respect commerce";
        }
        else if (level >= -25)
        {
            s << "is somewhat put off by trade and commerce";
        }
        else if (level >= -40)
        {
            s << "finds those that engage in trade and commerce to be fairly disgusting";
        }
        else
        {
            s << "holds the view that commerce is a vile obscenity";
        }
        BREAK(value);
    case value_type::ROMANCE:
        if (level > 40)
        {
            s << "sees romance as one of the highest ideals";
        }
        else if (level > 25)
        {
            s << "thinks romance is very important in life";
        }
        else if (level > 10)
        {
            s << "values romance";
        }
        else if (level >= -10)
        {
            s << "doesn't care one way or the other about romance";
        }
        else if (level >= -25)
        {
            s << "finds romance distasteful";
        }
        else if (level >= -40)
        {
            s << "is somewhat disgusted by romance";
        }
        else
        {
            s << "finds even the abstract idea of romance repellent";
        }
        BREAK(value);
    case value_type::NATURE:
        if (level > 40)
        {
            s << "holds nature to be of greater value than most aspects of civilization";
        }
        else if (level > 25)
        {
            s << "has a deep respect for animals, plants and the natural world";
        }
        else if (level > 10)
        {
            s << "values nature";
        }
        else if (level >= -10)
        {
            s << "doesn't care about nature one way or another";
        }
        else if (level >= -25)
        {
            s << "finds nature somewhat disturbing";
        }
        else if (level >= -40)
        {
            s << "has a deep dislike of the natural world";
        }
        else
        {
            s << "would just as soon have nature and the great outdoors burned to ashes and converted into a great mining pit";
        }
        BREAK(value);
    case value_type::PEACE:
        if (level > 40)
        {
            s << "believes the idea of war is utterly repellent and would have peace at all costs";
        }
        else if (level > 25)
        {
            s << "believes that peace is always preferable to war";
        }
        else if (level > 10)
        {
            s << "values peace over war";
        }
        else if (level >= -10)
        {
            s << "doesn't particularly care between war and peace";
        }
        else if (level >= -25)
        {
            s << "sees war as a useful means to an end";
        }
        else if (level >= -40)
        {
            s << "believes war is preferable to peace in general";
        }
        else
        {
            s << "thinks that the world should be engaged in perpetual warfare";
        }
        BREAK(value);
    case value_type::KNOWLEDGE:
        if (level > 40)
        {
            s << "finds the quest for knowledge to be of the very highest value";
        }
        else if (level > 25)
        {
            s << "views the pursuit of knowledge as deeply important";
        }
        else if (level > 10)
        {
            s << "values knowledge";
        }
        else if (level >= -10)
        {
            s << "doesn't see the attainment of knowledge as important";
        }
        else if (level >= -25)
        {
            s << "finds the pursuit of knowledge to be a waste of effort";
        }
        else if (level >= -40)
        {
            s << "thinks the quest for knowledge is a delusional fantasy";
        }
        else
        {
            s << "sees the attainment and preservation of knowledge as an offensive enterprise engaged in by arrogant fools";
        }
        BREAK(value);
    }
    AFTER_SWITCH(value, "");
}
