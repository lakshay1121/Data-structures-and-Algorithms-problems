

//search in rotated and sorted array I.

class Solution {
public:

    int binarySearch(vector<int>& nums , int target){

        int low = 0 ; 
        int high = nums.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;

            else if(nums[mid] >= nums[low]) {

                if(target >= nums[low] && target < nums[mid]){

                    high = mid - 1;
                }

                else{

                    low = mid + 1;
                }
            }

            else{

                if(target > nums[mid] && target <= nums[high]){

                    low = mid + 1;
                }

                else{

                    high = mid - 1;
                }
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int ans = binarySearch(nums , target);

        return ans;
    }
};


// search in a sorted array and rotated array where duplicates can be there.

class Solution {
public:

    bool binarySearch(vector<int>& nums, int target){

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return true;

            if(nums[mid] == nums[low] && nums[mid] == nums[high]){

                low++;
                high--;
                continue;
            }

            else if(nums[mid] >= nums[low]){

                if(target >= nums[low] && target < nums[mid]){

                    high = mid - 1;
                }

                else{

                    low = mid + 1;
                }
            }

            else{

                if(target > nums[mid] && target <= nums[high]){

                    low = mid + 1;
                }

                else{

                    high = mid - 1;
                }
            }
        }

        return false;
    }
    bool search(vector<int>& nums, int target) {

        bool ans = binarySearch(nums , target);
        
        return ans;
    }
};
