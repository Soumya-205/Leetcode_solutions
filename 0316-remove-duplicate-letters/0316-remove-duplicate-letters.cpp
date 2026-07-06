class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26, 0);
        vector<bool>visited (26, false);

        //count frequency of each character
        for(char ch:s){
            freq[ch-'a']++;
        }
        stack<char>st;

        for(char ch:s){
            //current character is being processed
            freq[ch-'a']--;
            //already present in stack
            if(visited[ch-'a']){
                continue;
            }

            //remove character if they appear later
            while(!st.empty() && st.top()>ch && freq[st.top()-'a']>0){
                visited[st.top()-'a']=false;
                st.pop();
            }
            st.push(ch);
            visited[ch-'a']=true;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};