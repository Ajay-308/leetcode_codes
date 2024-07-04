#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longest_alternating_subsequence_length(vector<int> &A)
{
    int n = A.size();
    vector<int> las(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((A[i] < A[j] && (i - j) % 2 == 0) || (A[i] > A[j] && (i - j) % 2 == 1))
            {
                las[i] = max(las[i], las[j] + 1);
            }
        }
    }
    return *max_element(las.begin(), las.end());
}
int main()
{
    vector<int> A = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 7};
    cout << longest_alternating_subsequence_length(A) << endl;
    return 0;
}