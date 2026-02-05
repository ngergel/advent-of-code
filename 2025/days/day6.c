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
        unsigned long long res = problems[num_rows - 1][i];

        for (size_t j = 0; j < num_rows - 1; j++) {
            if (problems[num_rows - 1][i]) res *= problems[j][i];
            else res += problems[j][i];
        }

        total_sum += res;
    }

    printf("Part 1 Homework Sum: %lld\n", total_sum);

    fclose(f);
    return 0;
}


bool space_col(char problems[MAX_ROWS][MAX_COLS], int num_rows, int col) {
    for (size_t i = 0; i < num_rows; i++) {
        if (problems[i][col] != ' ') return false;
    }

    return true;
}


int col_to_int(char problems[MAX_ROWS][MAX_COLS], int num_rows, int col) {
    char val[MAX_ROWS];
    memset(val, 0, sizeof val);

    for (size_t i = 0, pos = 0; i < num_rows - 1; i++) {
        if (problems[i][col] == ' ') continue;
        val[pos++] = problems[i][col];
    }

    return atoi(val);
}


int day6_p2(void) {
    FILE *f = fopen(day6_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char problems[MAX_ROWS][MAX_COLS];
    int num_rows = 0, num_cols = 0;
    char line[MAX_LINE];
    unsigned long long total_sum = 0;

    memset(problems, 0, sizeof problems);
    while (fgets(line, MAX_LINE, f)) {
        int col = 0;
        
        while (line[col++] != '\n') {
            problems[num_rows][col - 1] = line[col - 1];
        }

        num_cols = col > num_cols ? col : num_cols;
        num_rows++;
    }

    int col = num_cols - 2;
    while (col >= 0) {
        if (space_col(problems, num_rows, col)) col--;

        // Scan ahead to get the operator
        int offset = 0;
        while (col - offset >= 0 && !space_col(problems, num_rows, col - offset)) offset++;
        if (col - offset == 0) offset++;

        bool op = problems[num_rows - 1][col - offset + 1] == '*';
        unsigned long long res = op;

        for (size_t i = 0; i < offset; i++) {
            if (op) res *= col_to_int(problems, num_rows, col - i);
            else res += col_to_int(problems, num_rows, col - i);
        }

        total_sum += res;
        col -= offset;
    }

    printf("Part 2 Homework Sum: %lld\n", total_sum);

    fclose(f);
    return 0;
}