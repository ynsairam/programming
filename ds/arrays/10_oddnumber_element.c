#include <stdio.h>
int getOddOccurrence(int ar[], int ar_size)
{
     int i;
     int res = 0; 
     for (i=0; i < ar_size; i++)     {
	printf("[%d ^ %d] = %d\n", res, ar[i], res ^ ar[i]);
        res = res ^ ar[i];
     }
      
     return res;
}
 
/* Diver function to test above function */
int main()
{ 
     int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
     int n = sizeof(ar)/sizeof(ar[0]);
     printf("%d\n", getOddOccurrence(ar, n));
     return 0;
}
