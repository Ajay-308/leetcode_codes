class Solution {
public:
    // ye humara manacher's algorithm hai --> to find longest palindromic substring in O(N) time
    string longestPalindrome(string s) {
    string T = "^#"; 
    for (char c : s) {
        T += c;
        T += '#';   
    }
    T += '$';       
    
    int n = T.size();
    vector<int> P(n, 0);  
    int C = 0, R = 0;  
    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * C - i;  
        if (i < R) {
            P[i] = min(R - i, P[mirror]);
        }
        while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    int max_len = 0;
    int center_index = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }
    int start = (center_index - max_len) / 2;  
    return s.substr(start, max_len);
        
    }
};
