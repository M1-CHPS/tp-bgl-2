#!/bin/sh

# FIXME: Replace this by a Makefile

# First build the program
clang-6.0 -std=c99 -O3 queens.c main.c -o queens

# Then build the tests
clang-6.0 -std=c99 -O0 -g test_main.c -o test_main -lcmocka
clang-6.0 -std=c99 -O0 -g test_queens.c -o test_queens -lcmocka

# Finally run the tests
./test_main
./test_queens
