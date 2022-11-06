//memoization.
//t(c) -> O(m*n).
//s(c) -> O(n) + O(n*m).

int func(vector<vector<int>>&matrix, int row,int col,int i,int j,vector<vector<int>>&dp){
    
    if(j < 0 || j >= col) return -1e9;
    
    if(i == 0) return matrix[i][j];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int leftDiag = matrix[i][j] + func(matrix,row,col,i-1,j-1,dp);
    
    int down = matrix[i][j] + func(matrix,row,col,i-1,j,dp);
    
    int rightDiag = matrix[i][j] + func(matrix,row,col,i-1,j+1,dp);
    
    return dp[i][j] = max(leftDiag , max(down,rightDiag));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    
    int row = matrix.size();
    int col = matrix[0].size();
    
    vector<vector<int>> dp(row,vector<int>(col,-1));
    
    int maxi = -1e9;
    
   for(int j=0 ; j<col;j++){
    
       int a = func(matrix, row , col ,row-1,j,dp);
       
       if(a > maxi){
           
           maxi = a;
       }
        
     }
    
    return maxi;
}


//tabulation.
//t(c)->O(m*n).
//t(c)->O(m*n).




int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    
    int row = matrix.size();
    int col = matrix[0].size();
    
    int dp[row][col];
    
    for(int j = 0 ; j < col ; j++){
        
        dp[0][j] = matrix[0][j];
    }
    
    for(int i = 1; i < row ; i++){
        
        int leftDiag,rightDiag;
        for (int j = 0 ; j < col ; j++){
            
            leftDiag = matrix[i][j];
             
            if(j-1 >= 0)   leftDiag += dp[i-1][j-1];
            else leftDiag += -1e9;
    
            int down = matrix[i][j] + dp[i-1][j];
            
            rightDiag = matrix[i][j];
    
            if(j+1 < col) rightDiag += dp[i-1][j+1];
            else rightDiag += -1e9;
    
            dp[i][j] = max(leftDiag , max(down,rightDiag));
            
        }
    }
    int maxi = dp[row-1][0];
    
   for(int j=1 ; j < col;j++){
    
       maxi = max(maxi, dp[row-1][j]);
   }
    
    return maxi;
}
        
        
