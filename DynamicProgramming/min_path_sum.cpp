//memoization.
//t(c) -> O(m*n).
//s(c) -> O(m*n) + O(m +n).

class Solution {
public:
    
    int recur(int row , int col , vector<vector<int>> &grid,vector<vector<int>> &dp){
        
        
        if(row == 0 && col == 0) return grid[row][col];
        
        if(row < 0 || col < 0) return 1e9;
        
        if(dp[row][col] != -1) return dp[row][col];
        
         int left = grid[row][col] + recur(row , col-1,grid,dp);
        
         int up = grid[row][col] + recur(row-1,col,grid,dp);
        
        return dp[row][col] = min(left , up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int i = grid.size();
        
        int j = grid[0].size();
        
        vector<vector<int>> dp(i,vector<int>(j,-1));
        
        return recur(i-1 , j-1 , grid,dp);
    }
};

//tabulation.
//t(c) -> O(m*n).
//s(c) -> O(m*n).

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int i = grid.size();
        
        int j = grid[0].size();
        
        int dp[i][j];
        
        for(int row = 0 ; row < i ; row++){
            
            for(int col = 0 ; col < j ; col++){
                
                if(row == 0 && col == 0) dp[row][col] = grid[row][col];
                
                else if(row < 0 || col < 0) dp[row][col] = 1e9;
                
                else{
                    
                    int left = 0 , up = 0;
                    
                    left = grid[row][col];
                    
                    if(col>0) left += dp[row][col-1];
                    
                    else left += 1e9;
                    
                    up = grid[row][col];
                    
                    if(row>0) up += dp[row-1][col];
                    
                    else up += 1e9;
                    
                    dp[row][col] = min(left,up);
                }
            }
        }
        return dp[i-1][j-1];
    }
};


//space optimization.
//t(c) -> O(m*n).
//s(c) -> O(n).
