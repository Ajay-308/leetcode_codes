#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long result = 0;
        
        // We use a sliding window technique
        int start=0;
        long long current_sum=0;
        for(int end=0; end<n; end++){
            current_sum +=a[end];
            while(current_sum>x){
                current_sum -=a[start];
                start++;
            }

            if(current_sum==x){
                result++;
                current_sum -= a[start];
                start++;
            }
        }

        
        // for (int l = 0; l < n; ++l) {
        //     long long current_sum = 0;
        //     for (int r = l; r < n; ++r) {
        //         current_sum += a[r];
        //         if (current_sum > x) {
        //             current_sum = 0;
        //         }
        //         if (current_sum != 0) {
        //             result++;
        //         }
        //     }
        // }
        
        cout << result << "\n";
    }

    return 0;
}
