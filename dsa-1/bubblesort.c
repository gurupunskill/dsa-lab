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

	int temp;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n-1; j++ )
		{
			if ( a[j+1] < a[j] )
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	printf ( "\n\n\t Sorted array (ascending order) ==> ");
	for ( i = 0; i < n; i++ )
	{
		printf("%d ", *(a+i));
	}
	printf("\n\n");
	
}
