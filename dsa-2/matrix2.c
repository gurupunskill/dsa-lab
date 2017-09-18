#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
	int m, n, i, j, k, ch;
	char c;
	printf ("\n\n\t Enter size of matrix (MxN) ==> ");
	scanf ("%d%c%d", &m, &c, &n );
	
	if ( m!=n )
	{
		printf ("\n\n\t Not a square matrix!");
		return 1;	
	}
	
	printf ( "\n\t 1. Upper triangle matrix \n\t 2. Lower Triangle matrix \n\t 3. Diagonal matrix \n\t Enter the type of matrix being entered ==> ");
	scanf ( "%d", &ch );
	
	if ( ch == 1 || ch == 2 )
		k = n * (n-1) * 0.5;
	else if ( ch == 3 )
		k = n;
	else return 1;
	
	int *a = (int *) malloc ( k*sizeof(int));
	
	if ( ch == 1 )
	{
		printf ( "\n\t Enter Matrix ==>" );
		int count = 0, x;		
		for ( i = 0; i < m; i++ )
		{
			printf ("\n\n\t Enter Row %d (%d elements) ==> ", i+1, n);
			for ( j = 0; j < n; j++ )
			{
				scanf ("%d", &x);
				if ( j > i )
				{
					a[count] = x;
					count++;
				}
			}
		}
		
		count = 0;
		printf ( "\n\n\t Matrix ==> \n\t" );
		for ( i = 0; i < m; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				if ( j > i )
				{
					printf("%4d", a[count]);
					count++;				
				}
				else printf("%4d", 0);			
			}			
			printf("\n\n\t");
		}
	}
	
	if ( ch == 2 )
	{
		printf ( "\n\t Enter Matrix ==>" );
		int count = 0, x;		
		for ( i = 0; i < m; i++ )
		{
			printf ("\n\n\t Enter Row %d (%d elements) ==> ", i+1, n);
			for ( j = 0; j < n; j++ )
			{
				scanf ("%d", &x);
				if ( i > j )
				{
					a[count] = x;
					count++;
				}
			}
		}
		
		count = 0;
		printf ( "\n\n\t Matrix ==> \n\t" );
		for ( i = 0; i < m; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				if ( i > j )
				{
					printf("%4d", a[count]);
					count++;				
				}
				else printf("%4d", 0);			
			}			
			printf("\n\n\t");
		}
	}
	
	if ( ch == 3 )
	{
		printf ( "\n\t Enter Matrix ==>" );
		int count = 0, x;		
		for ( i = 0; i < m; i++ )
		{
			printf ("\n\n\t Enter Row %d (%d elements) ==> ", i+1, n);
			for ( j = 0; j < n; j++ )
			{
				scanf ("%d", &x);
				if ( j == i )
				{
					a[count] = x;
					count++;
				}
			}
		}

		count = 0;
		printf ( "\n\n\t Matrix ==> \n\t" );
		for ( i = 0; i < m; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				if ( j == i )
				{
					printf("%4d", a[count]);
					count++;				
				}
				else printf("%4d", 0);			
			}			
			printf("\n\n\t");
		}
	}

		

	return 0;
}
