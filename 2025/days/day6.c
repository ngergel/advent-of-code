// -------------------------------------------------
//	day6.c
//
//  Day 6 solution file.
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

#define MAX_COLS 4000
#define MAX_ROWS 5
#define MAX_LINE 10000


int day6_p1(void) {
    FILE *f = fopen(day6_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    int problems[MAX_ROWS][MAX_COLS];
    int num_rows = 0, num_cols = 0;
    char line[MAX_LINE];
    unsigned long long total_sum = 0;

    memset(problems, 0, sizeof problems);
    while (fgets(line, MAX_LINE, f)) {
        int col = 0;
        char* tok = strtok(line, " \n");

        while (tok) {
            if (tok[0] == '*' || tok[0] == '+') problems[num_rows][col++] = tok[0] == '+' ? 0 : 1;
            else problems[num_rows][col++] = atoi(tok);

            tok = strtok(NULL, " \n");
        }

        num_cols = col > num_cols ? col : num_cols;
        num_rows++;
    }

    for (size_t i = 0; i < num_cols; i++) {
        unsigned long long sum = problems[num_rows - 1][i];

        for (size_t j = 0; j < num_rows - 1; j++) {
            if (problems[num_rows - 1][i]) sum *= problems[j][i];
            else sum += problems[j][i];
        }

        total_sum += sum;
    }

    printf("Part 1 Homework Sum: %lld\n", total_sum);

    fclose(f);
    return 0;
}


int day6_p2(void) {
    FILE *f = fopen(test_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    printf("day6\n");

    fclose(f);
    return 0;
}