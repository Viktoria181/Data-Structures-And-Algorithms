SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) 
{

    SinglyLinkedListNode* newNode = llist;
    if(position == 0)
    {
        newNode = llist->next;
        return newNode;
    }
    
    SinglyLinkedListNode* iter = llist;
    
    for(int i = 1; i < position; i++)
    {
        iter = iter->next;
        newNode = newNode->next;
    }
    
    iter->next = newNode->next->next;
    
    
    return llist;
}