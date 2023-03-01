class Solution {
public:
    string reverseWords(string s) {

        string result;

        int i = 0 ; 
        int N = s.length();

        while(i < N){

            while(i < N && s[i] == ' ') i++;
            if(i >= N) break;

           int j = i + 1;

            while(j < N && s[j] != ' ' ) j++;

            string sub = s.substr(i , j-i);

            if(result.length() == 0) result = sub;

            else result = sub + " " + result;

            i = j + 1;
        }

        
        

        return result;
    }
};
