//Day 5 [LINKED LIST]
//5. Delete a given Node when a node is given. 
//Time complexity:O(1)

//function to get reference of the node to delete
node* getn(node* head,int val) 
{
    while(head->num != val) head = head->next;
    return head;
}
//delete function 
void delN(node* t) 
{
    t->num = t->next->num;
    t->next = t->next->next;
    return;
}

