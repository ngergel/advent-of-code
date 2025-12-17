// -------------------------------------------------
//	day2.c
//
//  Day 2 solution file.
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


int num_len(long long x) {
    if (x < 0) return -1;
    else if (x == 0) return 1;

    return (int)log10(x) + 1;
}


int day2_p1(void) {
    FILE *f = fopen(day2_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char buf[10000];
    fscanf(f, "%s\n", buf);

    long long total = 0;
    char *token = strtok(buf, ",");
    while (token != NULL) {
        int idx = 0;
        while(token[++idx] != '-');
        token[idx] = 0;

        long long start = strtoll(token, NULL, 10), end = strtoll(token + idx + 1, NULL, 10);
        
        for (long long i = start; i <= end; i++) {
            if (num_len(i) % 2 == 1) continue;
            assert(num_len(i) > 0);
            
            long long len = num_len(i) / 2, p = (long long)pow(10, len);
            if (i / p == i % p) total += i;
        }

        // Get next token.
        token = strtok(NULL, ",");
    }

    printf("Part 1 sum of invalid IDs: %lld\n", total);

    fclose(f);
    return 0;
}


bool invalid_id(long long id) {
    if (num_len(id) == 1) return false;

    for (long long len = 1; len <= num_len(id) / 2; len++) {
        long long p = (long long)pow(10, len);
        long long first = id % p, temp = id;
        bool invalid = true;

        if (num_len(first) + 1 != num_len(p)) continue;

        while (temp != 0 && invalid) {
            if (temp % p != first) invalid = false;
            temp /= p;
        }

        if (invalid) return true;
    }

    return false;
}


int day2_p2(void) {
    FILE *f = fopen(day2_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char buf[10000];
    fscanf(f, "%s\n", buf);

    long long total = 0;
    char *token = strtok(buf, ",");
    while (token != NULL) {
        int idx = 0;
        while(token[++idx] != '-');
        token[idx] = 0;

        long long start = strtoll(token, NULL, 10), end = strtoll(token + idx + 1, NULL, 10);
        
        for (long long i = start; i <= end; i++) {
            if (num_len(i) > 1 && invalid_id(i)) total += i;
        }

        // Get next token.
        token = strtok(NULL, ",");
    }

    printf("Part 2 sum of invalid IDs: %lld\n", total);

    fclose(f);
    return 0;
}