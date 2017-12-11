#include <stdio.h>
#if 0 //1 -> Rotate by 1 element
void leftRotate(int arr[], int d, int n) 
{
	int i; 
	for(i=0; i<d; i++) {
		int t = arr[0]; 
		for(int j=1; j<n; j++)
			arr[j-1] = arr[j];
		arr[n-1] = t;
	}
}
#endif 
#if 1//2-> inplace shifting
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}
void leftRotate(int arr[], int d, int n)
{
	int i, j, k, temp;
	for (i = 0; i < gcd(d, n); i++)
	{
		/* move i-th values of blocks */
		temp = arr[i];
		j = i;
		while(1)
		{
			k = j + d;
			if (k >= n)
				k = k - n;
			if (k == i)
				break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
} 
void rightRotate(int arr[], int d, int n)
{
	int i, j, k, temp;
	for (i = 0; i < gcd(d, n); i++)
	{
		/* move i-th values of blocks */
		temp = arr[i];
		j = i;
		while(1)
		{
			k = j - d;
			if (k < 0)
				k = k + n;
			if (k == i)
				break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
} 
#endif
#if 0//3 -> Reversal
void reverse(int arr[ ], int start, int end)
{
	int temp;
	while(start<end)
	{
		temp = arr[start];
		arr[start++] = arr[end];
		arr[end--] = temp;
	}
}
void leftRotate(int arr[], int d, int n)
{
	reverse(arr, 0, d-1);
	reverse(arr, d, n-1); 
	reverse(arr, 0, n-1);
}
void rightRotate(int arr[], int d, int n)
{
	reverse(arr, 0, (n-d)-1);
	reverse(arr, (n-d), n-1); 
	reverse(arr, 0, n-1);
}
#endif
void printArray(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
}
int main( )
{
	//int arr[] = {1, 2, 3, 4, 5, 6, 7};
	//int d = 2, n = 7;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int d = 3, n = 12;
	//leftRotate(arr, d, n); 
	rightRotate(arr, d, n); 
	printArray(arr, n); 
	getchar( );
	return 0; 
}

