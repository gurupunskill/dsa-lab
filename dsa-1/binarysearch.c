#include<stdio.h>
#include<stdlib.h>

main()
{
	int n,i,j,*a;
	printf ("\n\t Enter the number of elements ==> ");
	scanf ("%d",&n);
	a = malloc(n*sizeof(int));
	printf ("\n\t Enter %d elements ==> ", n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d", a+i);
	}
	
	int temp, smal, pos;
	for ( i = 0; i < n; i++ )
	{
		smal = *(a+i);
		pos = i;
		for ( j = i+1; j < n; j++ )
		{
			if ( a[j] <= smal )
			{
				smal = *(a+j);
				pos = j;
			}
		}
		temp = *(a+i);
		*(a+i) = smal;
		*(a+pos) = temp;
	}
	printf ( "\n\n\t Sorted array (ascending order) ==> ");
	for ( i = 0; i < n; i++ )
	{
		printf("%d ", *(a+i));
	}
	printf("\n\n");
	
	
	
	int low, high, mid, flag;
	int ele;
	printf ("\n\t Enter the element to be searched ==> ");
	scanf ("%d",&ele);
	
	low = 0;
	high = n;
	flag = 0;
	
	while ( low < high )
	{
		mid = (int)((low+high)/2);
		if ( a[mid] == ele )
		{
			flag = 1;
			printf("\n\n\t Element found !");
			break;
		}
		if ( ele > a[mid] )
		{
			low = mid;
		}
		if ( ele < a[mid])
		{
			high = mid;
		}
	}
	
	if ( flag == 0)
		{
		printf("\n\n\t Element not found !");
	}
	
	
	
}
