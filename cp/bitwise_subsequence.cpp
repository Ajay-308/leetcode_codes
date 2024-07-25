#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> LCS(const vector<int>& A) {
    int N = A.size();
    
    if (N == 0) {
        return {0, {}};
    }
    
    vector<int> dp(N, 1);
    vector<int> prev(N, -1);
    
    for (int i = 1; i < N; ++i) {
        if (A[i-1] < A[i] && (A[i-1] & A[i]) * 2 < (A[i-1] | A[i])) {
            dp[i] = dp[i-1] + 1;
            prev[i] = i-1;
        }
    }
    
    // Find the index of the maximum value in dp
    int max_length = *max_element(dp.begin(), dp.end());
    int index = distance(dp.begin(), max_element(dp.begin(), dp.end()));
    
    // Reconstruct the longest continuous increasing subsequence
    vector<int> lis;
    while (index != -1) {
        lis.push_back(A[index]);
        index = prev[index];
    }
    
    reverse(lis.begin(), lis.end());
    
    return {max_length, lis};
}

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    auto result = LCS(A);
    
    // Output the result
    cout << "max-length:-" << result.first << endl;
    cout << "list:-";
    for (int num : result.second) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
