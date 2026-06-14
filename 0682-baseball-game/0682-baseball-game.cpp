class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;

        for(string ch:ops){
            if(ch=="C"){
                st.pop();
            }
            else if(ch=="D"){
                st.push(2*st.top());
            }
            else if(ch=="+"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.push(first);

                st.push(first+second);
            }else{
                st.push(stoi(ch));
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};