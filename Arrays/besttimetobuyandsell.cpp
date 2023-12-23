class Solution {
public:
    int maxProfit(vector<int>& prices) {

       int mini = prices[0];
       int maxProfit = 0;

       for(int i = 1 ; i < prices.size() ; i++){

           int cost = prices[i] - mini;
           maxProfit = max(cost , maxProfit);
           mini = min(mini , prices[i]);
       }

       return maxProfit;
        
    }
};
