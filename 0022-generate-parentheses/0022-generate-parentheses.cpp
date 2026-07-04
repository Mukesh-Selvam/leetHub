class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string s="";
        genpar(s,0,0,n,res);
        return res;
    }
    void genpar(string& s,int open,int close,int n,vector<string>& res){
        if(s.length()==2*n){
            res.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            genpar(s,open+1,close,n,res);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            genpar(s,open,close+1,n,res);
            s.pop_back();
        }
    }
};