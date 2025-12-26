/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    if( head == NULL || head -> next == NULL)
    {
        return head;
    }

    struct ListNode *Lastnode=NULL;
    struct ListNode *current;
    int swapped;
    int tempval;

    do
    {
        swapped = 0;
        current = head;
        
        while(current -> next != NULL)
        {
            if(current -> val >= current -> next -> val)
            {
                tempval = current -> val;
                current -> val = current -> next -> val;
                current -> next -> val = tempval;
                swapped = 1;
            }
        current = current -> next;
        }
        Lastnode = current;
    }
    while (swapped);
    return head;
}
