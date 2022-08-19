//t(c) = O(N)
//s(c) = O(N)


//main function - check if the root node is not a leaf node add its data in the data structure.

//step 1 - add the left boundary data in data structure excluding the leaf nodes.

//step 2 - add the leave nodes into the data structure.

//step 3 - add the right boundary data in a temporary data structure excluding the leaf nodes , and store it in data structure in reverse order.




class Solution {
    
public:


void LeftBoundary(Node* root , vector<int> &ans){
    
    
    Node* curr = root -> left;
    
    
        while(curr){
            
            bool isLeaf = (curr ->left == NULL && curr -> right == NULL);
            
            
      if( !isLeaf) ans.push_back(curr -> data);
    
        
        if(curr -> left) curr = curr -> left;
        
         else curr = curr -> right;
        
        }
    
}


void RightBoundary(Node* root , vector<int> &ans){
    
    
    Node* rbound = root -> right;
    
    
    vector<int> tmp;
    
    while(rbound){
        
         bool isLeaf = (rbound ->left == NULL && rbound -> right == NULL);
        
        if( !isLeaf) tmp.push_back(rbound -> data);
        
        if(rbound -> right) rbound = rbound -> right;
        
        else rbound = rbound -> left;
        
    }
    
    
        for(int i = tmp.size() - 1 ; i >= 0; i--){
            
            ans.push_back(tmp[i]);
        }
    
}


void addLeaves(Node* root , vector<int> &ans){
    
    // a simple inorder traversal.
    
  
    
     bool isLeaf = (root ->left == NULL && root -> right == NULL);
    
      if(isLeaf){
            
             ans.push_back(root -> data);
             
             return;
            
        }
    
        if(root -> left) addLeaves(root -> left , ans);
        
        
        if(root -> right) addLeaves(root -> right , ans);
    
    
}
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        //adding the root data.
        
         bool isLeaf = (root ->left == NULL && root -> right == NULL);
       
        
        if(!isLeaf) ans.push_back(root -> data);
        
        LeftBoundary(root  , ans);
    
        addLeaves(root , ans);
        
        RightBoundary(root  , ans);
        
        
        return ans;
        
        
    }
};
