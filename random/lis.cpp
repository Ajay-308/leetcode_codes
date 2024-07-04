#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int longest_increasing_subsequence_length(vector<int> &A)
{
    int n = A.size();
    vector<int> lis(n, 1);
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
    return *max_element(lis.begin(), lis.end());
}
int main()
{
    vector<int> A = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 7};
    cout << longest_increasing_subsequence_length(A) << endl;
    return 0;
}