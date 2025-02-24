#include "fib.h"

long long int fib(int n) { return fib_helper(n); }

long long int fib_helper(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}