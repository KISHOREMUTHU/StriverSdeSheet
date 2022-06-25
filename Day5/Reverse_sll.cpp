/*Day 5 [LINKED LIST]
1. REVERSE A LINKED LIST*/

//RECURSIVE METHOD
//Time Complexity: O(n) 

//Reverse Function
 	struct Node* reverse(struct Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        struct Node* r = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
 
        return r;
    }
 
    
//ITERATIVE METHOD
//Time Complexity: O(n) 

//Reverse Function
void reverse()
 {
 
 Nodeptr curr = head;
 Nodeptr prev = NULL, next = NULL;
 while (curr != NULL) 
 {
 next = curr->next;
 curr->next = prev;
prev = curr;
 curr = next;
 }
 head = prev;
 }
 
 
