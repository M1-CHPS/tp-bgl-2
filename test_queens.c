#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "queens.c"

static void test_same_diagonal(void **state) {
  assert_false(true);
}

int main(void) {
  int result = 0;
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_same_diagonal),
  };
  result |= cmocka_run_group_tests_name("queens", tests, NULL, NULL);

  return result;
}
