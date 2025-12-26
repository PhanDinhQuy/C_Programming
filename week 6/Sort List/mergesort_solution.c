/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Hàm 1: hàm để trộn 2 danh sách đã sắp xếp
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL)
    {return l2;}
    if(l2 == NULL)
    {return l1;}

    struct ListNode *head;
    if(l1 -> val < l2 -> val)
    {
        head = l1;
        l1 = l1 -> next;
    }
    else
    {
        head = l2;
        l2 = l2 -> next;
    }

    struct ListNode *current = head;
    while ( l1 != NULL && l2 != NULL)
    {
        if(l1 -> val < l2 -> val )
        {
            current -> next = l1;
            l1 = l1 -> next;
        }
        else
        {
            current -> next = l2;
            l2 = l2 -> next;
        }
        current = current -> next;
    }
    if (l1 != NULL) {current -> next = l1;}
    else if (l2 != NULL) {current -> next = l2;}

    return head;
}

// Hàm 2: tách 
struct ListNode* split(struct ListNode* head)
{
    struct ListNode* slow = head; 
    struct ListNode* fast = head -> next;
    while ( fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    struct ListNode* mid = slow -> next;
    slow -> next = NULL;
    return mid;
}

//Hàm chính
struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* mid = split(head);
    struct ListNode* left = head;
    struct ListNode* right = mid;

    left = sortList(left);
    right = sortList(right);

    return merge(left, right);
}
