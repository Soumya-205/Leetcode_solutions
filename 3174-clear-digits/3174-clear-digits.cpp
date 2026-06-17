class Solution {
public:
    string clearDigits(string s) {
        string st;
        for(char ch:s){
            if(isdigit(ch)){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(ch);
            }
        }
        return st;
    }
};