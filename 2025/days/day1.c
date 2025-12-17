// -------------------------------------------------
//	day1.c
//
//  Day 1 solution file.
//
//  (c) Noah Gergel 2025
// -------------------------------------------------

#include <stdio.h>
#include <assert.h>

#include "aoc.h"

int day1_p1(void) {
    FILE *f = fopen(day1_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    int dial = 50, cnt = 0, val;
    char dir;

    // Read in each dial value.
    while (fscanf(f, " %c%d\n", &dir, &val) == 2) {
        dial = (dir == 'L' ? dial - val : dial + val) % 100;
        if (dial == 0) cnt++;
    }

    printf("New password: %d\n", cnt);

    // Close the file.
    fclose(f);
    return 0;
}


int day1_p2(void) {
    FILE *f = fopen(day1_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    int dial = 50, cnt = 0, val;
    char dir;

    // Read in each dial value.
    while (fscanf(f, " %c%d\n", &dir, &val) == 2) {
        cnt += val / 100;
        val %= 100;

        if ((dir == 'L' && (dial - val) <= 0 && dial != 0) || (dir == 'R' && (dial + val) >= 100 && dial != 0)) cnt++;
        dial = ((dir == 'L' ? dial - val : dial + val) % 100 + 100) % 100;
    }

    printf("Correct new password: %d\n", cnt);

    // Close the file.
    fclose(f);
    return 0;
}