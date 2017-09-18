// Tower of Hanoi = ToH
// skill method

/*
   I wasn't sure whether the question wanted me to calclate
   minimum steps or visually show how to solve the ToH.
   So, I did both.
*/

#include <stdio.h>


int ToH_n(int n)
{
        if (n == 0)
                return 0;
        return 2*ToH_n(n-1) + 1;
}

void ToH(int n, char init, char middle, char end)
{
        if ( n == 1 )
        {
                printf ("\n Disk 1: %c ==> %c", init, end);
                return;
        }
        ToH (n-1,init,end,middle);
        printf ("\n Disk %d: %c ==> %c", n, init, end);
        ToH (n-1,middle,init,end);
}

int main(int argc, char const *argv[]) {

        int n;
        printf ("\n\t TOWER OF HANOI PROBLEM");
        printf ("\n\n Enter number of disks ==> ");
        scanf ("%d", &n);
        printf ("\n\n Steps to solve the Tower of Hanoi: \n");
        ToH(n,'a','b','c');
        printf ("\n\n Minimum number of steps ==> %d \n\n", ToH_n(n));
        return 0;
}
