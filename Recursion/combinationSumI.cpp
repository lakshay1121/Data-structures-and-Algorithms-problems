class Solution {
public:

    void backtrack(int index, vector<int>& nums , int target , vector<int>& ds , vector<vector<int>>& ans){

        if(index == nums.size()){

            if(target == 0){

                ans.push_back(ds);

            }
                return;
        }

        //pick.

        if(nums[index] <= target){

            ds.push_back(nums[index]);

            backtrack(index , nums , target - nums[index] , ds , ans);

            ds.pop_back();

        }
            backtrack(index + 1 , nums ,target , ds , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;

        vector<int> ds;

        backtrack(0 , candidates , target , ds , ans);

        return ans;
        
    }
};
