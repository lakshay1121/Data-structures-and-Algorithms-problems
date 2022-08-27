class Solution {
public:
    
   bool solve(TreeNode* root , TreeNode* mini , TreeNode* maxi){
       
       if(root == NULL) return true;
       
       if( maxi && root -> val >= maxi -> val ||  mini && root -> val <= mini -> val) return false;
           
       
       
       else  return solve(root -> left , mini, root) && solve(root -> right , root , maxi);
       
   }
    bool isValidBST(TreeNode* root) {
        
       
        
       return solve(root , NULL, NULL);
    }
};
