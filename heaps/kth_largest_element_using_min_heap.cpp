class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int start = 0 ; 
        
        int end = nums.size() - 1;
        
        priority_queue<int , vector<int> , greater<int>> pq;
        
        for(int i = start ; i < k ; i++){
            
            pq.push(nums[i]);
        }
        
        for(int i = k ; i <= end; i++){
            
            if(pq.top() < nums[i]){
                
                pq.pop();
                
                pq.push(nums[i]);
            }
        }
        
        
        return pq.top();
        
    }
};
