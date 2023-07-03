class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
       int left = 0;
       int right = nums.size()-1;

       vector<pair<int,int>> vec;

       for(int i = 0 ; i < nums.size(); i++){

           vec.push_back({nums[i] , i});
       }

       sort(vec.begin() , vec.end());

       while(left < right){

           int sum = vec[left].first + vec[right].first;

           if(sum == target) return {vec[left].second , vec[right].second};

           else if(sum > target) right--;

           else left++;
       }

       return {-1,-1};
    }
};
