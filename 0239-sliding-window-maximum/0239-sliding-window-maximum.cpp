class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int>dq;

        for(int i=0;i<nums.size();i++){

            //remove the indices outside current window
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            //remove smaller elements from the back
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            //Add the current index
            dq.push_back(i);
            //Store the maximum if the first window is over
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};