class Solution {
public:
    
    int findPosition(int element , vector<int> &in ,int size){
        
        for(int i =  0; i <= size ; i++){
            
            if(in[i] == element) return i;
        }
        
        return - 1;
    }
    
    TreeNode* solve(vector<int> &pre , vector<int> &in , int &index , int inorderstart , int inorderend , int presize){
        
        //base case.
        
        if(index >= presize || inorderstart > inorderend){
            
            return NULL;
        }
        
        int element = pre[index++];
        
        TreeNode* root = new TreeNode(element);
        
        int position = findPosition(element , in , inorderend);
        
        
        //make left and right call.
        
        root -> left = solve(pre , in ,index ,inorderstart , position - 1 , presize);
        
        root -> right = solve(pre , in , index, position + 1 , inorderend , presize);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int inorderstart = 0;
        int inorderend = inorder.size() - 1;
        int n = preorder.size();
        int index = 0;
        
        TreeNode* ans = solve(preorder, inorder , index, inorderstart , inorderend ,n);
        
        return ans;
    }
};


//in this approach we are finding the position of element in inorder array , in O(n) time.

//the below approach will be in O(1).

//we will use a pre node to value mapped map ,  which will contain the index.

//updated code with position function in O(1) time .


class Solution {
public:
    
    void createMapping(vector<int> &inorder ,int start , int end , map<int,int>& nodeToIndex){
        
        for(int i =  start; i <= end ; i++){
            
            nodeToIndex[inorder[i]] = i;
        }
        
        
    }
    
    TreeNode* solve(vector<int> &pre , vector<int> &in , int &index , int inorderstart , int inorderend , int presize,map<int,int> &nodeToIndex){
        
        //base case.
        
        if(index >= presize || inorderstart > inorderend){
            
            return NULL;
        }
        
        int element = pre[index++];
        
        TreeNode* root = new TreeNode(element);
        
        int position = nodeToIndex[element];
        
        
        //make left and right call.
        
        root -> left = solve(pre , in ,index ,inorderstart , position - 1 , presize , nodeToIndex);
        
        root -> right = solve(pre , in , index, position + 1 , inorderend , presize,nodeToIndex);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int inorderstart = 0;
        
        int inorderend = inorder.size() - 1;
        
        int n = preorder.size();
        
        int index = 0;
        
        map<int,int> nodeToIndex;
        
        
        createMapping(inorder,inorderstart , inorderend , nodeToIndex);
        
        TreeNode* ans = solve(preorder, inorder , index, inorderstart , inorderend ,n , nodeToIndex);
        
        return ans;
    }
};
