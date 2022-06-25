//2.Find middle of LinkedList

//The list is traverses only once.
//Time Complexity: O(N)

 void Middle(class Node *head)
    {
        struct Node *first = head;
        struct Node *second = head;
  
        if (head!=NULL)
        {
            while (second != NULL && second->next != NULL)
            {
               second = second->next->next;
               first = first->next;
            }
            cout << "The middle element is " << first->data<< endl;
        }
    }
    
    
//Time Complexity:O(N)
//Moving middle to half of the list
void Middle(struct node* head)
{
    int count = 0;
    struct node* middle = head;
 
    while (head != NULL)
    {
         
        if (count%2==1)
            middle = middle->next;
 
        ++count;
        head = head->next;
    }
 
}
