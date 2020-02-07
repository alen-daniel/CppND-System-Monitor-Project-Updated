#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    
    int hh = seconds / 3600;
    int mm = seconds % 3600 / 60;
    int ss = seconds % 60;

    string hh_s, mm_s, ss_s;

    hh_s = std::to_string(hh);
    mm_s = std::to_string(mm);
    ss_s = std::to_string(ss);

    if (hh < 10)
    {
        hh_s = "0" + hh_s;
    }

    if (mm < 10)
    {
        mm_s = "0" + mm_s;
    }

    if (ss < 10)
    {
        ss_s = "0" + ss_s;
    }


    return hh_s + ":" + mm_s + ":" + ss_s;
}