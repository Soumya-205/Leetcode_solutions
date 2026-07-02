class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n),right(n);
        stack<int>st;

        //previous smaller element
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=i+1;
            }else{
                left[i]=i-st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        //next smaller element
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n-i;
            }else{
                right[i]=st.top()-i;
            }
            st.push(i);
        }
        long long ans=0;
        int mod=1000000007;
        for(int i=0;i<n;i++){
            long long contribution=(1LL* arr[i]*left[i]*right[i])%mod;
            ans=(ans+contribution)%mod;
        }
        return ans;
    }
};