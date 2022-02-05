#ifndef STOCK_H
#define STOCK_H
#include <string>
//#include <cmath>
#include <time.h>
//#include "stocks_map.h"

using namespace std;
#include <map>

struct Stock 
    {
        string stock_name;
        string stock_symbol;
        double share;
        int volume;
    };

#endif
