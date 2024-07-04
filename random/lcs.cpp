#include <bits/stdc++.h>
using namespace std;
int lcs(int A[], int B[], int n, int l)
{
    int dp[n + 1][l + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= l; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][l];
}
int main()
{
    int A[23] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 7};
    int B[10] = {1, 5, 2, 6, 5, 7, 3, 8, 4, 2};
    int n = sizeof(A) / sizeof(A[0]);
    int l = sizeof(B) / sizeof(B[0]);
    int result = lcs(A, B, n, l);
    cout << result << endl;
    return 0;
}