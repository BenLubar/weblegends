#include "../helpers_event.h"

void do_account_shift(std::ostream & s, int32_t shift)
{
    if (shift >= 5000)
    {
        s << " made a fortune";
    }
    else if (shift <= -5000)
    {
        s << " lost a fortune";
    }
    else if (shift >= 1000)
    {
        s << " did well";
    }
    else if (shift <= -1000)
    {
        s << " did poorly";
    }
    else
    {
        s << " broke even";
    }
}
