#include <stdio.h>
#include <stdlib.h>

//gcc -ggdb -o test test.c -Wl,-wrap,malloc
void* __real_malloc(size_t bytes);

int main()
{
   int *p = NULL;
   int i = 0;

   p = malloc(100*sizeof(int));

   for (i=0; i < 100; i++)
       p[i] = i;

   free(p);
   return 0;
}

void* __wrap_malloc(size_t bytes)
{
      printf("12345\n");
      return __real_malloc(bytes);
}
