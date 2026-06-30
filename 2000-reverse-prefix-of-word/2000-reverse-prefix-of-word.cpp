class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char>st;
        int n=word.length();
        int i=0;
        bool b=true;
        while(i<n){
            if(word[i]==ch){
                st.push(word[i]);
                b=false;
                break;
            }
            st.push(word[i]);
            i++;
        }
        i=0;
        if(b){
            return word;
        }
        while(!st.empty()){
            word[i]=st.top();
            st.pop();
            i++;
        }
        return word;
    }
};