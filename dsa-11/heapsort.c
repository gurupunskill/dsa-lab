#include <stdio.h>
int parent(int i)
{
    return (i/2);
}

int left(int i)
{
    return (2*i + 1);
}

int right(int i)
{
    return (2*i + 2);
}

void max_heapify (int* A, int i, int n)
{
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < n && A[l] > A[i])
        largest = l;
    else largest = i;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;

        max_heapify(A, largest, n);
    }
}

void build_max_heap (int* A, int n)
{
    // Check page 159 for complexity explanation
    // O(n)
    for (int i = (n/2) - 1; i >= 0; i--)
        max_heapify(A,i,n);
}

void heapsort(int *A, int n)
{
    build_max_heap(A, n);
    for (int i = n-1; i >= 0; i--)
    {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        max_heapify(A,0,i);        
    }
}

void main()
{
    int A[7] = {5,4,3,9,4,2,1};
    printf ("\n\n Unsorted ==> ");
    for (int i = 0; i < 7; i++)
        printf ("%d", A[i]);
    heapsort(A, 7);

    printf ("\n Sorted ==> ");
    for (int i = 0; i < 7; i++)
        printf ("%d", A[i]);
    printf ("\n\n");
}
