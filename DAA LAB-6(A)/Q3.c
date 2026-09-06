#include <stdio.h>
#include <string.h>
int main() {
    char a[100], b[100];
    scanf("%s", a);
    scanf("%s", b);
    int n = strlen(a);
    int m = strlen(b);

    int dp[100][100] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}