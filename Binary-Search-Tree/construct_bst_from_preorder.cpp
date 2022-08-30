class Solution {
public:
    
    TreeNode* buildBST(vector<int>& preorder , int &index , int upperbound){
        
        //base case.
        
        if(index == preorder.size() || preorder[index] > upperbound) return NULL;
        
        TreeNode* newnode = new TreeNode(preorder[index++]);
        
        newnode -> left = buildBST(preorder , index , newnode -> val);
        
        newnode -> right = buildBST(preorder , index , upperbound);
        
        return newnode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int index = 0 ;
        
       return buildBST(preorder,index,INT_MAX);
    }
};
