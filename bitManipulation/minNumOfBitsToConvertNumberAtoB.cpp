class Solution {
public:
    int minBitFlips(int start, int goal) {

        start = start ^ goal;
        int ans = 0;

        while(start){

            start = start & (start - 1);

            ans++;
        }
        
        return ans;
    
    }
};
