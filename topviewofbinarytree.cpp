class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        
        vector<int> ans;
        
        map<int,int> topNode;
        
        queue<pair<Node* , int>> q;
        
        q.push(make_pair(root , 0));
        
        
        
        while(!q.empty()){
            
           pair<Node* , int> temp = q.front();
           
           q.pop();
             
           Node* frontNode = temp.first;
           
           int horidis = temp.second;
           
           
           if(topNode.find(horidis) == topNode.end()){
               
               topNode[horidis] = frontNode -> data;
           }
           
           if(frontNode -> left){
               
               q.push(make_pair(frontNode -> left , horidis - 1));
           }
           
           if(frontNode -> right){
               
               q.push(make_pair(frontNode -> right , horidis + 1));
           }
     
        }
        
        for(auto it : topNode){
            
            ans.push_back(it.second);
        }
        
        
        return ans;
        
    }

};
