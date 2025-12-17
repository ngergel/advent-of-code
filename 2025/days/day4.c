// -------------------------------------------------
//	day4.c
//
//  Day 4 solution file.
//
//  (c) Noah Gergel 2025
// -------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#include "aoc.h"


int day4_p1(void) {
    FILE *f = fopen(test_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    printf("day4\n");

    fclose(f);
    return 0;
}


int day4_p2(void) {
    FILE *f = fopen(test_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }


    fclose(f);
    return 0;
}