class Solution {
public: 
    bool isSametree(TreeNode* root, TreeNode* subRoot){

         if(root == NULL && subRoot == NULL) return true;
        if(root != NULL && subRoot == NULL) return false;
        if(root == NULL && subRoot != NULL) return false;

        bool valueCheck = root -> val == subRoot -> val;
        
        bool left = isSametree(root -> left , subRoot -> left);
        bool right = isSametree(root -> right , subRoot -> right);

        return left && right && valueCheck;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot == NULL) return true;
        if(root == NULL && subRoot != NULL) return false;

        if(isSametree(root , subRoot)) {
            return true;
        }
        
       bool left =  isSubtree(root -> left, subRoot);
       bool right =  isSubtree(root -> right , subRoot);

       return (left || right);
        
    }
};
