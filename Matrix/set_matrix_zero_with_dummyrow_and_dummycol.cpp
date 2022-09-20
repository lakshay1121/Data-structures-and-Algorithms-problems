class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> rowdummy(matrix.size() , 1);
        
        vector<int> coldummy(matrix[0].size() , 1);
        
        for(int i = 0 ; i < matrix.size() ; i++){
            
            for(int j = 0 ; j < matrix[0].size(); j++){
                
                
                if(matrix[i][j] == 0){
                    
                    rowdummy[i] = 0 ;
                    coldummy[j] = 0;
                }
            }
        }
        
        
          for(int i = 0 ; i < matrix.size() ; i++){
            
            for(int j = 0 ; j < matrix[0].size(); j++){
                
                
                if(rowdummy[i] == 0 || coldummy[j] == 0){
                    
                    matrix[i][j] = 0;
                }
            }
        }

        return;
        
    }
};
