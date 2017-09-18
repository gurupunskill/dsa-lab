// Kth smallest element

/*
    This program is optimized for the worst case complexity.
    I use recursive merge sort in O(nlogn) to sort the array, returning the kth element.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Merge sort is implemented from the algorithm given in CLRS.
// Sentinel card didn't work, so I implemented it without the sentinel.

void merge(int* A, int p, int q, int r)
{
        int n1 = q-p+1;
        int n2 = r-q;

        int L[n1], R[n2];
        int i, j, k;

        for ( i = 0; i < n1; i++ )
                L[i] = A[p+i];
        for ( j = 0; j < n2; j++ )
                R[j] = A[q+j+1];

        i = 0;
        j = 0;
        k = p;

        while (i < n1 && j < n2)
        {
                if (L[i] <= R[j])
                {
                        A[k] = L[i];
                        i++;
                }
                else
                {
                        A[k] = R[j];
                        j++;
                }
                k++;
        }
        while (i < n1)
        {
                A[k] = L[i];
                i++;
                k++;
        }
        while (j < n2)
        {
                A[k] = R[j];
                j++;
                k++;
        }
        return;
}

void merge_sort(int* A, int p, int r)
{
        int q;
        if (p<r)
        {
                q = (p+r)/2;
                merge_sort(A,p,q);
                merge_sort(A,q+1,r);
                merge(A,p,q,r);
        }
}

int function_1 (int*a, int n, int k)
{
        /* Uses merge sort to sort the array. Returns kth element. */
        merge_sort(a,0,n-1);
        return a[k-1];
}

int main(int argc, char const *argv[])
{
        int n;
        printf ("\n\n\t\t Kth Smallest Element");
        printf ("\n\n\t Enter number of elements ==> ");
        scanf ("%d",&n);
        int a[n];
        printf ("\n\t Enter %d elements ==> ", n);
        int i;
        for (i = 0; i < n; i++)
                scanf("%d",&a[i]);
        int k;
        printf ("\n\t Enter k ==> ");
        scanf ("%d",&k);
        if (k > n || k < 1)
        {
                printf ("\n\n\t Error: Invalid K !!!");
                return -1;
        }
        printf ("\n\n\t Kth smallest element is %d\n\n", function_1(a,n,k));
}
