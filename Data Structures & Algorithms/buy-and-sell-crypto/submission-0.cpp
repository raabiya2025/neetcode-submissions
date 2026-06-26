class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,profit;
        int left=0,right=1;
        while(right<prices.size())
        {
            if(prices[left]<prices[right]){
                profit=prices[right]-prices[left];
                if(profit>maxprofit){
                    maxprofit=profit;
                }
                
                
            }
            else{
                left=right;
            }
            right++;
        }
        return maxprofit;


        
    }
};
