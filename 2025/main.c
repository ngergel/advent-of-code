// -------------------------------------------------
//	main.c
//
//  Entry point for the AoC solutions.
//
//  (c) Noah Gergel 2025
// -------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "aoc.h"


void register_fn(fn_t f) {
    all_func[num_fn++] = f;
}

void register_all_days(void) {
    register_fn(day1_p1), register_fn(day1_p2);
    register_fn(day2_p1), register_fn(day2_p2);
    register_fn(day3_p1), register_fn(day3_p2);
    register_fn(day4_p1), register_fn(day4_p2);
}

void run_day(int day) {
    // Note that the days are 1-indexed, but the array is 0 indexed.
    int idx = day * 2;
    if (idx < num_fn) all_func[idx]();
    if (idx + 1 < num_fn) all_func[idx + 1]();
}


int main(int argc, char** argv) {

    if (argc > 2) {
        printf("ERROR: Incorrect number of operands\n");
    }

    register_all_days();

    // Run all days if nothing is specified.
    if (argc == 1) {
        for (int i = 0; i < 12; i++) run_day(i);
        return 0;
    }

    // Run a specific day. If an invalid day is given, nothing happens.
    for (int i = 0; i < 12; i++) {
        if (strncmp(argv[1], day_options[i], 5) == 0) run_day(i);
    }

    return 0;
}