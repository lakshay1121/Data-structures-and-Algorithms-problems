//Memoization.

class Solution {
public:

    int solve(string text1 , string text2 , int ind1 , int ind2,vector<vector<int>> &dp){

        if(ind1 < 0 || ind2 < 0) return 0;

        if(dp[ind1][ind2] != -1 ) return dp[ind1][ind2];


        if(text1[ind1] == text2[ind2]) {

            return dp[ind1][ind2] =  (1 + solve(text1 , text2 , ind1 - 1 , ind2 - 1,dp));
        }

        else {

           return dp[ind1][ind2] = ( 0 + ( max(solve(text1 , text2 , ind1 - 1 , ind2 , dp) , solve(text1 , text2 , ind1 , ind2 - 1 , dp))));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int ind1 = text1.length();
        int ind2 = text2.length();

        vector<vector<int>> dp(ind1 , vector<int> (ind2 , -1));

        solve(text1 , text2 , ind1-1 , ind2-1 , dp);

        return dp[ind1-1][ind2-1];

       
    }
};



//Tabulation . 
