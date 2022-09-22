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
        
        //time - O(n*m) +)(n*m)
        //space - O(m) + O(n).
        
                
    }
};
        
 //highest optimized.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        
      int rowsize = matrix.size() , colsize = matrix[0].size() , col0 = 1;
        
      for(int i = 0 ; i < rowsize; i++){
          
          if(matrix[i][0] == 0) col0 = 0;
          
          for(int j = 1 ; j < colsize; j++){
              
              if(matrix[i][j] == 0){
                  
                  matrix[i][0] = matrix[0][j] = 0;
              }
          }
      }
        
        
        //iterates backwards.
        
        for(int i = rowsize - 1 ; i >= 0 ; i--){
            
            for(int j = colsize - 1; j >=1 ; j--){
                
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                        
                    matrix[i][j] = 0;
                }
            
                if(col0 == 0){
                    
                    matrix[i][0] = 0;
                }
        }
        
    }
};

        
        

