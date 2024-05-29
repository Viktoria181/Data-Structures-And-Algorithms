int getCount(SinglyLinkedListNode* head)
{
    int count = 0;

    SinglyLinkedListNode* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}


int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{

    int sizeOfHead1 = getCount(head1);
    int sizeOfHead2 = getCount(head2);

    SinglyLinkedListNode* temp = head2;

        for (int i = 0; i < sizeOfHead1; i++)
        {
            for (int j = 0; j < sizeOfHead2; j++)
            {
                if (head1 == temp)
                    return head1->data;
                temp = temp->next;
            }
            temp = head2;
            head1 = head1->next;
        }

    return 0;
}