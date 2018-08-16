#include <stdio.h>
#include <stdlib.h>

// define the map callback function
typedef int (*map_cb)(int current);

// map returns an array, so we have to return a pointer to the array
int *map(int *elements, int length, map_cb cb)
{
  int *newArr = malloc(length * sizeof(int));

  for (int index = 0; index < length; index++)
  {
    newArr[index] = cb(elements[index]);
  }

  return newArr;
}

int doubled(int element)
{
  return element * 2;
}

int main(void)
{
  int elements[] = {1, 2, 3, 4, 5, 6};

  //int len = sizeof(elements) / sizeof(int);
  //int len = sizeof(elements) / sizeof(elements[0]);
  int len = *(&elements + 1) - elements;

  int *doubled_elements;

  doubled_elements = map(elements, len, doubled);

  printf("[");
  for (int i = 0; i < len; i++)
  {
    if (i == (len - 1))
    {
      printf("%d]\n", doubled_elements[i]);
    }
    else
    {
      printf("%d, ", doubled_elements[i]);
    }
  }

  return 0;
}

/*
First of all, the compiler knows the array is 16 elements 
(because that's how many in the initializer), so the first line is the same as:
int nums[16] = {3,2,5,6,7,8,23,12,4,60,67,22,122,46,34,23};


What type is `nums[0]`? It's an `int`.

What type is `nums`? It's an `int *`.

What type if `&nums`? Casually, we'd say it was an `int **`. But that's not entirely true.

Since `nums` is declared as an array, the type for 
`&nums` is technically "a pointer to an array of 16 `int`s".

Now in many cases that doesn't matter. But when you do some arithmetic:

int **a = &nums + 0; // A points to array of 16 ints
int **b = &nums + 1; // B points to the next array of 16 ints

Just like how `nums + 0` and `nums + 1` 
point to the zeroth and first elements of the array, `&nums + 0` and `&nums + 1` point to the first array of 16 bytes and the _next_ array of 16 bytes.

(Of course, there is no "next array of 16 bytes" allocated, 
but you can still point to where it _would_ be if there were one.)

Since C packs arrays tightly in memory, 
the next array of 16 bytes starts in RAM directly after the the one you allocated.
*/