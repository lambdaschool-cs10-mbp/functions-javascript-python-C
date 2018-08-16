#include <stdio.h>
#include <stdlib.h>

// define the function pointer type to a reduce_cb
typedef int (*reduce_cb) (int accumulator, int current);

// let's define some callbacks
int sum(int a, int b)
{
  return a + b;
}

int product(int a, int b)
{
  return a * b;
}

int reduce(int *args, int length, int memo, reduce_cb cb)
{
  int accumulator = memo;

  // update the accumulated value with the next value in the args array
  for (int i = 0; i < length; i++)
  {
    accumulator = cb(accumulator, *(args+i));
  }
  return accumulator;
}

int main(void)
{
  int arr[] = {3,5,6};

  printf("%d\n", reduce(arr, 3, 0, sum));
  printf("%d\n", reduce(arr, 3, 1, product));
  return 0;
}
