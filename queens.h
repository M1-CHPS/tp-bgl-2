#include <stdbool.h>

/* find_solution: returns true iff a n-queens solution is found.
 * queens_row is an int array of size n that will be
 * overwritten with the solution.
 *
 * if a solution is found, queens_row[c] will contain the row number for queen
 * at column c.
 * */
bool find_solution(const int n, int queen_row[]);
