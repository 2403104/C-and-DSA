#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void displayLL(node *&head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteHead(node* &head)
{
    head=head->next;
}
void deleteNode(node *&head, int key)
{
    if (head->data==key)
    {
        deleteHead(head);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
            break;
        temp = temp->next;
    }
    if (temp->next==NULL)
    {
        temp->prev->next=NULL;
        delete temp->next;
        return;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    
    delete temp;
}
int main()
{
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    deleteNode(head, 7);
    displayLL(head);
    return 0;
}