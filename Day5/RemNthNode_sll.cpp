  //Day 5 [LINKED LIST]
//4.Remove N-th node from back of LinkedList
  
//ITERATIVE APPROACH
   Node* del(int key)
    {
        Node* temp;
        Node* f = head;
        Node* s = head;
        for (int i = 0; i < key; i++) {
            if (s->next == NULL) {
                
                if (i == key - 1) {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
                return head;
            }
            s = s->next;
        }
 
        while (s->next != NULL) 
  {
            f = f->next;
            s = s->next;
        }
        temp = f->next;
        f->next = f->next->next;
        free(temp);
        return head;
    }



