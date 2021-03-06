#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void get_matrix (int **a, int m, int n)
{
	int i, j;
	printf ( "\n\t Enter Matrix ==>" );
	for ( i = 0; i < m; i++ )
	{
		printf ("\n\n\t Enter Row %d (%d elements) ==> ", i+1, n);
		for ( j = 0; j < n; j++ )
			scanf("%d", &a[i][j]);
	}
}

void display_matrix (int **a, int m, int n)
{
	int i, j;
	printf ( "\n\n\t Matrix ==> \n\t" );
	for ( i = 0; i < m; i++ )
	{
		for ( j = 0; j < n; j++ )
			printf("%4d", a[i][j]);
		printf("\n\n\t");
	}
}

int is_diagonal (int **a, int m, int n)
{
	int i, j, k;
	k = a[0][0]; 
	for ( i = 1; i < m; i++ )
	{
		if ( a[i][i] != k )
		{
			return 1;
		}
	}
	if ( k == 0 )
		return 0;
	
	return 1;
}

bool is_second_diagonal (int **a, int m, int n)
{
	int i, j, k;
	for ( i = 0; i < m; i++ )
		if ( a[i][n-i-1] == 0 )
		{
			return false;
		}
	return true;
}




bool z_checker ( int **a, int m, int n )
{
	int i, j;
	bool dia = is_second_diagonal (a,m,n);
	
	if (dia)
	{
		for ( i = 1; i < m-1; i++ )
			for ( j = 0; j < n; j++ )
			{
				if ( i + j != n - 1 )
					if (a[i][j] != 0)
						return false;
			}
		return true;
	}
	else return false;	
}

void display_z (int **a, int m, int n )
{
	int i, j, sum = 0;
	printf ( "\n\n\t Z Matrix ==> \n\n\t" );
	for ( i = 0; i < m; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( (i!=0) && (i!= m-1) && ( i + j != n-1 ))
				printf ("    ");
			else
			{
				printf("%4d", a[i][j]);
				sum += a[i][j];			
			}		
		}		
		printf("\n\n\t");
	}
	printf ("\n\n Sum = %d \n\n", sum);
}

void checker (int **a, int m, int n)
{
	int i, j;
	int dia = is_diagonal (a,m,n);
	bool upper = true, lower = true;
	for ( i = 0; i < m; i++ )
		for ( j = 0; j < m; j++ )
		{
			if ( j > i )
			{
				if ( a[i][j] != 0 )
					lower = false;
			}
			if ( i > j )
			{
				if (a[i][j] != 0 )
					upper = false;
			}
		}
	
	if ( upper && lower && dia )
		printf ("\n\n\t The given matrix is a diagonal matrix");
	else if ( upper && dia == 0 && !lower)
		printf ("\n\n\t The given matrix is an upper triangle matrix");
	else if (lower && dia == 0 && !upper)
		printf ("\n\n\t The given matrix is a lower triangle matrix");
	else
		printf ("\n\n\t The matrix is normal.");

	printf ("\n\n\n");
	
}

int main()
{
	int m, n, i;
	char c;
	printf ("\n\n\t Enter size of matrix (MxN) ==> ");
	scanf ("%d%c%d", &m, &c, &n );
	
	if ( m!=n )
	{
		printf ("\n\n\t Not a square matrix!");
		return 0;	
	}

	int **a = (int**) malloc (m*sizeof(int *));
	for ( i = 0; i < m; i++ )
		a[i] = (int*) malloc (n*sizeof(int));

	get_matrix (a,m,n);
	display_matrix(a,m,n);
	checker (a,m,n);
	if (z_checker(a,m,n))
		display_z(a,m,n);
	
	return 0;
}
