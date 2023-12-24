//T(C) -> O(N)
//S(C) -> O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefix(n, 1), postfix(n , 1) , ans(n, 1);

        for(int i = 1 ; i < n ; i++){

            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i = n-2 ; i >= 0 ; i--){

            postfix[i] = postfix[i+1] * nums[i+1];
        }

        for(int i = 0 ; i < n ; i++){

            ans[i] = prefix[i] * postfix[i];
        }

        return ans;

    }
};
