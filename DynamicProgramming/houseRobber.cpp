class Solution {
public:
    int func(vector<int> &nums){
        
        int prev = nums[0];
        int prev2 = 0;
        
        
        for(int i = 1 ; i < nums.size(); i++){
            
        int pick = nums[i] ;
            
            if(i > 1){
                
             pick += prev2;
            }  
            
        
        int notPick = 0 + prev;
            
        int sum = max(pick , notPick);
        
        prev2 = prev;
            
        prev = sum;
                       
  }
        
        return prev;

    }
    int rob(vector<int>& nums) {
        
         return func(nums);
    }
};
