//recursion solution.
//t(c) -> O(n*4)*3
//s(c) -> O(n*3).

int func(int day , int last , vector<vector<int>> &points){
    
    if(day == 0){
        
        int maxi = 0 ; 
        
        for(int task = 0 ; task < 3; task++){
            
            if(task != last)
            
               maxi = max(maxi , points[0][task]);
        }
        
        return maxi;
    }
    
    int maxi = 0 ; 
    
    for(int task = 0 ; task < 3 ; task++){
        
        if(task != last){
        
        int point = points[day][task] + func(day - 1 , task , points);
        
        maxi = max(maxi , point);
            
        }
    }
    
    return maxi;
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return func(n-1 , 3 , points);
}



//memoization
//t(c) -> if there are n-2 overlapping subproblems in the recursion tree itself , then the T(c) -> will be O(n*4)*3.
//s(c) -> O(n) + O(n*4).


int func(int day , int last , vector<vector<int>> &points,vector<vector<int>> &dp){
    
    if(day == 0){
        
        int maxi = 0 ; 
        
        for(int task = 0 ; task < 3; task++){
            
            if(task != last)
            
               maxi = max(maxi , points[0][task]);
        }
        
        return maxi;
    }
    
    if(dp[day][last] != -1) return dp[day][last];
    
    int maxi = 0 ; 
    
    for(int task = 0 ; task < 3 ; task++){
        
        if(task != last){
        
        int point = points[day][task] + func(day - 1 , task , points,dp);
        
        maxi = max(maxi , point);
            
        }
    }
    
    return dp[day][last] = maxi ;
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    
    vector<vector<int>> dp(n , vector<int> (4,-1));
    return func(n-1 , 3 , points,dp);
}
