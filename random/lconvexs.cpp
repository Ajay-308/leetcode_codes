#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longestConvexSubsequence(vector<int> A)
{
    int n = A.size();
    vector<int> lis(n, 1), lds(n, 1);
    // Longest increasing subsequence
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    // Longest decreasing subsequence
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[i] > A[j])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    // Find longest convex subsequence
    int max_len = 0;
    for (int i = 0; i < n; i++)
    {
        max_len = max(max_len, lis[i] + lds[i] - 1);
    }
    return max_len;
}
int main()
{
    vector<int> A = {1, 2, 5, 4, 3, 6, 7, 9, 8};
    cout << longestConvexSubsequence(A) << endl;
}