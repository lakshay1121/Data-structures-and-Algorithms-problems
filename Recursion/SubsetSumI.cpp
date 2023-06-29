
class Solution
{
public:

    void helperSubset(int index , vector<int>&arr , int sum , vector<int>& ans ){
        
        if(index < 0){
            
            ans.push_back(sum);
            
            return;
        }
        
        //pick.
        
        helperSubset(index-1, arr , sum+arr[index] , ans);
        
        //notpick.
        
        helperSubset(index-1, arr , sum , ans);
        
        
    }

    vector<int> printSubsets(vector<int> arr , int size ){
         
         vector<int> ans;
         
         helperSubset(size-1 , arr , 0 , ans);
         
         return ans;
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        vector<int> ans = printSubsets(arr , N);
        
        return ans;
    }
};

