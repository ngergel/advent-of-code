// -------------------------------------------------
//	day5.c
//
//  Day 5 solution file.
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


int day5_p1(void) {
    FILE *f = fopen(test_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    printf("day5\n");

    fclose(f);
    return 0;
}


int day5_p2(void) {
    FILE *f = fopen(test_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    printf("day5\n");

    fclose(f);
    return 0;
}