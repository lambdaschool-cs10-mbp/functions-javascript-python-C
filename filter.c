#include <stdio.h>
#include <stdlib.h>
typedef int (*filter_cb)(int current);

int *filter(int *elements, int length, int *returned_length, filter_cb cb)
{
  int *newArr = malloc(length * sizeof(int));

  int i = 0;
  for (int index = 0; index < length; index++)
  {
    // we only add items to the newArr that pass our cb
    if (cb(elements[index]))
    {
      newArr[i] = elements[index];
      i++;
      *returned_length = i;
    }
  }

  return newArr;
}

int evens(int element)
{
  return element % 2 == 0;
}

int odds(int element)
{
  return element % 2;
}

int biggerThan3(int element)
{
  return element > 3;
}

int main(void)
{
  int elements[] = {1, 2, 3, 4, 5, 6};

  // length of array
  int len = *(&elements + 1) - elements;

  int *even_arr;
  int *odd_arr;
  int *big3;

  // the returned length
  int even_arr_len = 0;
  int odd_arr_len = 0;
  int big_len = 0;

  // run the functions
  even_arr = filter(elements, len, &even_arr_len, evens); // the & on the even_arr_len is passing in the pointer address
  odd_arr = filter(elements, len, &odd_arr_len, odds);    // the & on the even_arr_len is passing in the pointer address
  big3 = filter(elements, len, &big_len, biggerThan3);    // the & on the even_arr_len is passing in the pointer address

  printf("Even Numbers\n");
  printf("[");
  for (int i = 0; i < even_arr_len; i++)
  {
    if (i == (even_arr_len - 1))
    {
      printf("%d]\n", even_arr[i]);
    }
    else
    {
      printf("%d, ", even_arr[i]);
    }
  }

  printf("Odd Numbers\n");
  printf("[");
  for (int i = 0; i < odd_arr_len; i++)
  {
    if (i == (odd_arr_len - 1))
    {
      printf("%d]\n", odd_arr[i]);
    }
    else
    {
      printf("%d, ", odd_arr[i]);
    }
  }

  printf("Numbers bigger than 3\n");
  printf("[");
  for (int i = 0; i < big_len; i++)
  {
    if (i == (big_len - 1))
    {
      printf("%d]\n", big3[i]);
    }
    else
    {
      printf("%d, ", big3[i]);
    }
  }

  return 0;
}