

## Algorithm - 

current = root

while current is not  NULL

if current -> left not exist
   visit(current)
   curr = curr -> right

else 
  predecessor = findPredecessor(current)
  
  if current -> right not exist

    predecessor -> right = current
    current = current -> left
  
  else 

    predecessor -> right = NULL
    visit(current)
    current = current -> left
