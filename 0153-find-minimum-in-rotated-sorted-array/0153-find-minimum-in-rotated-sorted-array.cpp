class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;

        while(left<right){
            //calcualte the mis
            int mid=left+(right-left)/2;

            //minimum is on right side
            if(nums[mid]>nums[right]){
                left=mid+1;
            }
            //if min on left side
            else{
                right=mid;
            }
        }
        return nums[left];
    }
};