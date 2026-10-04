#include<stdio.h>
int main()
{
    long long a,b,n,count;

    // Read range
    printf("Enter starting value: ");
    scanf("%lld",&a);

    printf("Enter ending value: ");
    scanf("%lld",&b);
    // Check every number in the range
    for(n=a;n<=b;n++)
    {
        long long x=n;
        count=0;

        printf("\n%d: ",n);

        // Generate Collatz sequence
        while(x!=1)
        {
            printf("%lld ",x);

            // If even, divide by 2
            if(x%2==0)
                x=x/2;

            // If odd, multiply by 3 and add 1
            else
                x=3*x+1;

            count++;
        }

        printf("1");
        printf("  Steps = %lld",count);
    }
    return 0;
}