//Day 5 [LINKED LIST]
//3.Merge two sorted Linked List

//RECURSIVE METHOD
//TIME COMPLEXITY: O(m+n)
Node* Sort(Node* a, Node* b) 
{ 
    Node* res = NULL; 
      
    if (a == NULL) 
        return(b); 
    else if (b == NULL) 
        return(a); 
      
    if (a->data <= b->data) 
    { 
        res = a; 
        res->next = Sort(a->next, b); 
    } 
    else
    { 
        res = b; 
        res->next = Sort(a, b->next); 
    } 
    return(res); 
} 

//Method 2
//using local references
Node* Sort(Node* a, Node* b)
{
    Node* res = NULL;
  
    
    Node** lastPtrRef = &result;
  
    while (1) {
        if (a == NULL) 
		{
            *lastPtrRef = b;
            break;
        }
        
        else if (b == NULL) 
		{
            *lastPtrRef = a;
            break;
        }
        
        if (a->data <= b->data)
            MoveNode(lastPtrRef, &a);
        else
            MoveNode(lastPtrRef, &b);
  
      
        lastPtrRef = &((*lastPtrRef)->next);
    }
    return (res);
}
  





