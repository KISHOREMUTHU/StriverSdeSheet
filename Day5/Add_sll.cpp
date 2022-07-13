//Day 5 [LINKED LIST]
//6. Add two numbers as LinkedList

//Iterative Approach
//Time Complexity: O(nlogn)

// to add two new numbers
Node* addList(Node* l1, Node* l2) {
    stack<int> s1,s2;
    while(l1!=NULL){
        s1.push(l1->data);
        l1=l1->next;
    }
    while(l2!=NULL){
        s2.push(l2->data);
        l2=l2->next;
    }
    int c=0;
    Node* res=NULL;
    while(s1.empty()==false || s2.empty()==false){
        int a=0,b=0;
        if(s1.empty()==false){
            a=s1.top();s1.pop();
        }
        if(s2.empty()==false){
            b=s2.top();s2.pop();
        }
        int tot=a+b+c;
        Node* temp=new Node();
        temp->data=tot%10;
        c=tot/10;
        if(res==NULL){
            res=temp;
        }else{
            temp->next=res;
            res=temp;
        }
    }
    if(c!=0){
        Node* temp=new Node();
        temp->data=c;
        temp->next=res;
        res=temp;
    }
    return res;
}
 


