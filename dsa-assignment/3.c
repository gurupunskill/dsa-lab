// Find missing number

/*
   There are n elements, from 0 to n-1.
   One element is missing ==> n-1 elements are entered.
   Sn = n*(n-1)/2 will give me the sum of the proper array.
   Sn - Sum(Array) ==> element
*/

#include <stdio.h>

int main()
{
        int n;
        printf ("\n\n\t\t Find Missing Element");
        printf ("\n\n\t Enter number of elements ==> ");
        scanf ("%d",&n);
        int P[n - 1];
        int Sn = (n-1)*(n)*0.5;
        printf ("\n\t Enter %d elements ==> ", n - 1);
        int i;
        for (i = 0; i < n-1; i++)
        {
                scanf("%d",P+i);
                Sn -= P[i];
        }
        printf ("\n\n\t The missing element is ==> %d \n\n", Sn);
        return 0;
}
