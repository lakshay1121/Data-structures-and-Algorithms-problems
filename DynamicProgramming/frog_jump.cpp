//simple recursion.
//t(c) -> O(n).
//s(c) -> O(n).


int func(int ind , vector<int> &heights){
    
    if(ind == 0) return 0;
    
    int left = func(ind - 1,heights) + abs(heights[ind] - heights[ind - 1]);
    
    int right = INT_MAX;
    
    if(ind > 1) right = func(ind - 2,heights) + abs(heights[ind] - heights[ind - 2]);
    
    return min(left , right);
}
int frogJump(int n, vector<int> &heights)
{
  
    return func(n - 1 , heights);
}

//using memoization , 

//t(c) -> O(n).
//s(c) -> O(n).


int memoization(int ind , vector<int> &heights,vector<int>& dp){
    
    if(ind == 0) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    
    int left = memoization(ind - 1,heights,dp) + abs(heights[ind] - heights[ind - 1]);
    
    int right = INT_MAX;
    
    if(ind > 1) right = memoization(ind - 2,heights,dp) + abs(heights[ind] - heights[ind - 2]);
    
    return dp[ind] = min(left , right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1 , -1);
    return memoization(n - 1 , heights , dp);
}


//using tabulation. 

//t(c) -> O(n)
//s(c) -> O(n).

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n , 0);
    
    dp[0] = 0 ; 
    
    for(int i = 1 ; i<n ; i++){
        
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        
        if(i > 1) ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            
        dp[i] = min(fs , ss);
    }
    
    return dp[n - 1];
}


//space optimization.

//t(c) -> O(n).
//s(c) -> O(1).

int frogJump(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2 = 0 ;
    
    for(int i = 1 ; i<n ; i++){
        
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        
        if(i > 1) ss = prev2 + abs(heights[i] - heights[i - 2]);
            
        int curi = min(fs , ss);
        
        prev2 = prev;
        prev = curi;
    }
    
    return prev;
}
