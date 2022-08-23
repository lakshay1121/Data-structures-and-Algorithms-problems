class Solution {
public:
    
        void createMapping(vector<int> &inorder ,int start , int end , map<int,int>& nodeToIndex){
        
        for(int i =  start; i <= end ; i++){
            
            nodeToIndex[inorder[i]] = i;
        }
        
        
    }
    
    TreeNode* solve(vector<int> &post , vector<int> &in , int &index , int inorderstart , int inorderend , int postsize,map<int,int> &nodeToIndex){
        
        //base case.
        
        if(index < 0 || inorderstart > inorderend){
            
            return NULL;
        }
        
        int element = post[index--];
        
        TreeNode* root = new TreeNode(element);
        
        int position = nodeToIndex[element];
        
        
       //make right call first then the first call.
        
        root -> right = solve(post , in , index, position + 1 , inorderend , postsize,nodeToIndex);
        
             root -> left = solve(post , in ,index ,inorderstart , position - 1 , postsize , nodeToIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        
         
        int inorderstart = 0;
        
        int inorderend = inorder.size() - 1;
        
        int n = postorder.size();
        
        int index = n - 1;
        
        map<int,int> nodeToIndex;
        
        
        createMapping(inorder,inorderstart , inorderend , nodeToIndex);
        
        TreeNode* ans = solve(postorder, inorder , index, inorderstart , inorderend ,n , nodeToIndex);
        
        return ans;
    }
};
