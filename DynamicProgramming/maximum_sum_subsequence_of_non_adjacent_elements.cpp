
//recursion solution.
//t(c) -> O(2^n).
//s(c) -> O(n).

int func(int index , vector<int> &nums){
    
    if(index == 0) return nums[index];
    
    if(index < 0) return 0;
    
    int pick = nums[index] + func(index - 2 , nums);
    
    int notPick = 0 + func(index - 1 , nums);
    
    return max(pick , notPick);
    }
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    return func(n - 1 , nums);
}

//memoization solution.
//t(c) -> O(n).
//s(c) -> O(n) + O(n).


int func(int index , vector<int> &nums,vector<int> &dp){
    
    if(index == 0) return nums[index];
    
    if(index < 0) return 0;
    
    if(dp[index] != -1) return dp[index];
    
    int pick = nums[index] + func(index - 2 , nums,dp);
    
    int notPick = 0 + func(index - 1 , nums,dp);
    
    return dp[index] = max(pick , notPick);
    }
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
   
    vector<int> dp(n , -1);
    return func(n - 1 , nums,dp);
}


//tabulation solution.
//t(c) -> O(n).
//s(c) -> O(n).

int func(int index , vector<int> &nums,vector<int> &dp){
    
     dp[0] = nums[0];
    
     int pick , notPick;
    
     for(int i = 1 ; i < index ; i++){
         
          pick = nums[i];
         
         if(i > 1) pick += dp[i - 2];
         
          notPick = 0 + dp[i - 1];
         
         dp[i] = max(pick , notPick);
         
     }
    return dp[index - 1];
    }
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
   
    vector<int> dp(n , -1);
    return func(n , nums,dp);
}


//space optimization.
//t(c) -> O(n).
//s(c) -> O(1).

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    
    int prev = nums[0] ;
    int prev2 = 0;
    
    for(int i = 1 ; i < n ; i++){
        
        int pick = nums[i] ;
        
        if(i > 1) pick += prev2;
        
        int notPick = 0 + prev;
        
        int curi = max(pick , notPick);
        
        prev2 = prev; 
        prev = curi;
    }

    return prev;
}
