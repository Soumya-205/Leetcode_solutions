class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(char ch:s){
            if(ch=='('){
                st.push(0);
            }else{
                int topScore=st.top();
                st.pop();
                int currentScore;
                if(topScore==0){
                    currentScore=1;
                }else{
                    currentScore=2*topScore;
                }
                st.top()+=currentScore;
            }
        }
        return st.top();
    }
};