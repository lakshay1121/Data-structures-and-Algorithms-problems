class Solution{
    public:
  
    
    int kthSmallest(int arr[], int l, int r, int k) {
        
       
        
        priority_queue<int> pq;
        
        //step 1 
        
        for(int i = 0 ; i < k ; i++){
            
            pq.push(arr[i]);
        }
        
        //step2. 
        //push rest elements which are smaller than the heap.top into the heap.
        
        for(int i  = k ; i <= r; i++){
            
            int element = arr[i];
            
            if(element < pq.top()){
                
                pq.pop();
                
                pq.push(element);
            }
        }
        
        //step3 . 
        
        return pq.top();
        
        
        
        
    }
};
