class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice=prices[0];
        int maxProfit=0;

        for(int i=0;i<prices.size();i++){  //imagine each day as selling day
             int profit=prices[i]-minPrice; //current profit
             maxProfit=max(maxProfit,profit);//update the maximum profit
             minPrice=min(minPrice,prices[i]); // update minprice             

        }
        return maxProfit;
        
    }
};