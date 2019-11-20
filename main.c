#include <err.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "queens.h"
#include "rdtsc.h"

/* print_board: prints the queen_row array */
static void print_board(const int n, const int queen_row[n]) {
  for(int i = 0; i < n; i++) {
    printf("%d ", queen_row[i]);
  }
  printf("\n");
}

/* parse command line arguments
 * a single strictly positive number is expected
 * for other inputs -1 is returned
 * */
static int parse_args(int argc, char * argv[]){
  if (argc != 2) {
    return -1;
  }

  int n = strtol(argv[1], NULL, 10);
  if (n <= 0) {
    return -1;
  }
  return n;
}

/* solve the n-queens problem
 * usage: queens <n>, n must be an integer greater than 0
 * */
#ifndef CMOCKA_H_
int main(int argc, char *argv[]) {
  int n = parse_args(argc, argv);
  if (n == -1) {
    errx(1, "usage: queens <n>, n must be an integer greater than 0\n");
  }
  int queen_row[n];
  bool ok = find_solution(n, queen_row);
  if (!ok) {
    errx(1, "no solution could be found for n = %d\n", n);
  }
  print_board(n, queen_row);
  return 0;
}
#endif
