class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0 ;
        int candidate = 0;

        for(auto num : nums){

            if(count == 0){
                candidate = num;
            }

            if(candidate == num){
                count++;
            }

            else count -= 1;
        }
        
        return candidate;
    }
};


//majority element can be more than one in this case ,atmost 2 majority elements can be there.


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;

        int num1 = INT_MIN , num2 = INT_MIN;
        int cnt1 = 0 , cnt2 = 0;

        for(int i = 0 ; i < nums.size() ; i++){

            if(num1 == nums[i]) cnt1++;
            else if(num2 == nums[i]) cnt2++;

            else if(cnt1 == 0){

                num1 = nums[i];
                cnt1 = 1;
            }

            else if(cnt2 == 0){

                num2 = nums[i];
                cnt2 = 1;
            }

            else{

                cnt1--;
                cnt2--;
            }
        }

         cnt1 = 0 , cnt2 = 0; 

        for(int i = 0 ; i < nums.size() ; i++){

            if(num1 == nums[i]){cnt1++;}
            if(num2 == nums[i]) {cnt2++;}
        }

        if(cnt1 > (nums.size() / 3)) ans.push_back(num1);
        if(cnt2 > (nums.size() / 3)) ans.push_back(num2);

        return ans;
    }
};

