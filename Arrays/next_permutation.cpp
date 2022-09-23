class Solution {
public:
    

    void nextPermutation(vector<int>& nums) {
        
       int index1 ,index2 ; 
        
       for(index1 = nums.size() - 2 ; index1 >= 0; index1--){
           
           if(nums[index1] < nums[index1 + 1]){
               
               break;
               
           }
       }
        
        
        if(index1 < 0) reverse(nums.begin() , nums.end());
        
        else{
        for(index2 = nums.size() - 1 ; index2 > index1 ; index2--){
            
            if(nums[index2] > nums[index1]){
                
                break;
            }
        }
            
            
            
         swap(nums[index1] , nums[index2]);
         reverse(nums.begin() + index1 + 1 , nums.end());
        
        
    }
    }
};
