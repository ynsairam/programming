/* Program for finding out majority element in an array */
# include<stdio.h>
# define bool int
 
int findCandidate(int *, int);
bool isMajority(int *, int, int);
 
/* Function to print Majority Element */
void printMajority(int a[], int size)
{
  /* Find the candidate for Majority*/
  int cand = findCandidate(a, size);
  printf("findCandidate returned %d\n", cand);
  /* Print the candidate if it is Majority*/
  if (isMajority(a, size, cand))
    printf(" %d \n", cand);
  else
    printf("No Majority Element\n");
}
 
/* Function to find the candidate for Majority */
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    int i;
    for (i = 1; i < size; i++)
    {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}
 
/* Function to check if the candidate occurs more than n/2 times */
bool isMajority(int a[], int size, int cand)
{
    int i, count = 0;
    for (i = 0; i < size; i++)
      if (a[i] == cand)
         count++;
    if (count > size/2)
       return 1;
    else
       return 0;
}
 
/* Driver function to test above functions */
int main()
{
    //int a[] = {1, 3, 3, 1, 2};
    int a[] = {2, 2, 3, 5, 2, 2, 6};
    int size = (sizeof(a))/sizeof(a[0]);
    printMajority(a, size);
 //   getchar();
    return 0;
}
