#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memoize.h"

#define NOT_CACHED -1

memoize_cache_t *memoize_init(int capacity, int dbg_flag) {
  memoize_cache_t *cache = malloc(sizeof(memoize_cache_t));
  cache->data = malloc(sizeof(memoize_value_t) * capacity);
  for (int i = 0; i < capacity; i++) {
    cache->data[i] = -1;
  }

  cache->size = 0;
  cache->capacity = capacity;
  cache->dbg_flag = dbg_flag;

  if (memoize_debug_flag(cache) > 0) {
    printf("dbg: cache initialized\n");
  }
  return cache;
}

void memoize_free(memoize_cache_t *cache) {
  if (memoize_debug_flag(cache) > 0) {
    printf("dbg: freeing cache\n");
  }
  free(cache);
}

int memoize_check(memoize_cache_t *cache, memoize_value_t data) {
  // this works

  if (memoize_cache_size(cache) == 0) {
    if (memoize_debug_flag(cache) > 0) {
      printf("dbg: '%lld' not found; cache empty\n", data);
    }
    return NOT_CACHED;
  }

  for (int index = 0; index < memoize_cache_size(cache); index++) {
    if (cache->data[index] == data) {
      if (memoize_debug_flag(cache) > 0) {
        printf("dbg: '%lld' is in the cache\n", data);
      }

      return index;
    }
  }
  if (memoize_debug_flag(cache) > 0) {
    printf("dbg: '%lld' not found\n", data);
  }
  return NOT_CACHED;
}

int memoize_insert(memoize_cache_t *cache, memoize_value_t data) {
  // this does not work

  int cache_check_index = memoize_check(cache, data);

  if (cache_check_index == NOT_CACHED) {
    // strange behavior: when attempting to add the second string, the string at
    // index 0 is replaced by the new string
    //
    // adding entries manually line by line works as expected
    // i.e.
    // cache->data[0] = "23523";
    // cache->data[1] = "6645";
    // cache->data[2] = "44";
    cache->data[memoize_cache_size(cache)] = data;
    cache->size++;
  }

  memoize_print_cache(cache); // remove later
  return memoize_cache_size(cache) - 1;
}

int memoize_cache_size(memoize_cache_t *cache) { return cache->size; }

int memoize_cache_capacity(memoize_cache_t *cache) { return cache->capacity; }

int memoize_debug_flag(memoize_cache_t *cache) { return cache->dbg_flag; }

void memoize_print_cache(memoize_cache_t *cache) {
  for (int index = 0; index < memoize_cache_size(cache); index++) {
    printf("%d. %lld\n", index, cache->data[index]);
  }
}