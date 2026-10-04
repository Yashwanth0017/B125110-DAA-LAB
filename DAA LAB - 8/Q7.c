#include<stdio.h>
int main()
{
    int n,p[100],dp[100],cut[100];
    // Read rod length
    printf("Enter rod length: ");
    scanf("%d",&n);

    // Read prices
    printf("Enter prices: ");
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
        
    dp[0]=0;

    // Find maximum revenue
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;

        // Try every possible first cut
        for(int j=1;j<=i;j++)
        {
            if(p[j]+dp[i-j]>dp[i])
            {
                dp[i]=p[j]+dp[i-j];
                cut[i]=j;
            }
        }
    }
    // Print maximum revenue
    printf("Maximum revenue = %d\n",dp[n]);
    // Print selected pieces
    printf("Pieces: ");
    while(n>0)
    {
        printf("%d ",cut[n]);
        n=n-cut[n];
    }
    return 0;
}