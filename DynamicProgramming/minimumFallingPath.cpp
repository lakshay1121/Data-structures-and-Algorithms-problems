class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> dp(row , vector<int> (col, 0));
        
        
        for(int j = 0 ; j < col ; j++) dp[0][j] = matrix[0][j];
        
        for(int i = 1 ; i < row; i++){
            
            for(int j = 0 ; j < col ; j++){
                
                 //up.
                int up = matrix[i][j] + dp[i-1][j];

                //upleft.
                int upLeft = matrix[i][j];
                
                if(j - 1 >=0 ) upLeft += dp[i-1][j-1];
                
                else upLeft += 1e9;

                //upright.
                int upRight = matrix[i][j];
                
                if(j+1 < col) upRight += dp[i-1][j+1];
                
                else upRight += 1e9;
                
                
                dp[i][j] =  min(up , min(upLeft, upRight));
     
            }
        }
        
        int minAns = 1e9;
        
        for(int j = 0 ; j < col; j++){
            
            minAns = min(minAns , dp[row-1][j]);
        }
        
        return minAns;
        
    }
};
