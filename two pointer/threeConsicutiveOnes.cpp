#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<int> A = {1, 1, 0, 0, 0, 1, 1, 1, 0, 0,1,1,1};
    int n = A.size();
    int cnt = 0;
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            cnt++;
            s.push(i);
            if (cnt == 3) {
                // Print the contents of the stack
                cout << "Stack contains indices where 1 appears consecutively 3 times: ";
                while (!s.empty()) {
                    cout << s.top() << " ";
                    s.pop();
                }
                cout << endl;
            }
        } else {
            cnt = 0;
            // Clear the stack
            while (!s.empty()) {
                s.pop();
            }
        }
    }
    
    cout << "No sequence of 3 consecutive 1s found." << endl;
    return 0;
}
