#include <stdio.h>

#include "fib.h"
#include "memoize.h"

#define CACHE_TEST_SIZE 10000

long long int (*fib_ptr)(int n) = &fib;

void memoize_test() {
  memoize_cache_t *my_cache = memoize_init(200, 0);
  long long int fib_map[CACHE_TEST_SIZE];

  long long int user_input = 0;

  for (int scanf_result;
       (printf(">> "), scanf_result = scanf("%lld", &user_input)) != EOF;) {
    int cache_index = memoize_insert(my_cache, user_input);
    if (cache_index == -1) {
      fib_map[user_input] = fib_ptr(user_input);
    }
    printf("%s", "<fib value> -> <precalculated value>\n");
    for(int index = 0; index < memoize_cache_size(my_cache); index++) {
      long long int cache_value = my_cache->data[index];
      printf("%lld -> [%lld]\n",  cache_value, fib_map[cache_value]);
    }
  }
  memoize_free(my_cache);
}

int main(int argc, char *argv[]) {
  memoize_test();
  return 0;
}
