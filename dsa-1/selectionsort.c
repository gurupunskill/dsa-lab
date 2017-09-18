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
	
}
