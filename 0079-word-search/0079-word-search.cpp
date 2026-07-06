class Solution {
public:
    bool existword(int i,int j,int k,vector<vector<char>>& board,string& word){
        // base case
        if(i>=board.size() || i<0 || j<0 || j>=board[0].size()) return false;
        
        if(word[k] !=board[i][j]) return false;
        if(k==word.size()-1) return true;
        char ch=board[i][j];
        board[i][j]='*';
        //right
        bool a1=existword(i,j+1,k+1,board,word);
        //left
        bool a2=existword(i,j-1,k+1,board,word);
        //up
        bool a3=existword(i-1,j,k+1,board,word);
        //bottom 
        bool a4=existword(i+1,j,k+1,board,word);

        board[i][j]=ch;
        return a1 || a2 || a3 || a4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    if(existword(i,j,0,board,word)) return true;
                }
            }
        }
        return false;
    }

};