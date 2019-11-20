#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

/* we directly include the .c file so we can test static functions */
#include "main.c"

static void test_parse_args(void **state) {
  /* no arg, too many args */
  assert_int_equal(-1, parse_args(1, (char*[]){"queens"}));
  assert_int_equal(-1, parse_args(3, (char*[]){"queens", "1", "2"}));
  /* invalid arg */
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "notanint"}));
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "-10"}));
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "0"}));
  /* valid arg */
  assert_int_equal(153, parse_args(2, (char*[]){"queens", "153"}));
}

int main(void) {
  int result = 0;
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_parse_args),
  };
  result |= cmocka_run_group_tests_name("main", tests, NULL, NULL);

  return result;
}
