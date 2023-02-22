class Solution {
public:

 int solve(vector<int>& cost ,int index , vector<int>& dp){

    if(index == 0 || index == 1) return cost[index];

    if(dp[index] != -1) return dp[index];

    dp[index] = (cost[index] + min(solve(cost , index - 1 , dp) , solve(cost , index - 2 , dp)));

  return dp[index];

 }
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n , -1);

        int firstCall = solve(cost , n-1 ,dp);
        int secondCall = solve(cost , n-2 ,dp);

        return (min(firstCall , secondCall));
        
    }
};
