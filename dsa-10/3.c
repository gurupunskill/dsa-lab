#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int nodes;
	printf ("\n\n\t Enter number of nodes ==> ");
	scanf ("%d", &nodes);
	nodes = log2(nodes);
	printf ("\n\t Height ==> %d \n\n", nodes);
	return 0;
}
