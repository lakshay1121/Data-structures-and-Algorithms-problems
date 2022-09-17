//find the maximum length subarray having equal no of zeroes and ones.


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
       unordered_map<int,int> mp;
        
       //make all 0's as -1.
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(nums[i] == 0) nums[i] = -1;
            
        }
        
        //main logic.
        
        int sum = 0 , maxlength = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            sum += nums[i];
            
            // if sum == 0 , that means we are having equal numbers of zeroes and one's.
            
            if(sum == 0) 
                
                maxlength = max(maxlength , i + 1);
            
            if(mp.find(sum) != mp.end()){
                
                maxlength = max(maxlength , i - mp[sum]);
            }
            
            else 
                
                mp[sum] = i;
        }
        
        
        return maxlength;
    }
};
