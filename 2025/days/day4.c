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

#define MAX_N 200


int boundry_count(char grid[MAX_N][MAX_N], int x, int y) {
    if (x < 0 || y < 0 || x >= MAX_N || y >= MAX_N) return 0;
    
    int cnt = 0;
    if (x > 0 && grid[x - 1][y] == '@') cnt++;
    if (y > 0 && grid[x][y - 1] == '@') cnt++;
    if (x < MAX_N - 1 && grid[x + 1][y] == '@') cnt++;
    if (y < MAX_N - 1 && grid[x][y + 1] == '@') cnt++;

    if (x > 0 && y > 0 && grid[x - 1][y - 1] == '@') cnt++;
    if (x > 0 && y < MAX_N - 1 && grid[x - 1][y + 1] == '@') cnt++;
    if (x < MAX_N - 1 && y > 0 && grid[x + 1][y - 1] == '@') cnt++;
    if (x < MAX_N - 1 && y < MAX_N - 1 && grid[x + 1][y + 1] == '@') cnt++;

    return cnt;
}


int day4_p1(void) {
    FILE *f = fopen(day4_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char grid[MAX_N][MAX_N];
    int num_rows = 0, num_cols, movable_rolls = 0;

    memset(grid, 0, sizeof grid);
    while (fgets(grid[num_rows++], MAX_N, f));
    num_cols = strlen(grid[0]);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (grid[i][j] == '@' && boundry_count(grid, i, j) < 4) movable_rolls++;
        }
    }

    printf("Part 1 movable rolls: %d\n", movable_rolls);

    fclose(f);
    return 0;
}


int day4_p2(void) {
    FILE *f = fopen(day4_inp, "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char grid[MAX_N][MAX_N];
    int num_rows = 0, num_cols, movable_rolls = 0;
    bool moved = true;

    memset(grid, 0, sizeof grid);
    while (fgets(grid[num_rows++], MAX_N, f));
    num_cols = strlen(grid[0]);

    while (moved) {
        moved = false;

        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (grid[i][j] == '@' && boundry_count(grid, i, j) < 4) {
                    movable_rolls++;
                    grid[i][j] = '.';
                    moved = true;
                }
            }
        }
    }

    printf("Part 2 movable rolls: %d\n", movable_rolls);

    fclose(f);
    return 0;
}