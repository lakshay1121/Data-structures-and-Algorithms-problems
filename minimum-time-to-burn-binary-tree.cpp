class Solution {
  public:
  
  Node* createMapping(Node* root , int target , map<Node*,Node*> &NodeToParent){
      
    Node* res = NULL;
    
      queue<Node*> q;
      
      q.push(root);
      
      NodeToParent[root] = NULL;
      
      while(!q.empty()){
          
          Node* front = q.front();
          
          q.pop();
          
          if(front -> data == target) res = front;
          
          
          if(front -> left){
              
              NodeToParent[front -> left] = front;
              
              q.push(front -> left);
          }
          
          
            if(front -> right){
              
              NodeToParent[front -> right] = front;
              
              q.push(front -> right);
          }
      }
      
      
      return res;
      
  }
  
  
  int burnTree(Node* root ,  map<Node*,Node*> &NodeToParent){
      
      
      int ans = 0;
      
      map<Node* , bool> visited;
      
      queue<Node*> q;
      
      q.push(root);
      
      visited[root] = true;
      
      while(!q.empty()){
          
            bool flag = 0;
      
          
          int size = q.size();
          
          for(int i = 0 ; i < size ; i++){
              
              Node* front = q.front();
              
              q.pop();
              
              if(front -> left && !visited[front -> left]){
                  
                  flag = 1;
                  
                  q.push(front -> left);
                  
                  visited[front -> left] = true;
                  
              }
              
              
               if(front -> right && !visited[front -> right]){
                  
                  flag = 1;
                  
                  q.push(front -> right);
                  
                  visited[front -> right] = true;
                  
              }
              
             
             if(NodeToParent[front] && !visited[NodeToParent[front]]){
                 
                 flag = 1;
                 
                 q.push(NodeToParent[front]);
                 
                 visited[NodeToParent[front]] = true;
             }
            
              
          }
          
           if(flag == 1) ans++;
      }
      
      
      return ans;
  }
  
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        map<Node*,Node*> NodeToParent;
        
        Node* targetNode = createMapping(root, target ,NodeToParent);
        
        int ans = burnTree(targetNode, NodeToParent);
        
        return ans;
        
        
    }
};
