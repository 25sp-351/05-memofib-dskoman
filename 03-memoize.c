#include <stdio.h>

#include "memoize.h"

void memoize_test() {
  memoize_cache_t *my_cache = memoize_init(200, 1);

  long long int user_input = 0;

  for (int scanf_result;
       (printf(">> "), scanf_result = scanf("%lld", &user_input)) != EOF;) {
    memoize_insert(my_cache, user_input);
  }
  memoize_free(my_cache);
}

int main(int argc, char *argv[]) {
  memoize_test();
  return 0;
}