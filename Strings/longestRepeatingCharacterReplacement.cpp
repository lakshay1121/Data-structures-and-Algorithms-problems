class Solution {
public:
    int characterReplacement(string s, int k) {

        int start = 0 , maxFreq = 0 , maxLen = 0;
        unordered_map<char , int> freq;

        for(int end = 0 ; end < s.size(); end++){

            freq[s[end]]++;

            maxFreq = max(maxFreq , freq[s[end]]);

            // windowSize - maxFreq <= k.


            while((end-start+1) - maxFreq > k){

                freq[s[start]]--;
                start++;
            }

            maxLen = max(maxLen , end-start+1);
        }

        return maxLen;
        
    }
};
