//recursion solution.
//t(c) -> O(2^(n*m))
//s(c) -> O( m - 1 + n - 1) -> recursion stack space.

class Solution {
public:
    
    int func(int row ,int col){
        
        if(row == 0 && col == 0) return 1;
        
        if(row < 0 || col < 0) return 0;
        
        int upDir = func(row - 1 , col);
        
        int leftDir = func(row , col - 1);
        
        return (upDir + leftDir);
    }
    int uniquePaths(int m, int n) {
        
       return func(m-1 ,n-1);
    }
};

//memoization solution.
//t(c) -> O(m*n).
//s(c) -> O( m - 1 + n - 1) + O(m*n).

class Solution {
public:
    
    int func(int row ,int col,vector<vector<int>> &dp){
        
        if(row == 0 && col == 0) return 1;
        
        if(row < 0 || col < 0) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int upDir = func(row - 1 , col,dp);
        
        int leftDir = func(row , col - 1,dp);
        
        return dp[row][col] = (upDir + leftDir);
    }
    int uniquePaths(int m, int n) {
        
       vector<vector<int>> dp(m , vector<int> (n ,-1));
        
       return func(m-1 ,n-1,dp);
    }
};


//tabulation solution.
//t(c) -> O(m*n).
//s(c) -> O(m*n).

class Solution {
public:

    int uniquePaths(int m, int n) {
        
       int dp[m][n];
        
       for(int i = 0 ; i < m; i++){
           
           for(int j = 0 ; j < n; j++){
               
               if(i == 0 && j == 0) dp[i][j] = 1;
               
               else {
               int up = 0 , left = 0;
               
               if(i > 0)  up = dp[i-1][j];
               
               if(j > 0)  left = dp[i][j-1];
               
               dp[i][j] = (up + left);
                   
               }
           }
       }
        
       return dp[m-1][n-1];
    }
};


//t(c) -> O(m*n).
//s(c) -> O(n).

class Solution {
public:

    int uniquePaths(int m, int n) {
        
       vector<int> prev(n,0);
        
       for(int i = 0 ; i < m; i++){
           
           vector<int> cur(n,0);
           
           for(int j = 0 ; j < n; j++){
               
               if(i == 0 && j == 0) cur[j] = 1;
               
               else {
               int up = 0 , left = 0;
               
               if(i > 0)  up = prev[j];
               
               if(j > 0)  left = cur[j-1];
               
               cur[j] = (up + left);
                   
               }
           }
           
           prev = cur;
       }
        
       return prev[n-1];
    }
};
