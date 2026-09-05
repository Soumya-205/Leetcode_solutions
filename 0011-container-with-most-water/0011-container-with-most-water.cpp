class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int j=n-1;
        int i=0;
        int maxWater=0;

        while(i<j){
            int w=(j-i);
            int length=min(height[i], height[j]);
            int area=w*length;
            maxWater = max (maxWater, area);

            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxWater;
    }  
};