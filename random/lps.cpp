
#include <iostream>
#include <cstring>
using namespace std;
int longestPalindromeSubseq(int A[], int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][i] = 1; // Every element is a palindrome of length 1
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] == A[j])
            {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Length of longest palindrome subsequence is: " << longestPalindromeSubseq(A, n) << endl;
    return 0;
}
