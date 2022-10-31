//memoization.
//t(c) ->O(n*n).
//s(c) -> O(n) +O(n*n).

class Solution {
public:
    
    int func(int row , int col ,int m, vector<vector<int>> &grid,vector<vector<int>> &dp){
                
        if(row == m-1) return grid[row][col];
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int down = grid[row][col] + func(row+1,col,m,grid,dp);
        
        int diagonal = grid[row][col] + func(row+1,col+1,m,grid,dp);
        
        return dp[row][col] = min(down,diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int i = triangle.size();
        
        vector<vector<int>> dp(i,vector<int>(i,-1));
        
        return func(0 , 0 , i,triangle,dp);
    }
};
    
//tabulation.
//
