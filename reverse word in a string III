class Solution {
public:
    string reverseWords(string s) {
        istringstream stream(s);
        string word,res;

        while(stream>>word){
            reverse(word.begin(),word.end());
            res+=word+ " ";
        }
        if(!res.empty()){
            res.pop_back();
        }
        
        return res;
    }
};
