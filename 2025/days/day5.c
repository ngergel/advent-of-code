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

#define MAX_N 250
#define MAX_LINE 50


struct interval {
    unsigned long long start, end;
};


bool in_interval(long long x, struct interval* i) {
    return x >= i->start && x < i->end;
}


bool interval_lt(struct interval* x, struct interval* y) {
    if (x->start < y->start) return true;
    else if (x->start == y->start && x->end < y->end) return true;
    return false;
}


void insertion_sort(struct interval arr[MAX_N], size_t n) {
    for (int i = 1; i < n; i++) {
        struct interval key = arr[i];
        int j = i - 1;

        while (j >= 0 && interval_lt(&key, &arr[j])) arr[j + 1] = arr[j], j--;

        arr[j + 1] = key;
    }
}


unsigned long long max_ull(unsigned long long a, unsigned long long b) {
    return a >= b ? a : b;
}


int day5_p1(void) {
    FILE *f = fopen(day5_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    struct interval arr[MAX_N];
    char line[MAX_LINE];
    size_t n = 0;

    while (fgets(line, MAX_LINE, f)) {
        if (strlen(line) == 1) break;

        char *first_str = strtok(line, "-"), *second_str = strtok(NULL, "-");
        unsigned long long start = strtoull(first_str, NULL, 10), end = strtoull(second_str, NULL, 10);

        arr[n++] = (struct interval){start, end + 1};
    }

    insertion_sort(arr, n);

    int fresh = 0;
    while (fgets(line, MAX_LINE, f)) {
        long long id = strtoll(line, NULL, 10);

        for (int i = 0; i < n; i ++) {
            if (in_interval(id, &arr[i])) {
                fresh++;
                break;
            }
        }
    }

    printf("Part 1 # of fresh ingredients: %d\n", fresh);

    fclose(f);
    return 0;
}


int day5_p2(void) {
    FILE *f = fopen(day5_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    struct interval arr[MAX_N];
    char line[MAX_LINE];
    size_t n = 0;

    while (fgets(line, MAX_LINE, f)) {
        if (strlen(line) == 1) break;

        char *first_str = strtok(line, "-"), *second_str = strtok(NULL, "-");
        unsigned long long start = strtoull(first_str, NULL, 10), end = strtoull(second_str, NULL, 10);

        arr[n++] = (struct interval){start, end + 1};
    }

    insertion_sort(arr, n);

    unsigned long long fresh = 0;
    for (size_t i = 0; i < n; i++) {
        unsigned long long s = arr[i].start, e = arr[i].end;
        
        while (i + 1 < n && arr[i + 1].start < arr[i].end) {
            e = max_ull(e, max_ull(arr[i].end, arr[i + 1].end));
            i++;
        }

        fresh += e - s;
    }

    printf("Part 2 # of fresh ingredients: %lld\n", fresh);

    fclose(f);
    return 0;
}