class Solution {
public:
    
     void RightViewRecursive(TreeNode* root , vector<int> &ans , int lvl){
    
    if(root == NULL) return;
    
    if(lvl == ans.size()) ans.push_back(root -> val);
         
     RightViewRecursive(root -> right , ans , lvl + 1);
    
    RightViewRecursive(root -> left , ans, lvl + 1);
  
}
    
    vector<int> rightSideView(TreeNode* root) {
    
   
           vector<int> ans;


           RightViewRecursive(root , ans , 0);

           return ans;
        
    }
};
