
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);

        
        iota(indices.begin(), indices.end(), 0);
        //iota fill kardega apni indices ko increasing order mai
        stack<int> st;
        // sorting karunga us order mai jo phele aaya mere postions wale vector mai
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });

        for (int currentIndex : indices) {
            bool survived = true;
            // jab mera stack ka top and health of i equal hai enery collison and ded
            while (!st.empty() && directions[st.top()] == 'R' && directions[currentIndex] == 'L') {
                if (healths[st.top()] == healths[currentIndex]) {
                    survived = false;
                    healths[st.top()] = 0;
                    healths[currentIndex] = 0;
                    st.pop();
                    break;
                } else if (healths[st.top()] > healths[currentIndex]) {
                    //jab mera stakc ka top bada hai or chota wala ded ho gya
                    healths[st.top()]--;
                    healths[currentIndex] = 0;
                    survived = false;
                    break;
                } else {
                     //jab mera stack ka top chota hai to chota wala ded means stack ka top
                    healths[currentIndex]--;
                    healths[st.top()] = 0;
                    st.pop();
                }
            }
            if (survived) {
                st.push(currentIndex);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};
