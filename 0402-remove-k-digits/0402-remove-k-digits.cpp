class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        for(char digit:num){
            while(!st.empty() && k>0 && st.top()>digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        //If removals are still left, remove from end
        while(k>0){
            st.pop();
            k--;
        }
        //Build ans
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        //Remove trailing leading zeroes
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        if(ans==""){
            return "0";
        }
        return ans;
    }
};