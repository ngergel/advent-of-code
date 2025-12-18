// -------------------------------------------------
//	aoc.h
//
//  Registry definition and file data for AoC 2025.
//
//  (c) Noah Gergel 2025
// -------------------------------------------------

#ifndef AOC_H
#define AOC_H


// Function pointer information.
typedef int (*fn_t)(void);
#define MAX_FN 24 // (12 days) * 2

static fn_t all_func[MAX_FN] = {NULL};
static size_t num_fn = 0;

void register_fn(fn_t);
void register_all_days(void);


// Forward decl. for all days and their parts.
int day1_p1(void); int day1_p2(void);
int day2_p1(void); int day2_p2(void);
int day3_p1(void); int day3_p2(void);
int day4_p1(void); int day4_p2(void);
int day5_p1(void); int day5_p2(void);
int day6_p1(void); int day6_p2(void);
int day7_p1(void); int day7_p2(void);
int day8_p1(void); int day8_p2(void);
int day9_p1(void); int day9_p2(void);
int day10_p1(void); int day10_p2(void);
int day11_p1(void); int day11_p2(void);
int day12_p1(void); int day12_p2(void);


// Input file information.
static const char* test_inp = "inputs/test.in";
static const char* day1_inp = "inputs/day1.in";
static const char* day2_inp = "inputs/day2.in";
static const char* day3_inp = "inputs/day3.in";
static const char* day4_inp = "inputs/day4.in";
static const char* day5_inp = "inputs/day5.in";
static const char* day6_inp = "inputs/day6.in";
static const char* day7_inp = "inputs/day7.in";
static const char* day8_inp = "inputs/day8.in";
static const char* day9_inp = "inputs/day9.in";
static const char* day10_inp = "inputs/day10.in";
static const char* day11_inp = "inputs/day11.in";
static const char* day12_inp = "inputs/day12.in";

// Day options for command line.
static const char* day_options[12] = {
    "day1", "day2", "day3", "day4", "day5", "day6",
    "day7", "day8", "day9", "day10", "day11", "day12"
};

#endif