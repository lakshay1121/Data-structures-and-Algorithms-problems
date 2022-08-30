class Solution {
public:
    
    void inorder(TreeNode* root , vector<int> & InorderToBST){
        
        if(root == NULL) return;
        
        inorder(root -> left , InorderToBST);
        
        InorderToBST.push_back(root -> val);
        
        inorder(root -> right , InorderToBST);
        
    }
    
    
    TreeNode* InorderToBalanced(int start , int end , vector<int> &InorderToBST){
        
        //base case.
        
        if(start > end) return NULL;
        
        int mid = (start + end) / 2;
        
        TreeNode* newRoot = new TreeNode(InorderToBST[mid]);
        
        newRoot -> left = InorderToBalanced(start , mid - 1, InorderToBST);
        
        newRoot -> right = InorderToBalanced(mid + 1 , end, InorderToBST);
        
        return newRoot;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> InorderToBST;
        
        inorder(root , InorderToBST);
        
        int start = 0;
        
        int end = InorderToBST.size() - 1;
        
        return InorderToBalanced(start , end, InorderToBST);
    }
};
