class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int first = m-1;
        int second = n-1;
        int k = m+n-1;

        while(first >= 0 && second >= 0){

            if(nums1[first] > nums2[second]){

                nums1[k] = nums1[first];

                k-- , first--;
            }

            else{

                nums1[k] = nums2[second];
                second--,k--;
            }
        }

        while(first >= 0){

            nums1[k--] = nums1[first--];
        }

        while(second >= 0){

            nums1[k--] = nums2[second--];
        }
    }
};
