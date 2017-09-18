#include <stdio.h>
#include <time.h>

// power3 would calculate x^n in 2log3(n) where log3 is log base 3.
long int power3(int x, int n)
{
        if ( n == 0 )
                return 1;
        if ( n == 1 )
                return x;
        if ( n == 2 )
                return x*x;

        int rem_n = n%3;
        int new_n = n - rem_n;
        long int ans = power3(x, new_n/3);
        long int rem_ans = power3(x, rem_n);
        return ans*ans*ans*rem_ans;
}

// power2 would calculate it in lg(n).
long int power2(int x, int n)
{
        if ( n == 0)
                return 1;
        if ( n == 1)
                return x;
        int rem_n = n%2;
        int new_n = n - rem_n;
        long int ans = power3(x, new_n/2);
        long int rem_ans = power3(x, rem_n);
        return ans*ans*rem_ans;
}

int main()
{
        printf ("\n\n\t\t POWER EVALUATION IN BASE 3");
        int x, n;
        char k;

        printf ("\n\n\t Enter x and n (x^n) ==> ");
        scanf ("%d%c%d",&x,&k,&n);

        clock_t start = clock(), diff;
        printf ("\n\n\t The value using base-3 evaluation is %ld", power3(x,n));
        diff = clock() - start;
        printf("\n\t Time taken: %ld microseconds", diff);

        start = clock();
        printf ("\n\n\n\t The value using base-2 evaluation is %ld", power2(x,n));
        diff = clock() - start;
        printf("\n\t Time taken: %ld microseconds \n\n\n", diff);

        return 0;
}
