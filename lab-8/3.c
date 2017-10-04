#include <stdio.h>
void main()
{
	int h;
	printf ("\n\n\t Enter height of tree ==> ");
	scanf ("%d", &h);
	printf ("\n\t Number of nodes ==> %d \n\n", (1<<h)-1);
}
