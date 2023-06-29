class Solution {
public:

    void backtrack (vector<int>& nums , int index , vector<vector<int>>& ans ,   vector<int>& curr){

        ans.push_back(curr); // Adding curretn subset to the answer vector.

        //Generate subsets by including elements elements from index to n-1.

        for(int i = index ; i < nums.size(); i++){

            if(i != index && nums[i] == nums[i-1]){
                
                //Duplicate subset case , so we will not include it.
                continue;
            }

            //Without duplicate case , In this we will include our subset.

            curr.push_back(nums[i]);

            backtrack(nums, i + 1 , ans, curr);

            //Now we need to delete the call for the particular element.

            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;

        vector<int> curr;

        backtrack(nums , 0 , ans ,curr);

        return ans;
    }
};
