// cut_wire.h
#include <string>
#include "time.h"
using namespace std;
#ifndef CUT_WIRE_H
#define CUT_WIRE_H

int check_wires(string wires[], int n);

int cut_wire(chrono::steady_clock::time_point& end_time);

#endif
