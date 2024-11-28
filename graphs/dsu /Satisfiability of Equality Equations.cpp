class Solution {
public:
    vector<int> par;
    vector<int> rank;
    
    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]); // Path compression
    }
    
    void unionSets(int x , int y){
        int x_par = find(x);
        int y_par = find(y);
        
        if(x_par == y_par) return; // If they are already in the same set, no need to unite
        
        // Union by rank
        if(rank[x_par] > rank[y_par]){
            par[y_par] = x_par;
        }
        else if(rank[x_par] < rank[y_par]){
            par[x_par] = y_par;
        }
        else {
            par[x_par] = y_par;
            rank[y_par]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        par.resize(26);
        rank.resize(26);

        //lets apply dsu 
        // kaise ye dekhte hai 
        //dekho suru mai har kisi ko individual maan lenge
        // lets take an example 
        //a == b , b==c , c== e and a!=e
        // ab har ek ko individual maan lenge a , b, c,e all 4 has himself as parent
        // a == b means a and b pr union laga denge b ka baap a ho gya 
        // b and c pr bhi laga denge similarly c nd e pr bhi 
        // ab jo graph aayega vo kuch esa dikhega 
        //  a <- c
        //  ^  `
        //  |    `
        //  b      e
        // qb jo last wali condition bol rahi hai a != e 
        // a ka baap khud a hai or e ka baap bhi a hai so how can not equal , retunr false
        for(int i=0;i<26;i++){
            par[i]=i;
        }
        for(string &s:equations){
            if(s[1] == '='){// agar s[1] = hua tp union kardo
                unionSets(s[0] - 'a', s[3] - 'a'); 
            }
        }
        //ab != wale ki bari
        for(string &s:equations){
            if(s[1]=='!'){ // a!=b mtlb a ka baap a hai or b ka baap bhi a hai but yaha fir contion satisfy nhi karegi ki b!=a ye staisfy karne ke liya dono alag baap ki aulaad hona jaruri hai 
                char f = s[0];
                char t = s[3];
                int parf=find(f-'a');
                int part=find(t - 'a');
                if(parf==part) return false; 

            }
        }
        return true;
    }
};
