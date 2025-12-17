// -------------------------------------------------
//	day3.c
//
//  Day 3 solution file.
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

#define MAX_BANK 200


int highest_jolt(char* bank, int offset) {
    int max_jolt = 0, idx = 0;
    while (bank[++idx] != 0) {
        if (!bank[idx + offset]) break;
        if (bank[idx - 1] > bank[max_jolt]) max_jolt = idx - 1;
    }

    return max_jolt;
}


int day3_p1(void) {
    FILE *f = fopen(day3_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char bank[MAX_BANK];
    int total_joltage = 0;
    while (fgets(bank, MAX_BANK, f)) {
        int idx = highest_jolt(bank, 1);
        int jolt = 10 * (bank[idx] - 48) + (bank[idx + 1 + highest_jolt(bank + idx + 1, 0)] - 48);

        total_joltage += jolt;
    }

    printf("Part 1 total joltage: %d\n", total_joltage);

    fclose(f);
    return 0;
}


int day3_p2(void) {
    FILE *f = fopen(day3_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char bank[MAX_BANK];
    long long total_joltage = 0;
    while (fgets(bank, MAX_BANK, f)) {
        long long jolt = 0, idx = 0, ptr = 0;

        for (int i = 11; i >= 0; i --) {
            idx = highest_jolt(bank + ptr, i);
            jolt = 10 * (jolt + bank[ptr + idx] - 48);
            ptr += idx + 1;
        }

        total_joltage += jolt / 10;
    }

    printf("Part 2 total joltage: %lld\n", total_joltage);

    fclose(f);
    return 0;
}