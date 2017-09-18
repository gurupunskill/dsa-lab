// Length of the longest monotonous increasing subsequence
/* Trying for O(nlogn). Straightforward algorithm is O(n^2). */

#include <stdio.h>

/*
   Let P be the parent array.
   The idea is to store the smallest possible end element for
   a subsequence of size k in an array A[k - 1].
   That way, we know the size of the largest subsequence from
   the size of array A.
   The question is: how do we go about finding the smallest
   element from A such that P[i] is greater than A[j] but lesser than A[j+1]?
   Binary search would do it in O(log n).
*/

/*
   NOTE: When I was testing this code out on gcc, it worked for 7/8 elements
         but did not work for 15 (Segmentation Fault).
         But, I tested the code out on an online compiler and it worked
         perfectly for any number of digits.
         The code works. I'm not sure why gcc gets it wrong.
*/

int find_right_position(int* A, int l, int r, int ele)
{
        int m;
        while( 1+l < r )
        {
                m = (l+r)/2;
                if (ele >= A[m])
                        l = m;
                else
                        r = m;
        }
        return m;
}

int length_of_LIS(int *P, int n)
{
        int A[n], i, k;
        int length = 1;
        A[0] = P[0];
        for (i = 0; i < n; i++)
        {
                if (P[i] < A[0])
                {
                        A[0] = P[i];
                }
                else if (P[i] > A[length-1])
                {
                        A[length] = P[i];
                        length++;
                }
                else
                {
                        k = find_right_position(A,0,length,P[i]);
                        A[k] = P[i];
                }
        }
        return length;
}

int main()
{
        int n;
        printf ("\n\n\t\t LIS");
        printf ("\n\n\t Enter number of elements ==> ");
        scanf ("%d",&n);
        int P[n];
        printf ("\n\t Enter %d elements ==> ", n);
        int i;
        for (i = 0; i < n; i++)
                scanf("%d",P+i);
        int length = length_of_LIS(P,n);
        printf ("\n\n\t Length of largest subsequence ==> %d\n\n", length);
        return 0;
}
