/*
a node contain data and next(pointer which points to the next node in the list)
*/
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    // next is a pointer of type node*, meaning it can store the memory address of another node object.
    node *next; // as next contain the address of the next node so it type will be address means node*
    node(int val)
    {
        this->data = val;
        this->next = NULL; // new formed node will not have any address
    }
};
// pass by reference
void insertAtTail(node *&head, int val)
{
    node *n = new node(val); // creating a new node, n is the pointer to the new node
    if (head == NULL)
    {
        head = n;
        return;
    }
    // node* is a pointer to an object of type node.
    // It points to a memory address where a node object is stored.
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head; // making the  reference of n to head
    head = n;       // making n as the head
}
// pass by value because we do not want to modify the linked list
void display(node *head)
{ // because the head passed will be of the type node*
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}
void deleteHead(node *&head)
{
    node *toDelete = head;
    head = head->next;
    delete toDelete;
}
void deleteNode(node *&head, int key)
{
    if (head->data == key)
    {
        node *toDelete = head;
        head = head->next;
        delete toDelete;
    }
    if (head == NULL)
    {
        cout << "Linked list is empty";
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == key)
            break;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Item is not present in the linked list" << endl;
        return;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}
node *reverseLL(node *&head)
{
    // THREE POINTER
    node *prev = NULL;
    node *curr = head;
    node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;

    // RECURSIVE APPROACH;
    // if (head == NULL || head->next == NULL)
    // {
    //     return head;
    // }
    // node *newHead = reverseLL(head->next);
    // head->next->next = head;
    // head->next = NULL;

    // return newHead;
}
node *reverse_k(node *&head, int k)
{
    node *prev = NULL;
    node *curr = head;
    node *next;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverse_k(next, k);
    }
    return prev;
}
void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
bool detectCycle(node *head)
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != slow);
    fast = head;
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
int countLength(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
void appendLastK(node *&head, int k)
{
    if (k > countLength(head))
    {
        cout << k << " is grater than the length of the list";
        return;
    }
    node *temp = head;
    int val = 1;
    node *kth;
    while (temp->next != NULL)
    {
        if (k == val)
        {
            kth = temp;
        }
        val++;
        temp = temp->next;
    }
    node *next = kth->next;
    kth->next = NULL;
    temp->next = head;
    head = next;
}
int findIntersection(node *head1, node *head2)
{
    int l1 = countLength(head1);
    int l2 = countLength(head2);
    node *temp1 = (l1 > l2) ? head1 : head2;
    node *temp2 = (l1 < l2) ? head1 : head2;
    int l = abs(l1 - l2);
    int s = 1;
    while (s < l)
    {
        temp1 = temp1->next;
        s++;
    }
    while (temp1->next != NULL)
    {
        if (temp1->next == temp2->next)
            return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}
// MERGE TWO SORTED LIST
node *mergeSortedList(node *head1, node *head2)
{

    node *dummyNode = new node(-1);
    node *dummy = dummyNode; // a list starting with dummy node
    node *temp1 = head1;
    node *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            dummy->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            dummy->next = temp2;
            temp2 = temp2->next;
        }
        dummy = dummy->next;
    }
    while (temp1 != NULL)
    {
        dummy->next = temp1;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        dummy->next = temp2;
        temp2 = temp2->next;
    }
    return dummyNode->next;
}
void evenAfterOdd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = head->next;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if (odd->next == NULL)
    {
        even->next = NULL;
    }
}
node *findMiddle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{

    node *head = NULL;

    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    // insertAtTail(head, 6);
    // insertAtTail(head, 8);
    // insertAtTail(head, 12);
    // insertAtHead(head, 8);
    // insertAtHead(head, 4);
    // insertAtHead(head, 6);
    // deleteHead(head);
    // deleteNode(head,0);

    // display(reverseLL(head));
    // display(reverse_k(head,3));
    // cout<<search(head, 80);
    // makeCycle(head,3);
    // cout<<detectCycle(head);
    // removeCycle(head);
    display(head);
    cout << endl;
    // evenAfterOdd(head);
    // display(head)
    // appendLastK(head, 4);
    // display(head);

    // node* head1=NULL;
    // node* head2=NULL;

    // insertAtTail(head1,1);
    // insertAtTail(head1,3);
    // insertAtTail(head1,5);
    // insertAtTail(head1,6);
    // insertAtTail(head2,2);
    // insertAtTail(head2,4);
    // insertAtTail(head2,7);
    // insertAtTail(head2,9);
    // insertAtTail(head2,10);
    // insertAtTail(head2,11);
    // display(mergeSortedList(head1,head2));
    node *h = findMiddle(head);
    cout << h->data;
    return 0;
}