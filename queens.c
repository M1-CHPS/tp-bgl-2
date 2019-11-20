#include "queens.h"
#include <assert.h>
#include <stdlib.h>

/* check_same_diagonal: returns true iff queens (c0,r0) and (c1,r1) are in the
 * same diagonal. */
static bool check_same_diagonal(const int c0, const int r0,
                                const int c1, const int r1) {
  assert(false);
}

/* check_column_ok: returns true iff the placement (c,r) is ok with all queens
 * to the left of column c already placed in queen_row.
 * precondition: queen_row must be at least of size c. */
static bool check_column_ok(const int c, const int r, const int queen_row[]) {
  assert(false);
}

/* find_available: returns an available row higher than min.
 * If no row is found returns -1 */
static int find_available(const int min, const int n, const bool available[]) {
  assert(false);
}

/* _find_solution: tries to find a solution to the n-queens problems by filling
 * columns from c to n.
 * queen_row contains the row positions for columns lower than c.
 * available contains the available rows to fill columns higher or equal to c.
 */
static bool _find_solution(const int n, const int c, int queen_row[],
                           bool available[]) {
  assert(false);
}

/* find_solution: returns true iff a n-queens solution is found.
 * queens_row is an int array of size n that will be
 * overwritten with the solution.
 *
 * if a solution is found, queens_row[c] will contain the row number for queen
 * at column c.
 * */
bool find_solution(const int n, int queen_row[]) {
  bool available[n];
  for (int i = 0; i < n; i++) {
    available[i] = true;
  }
  return _find_solution(n, 0, queen_row, available);
}
