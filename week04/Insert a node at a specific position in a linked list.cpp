SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) 
{
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    if(position == 0)
    {
        newNode->next = llist;
        return newNode;
    }
    
    SinglyLinkedListNode* iter = llist;
    
    for(int i = 1; i < position; i++)
    {
        iter = iter->next;
    }
    
    newNode->next = iter->next;
    iter->next = newNode;
    
    return llist;

}