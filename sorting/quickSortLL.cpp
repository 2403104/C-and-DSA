#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define input(arr)       \
    for (auto &it : arr) \
        cin >> it;
#define output(arr)        \
    for (auto it : arr)    \
        cout << it << " "; \
    cout << endl;
#define pb push_back
#define p push
#define F first
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
struct Node{
    int val;
    Node* prev;
    Node* next;
    Node(int data) : prev(NULL), next(NULL), val(data) {}
};
Node* partition(Node* low , Node* high){
    int pivot=high->val;
    Node* i=low->prev;
    for(Node*  j=low;j!=high;j=j->next){
        if(j->val<pivot){
            i=(i)?i->next:low;
            swap(i->val,j->val);
        }
    }
    i=(i)?i->next:low;
    swap(i->val,high->val);
    return i;
}
void quickSort(Node* low, Node* high){
    if(high!=NULL && low!=high && low!=high->next){
        Node* pivot=partition(low,high);
        quickSort(low,pivot->prev);
        quickSort(pivot->next,high);
    }
}
Node* arrayToDoublyLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    return head;
}
void solve(){
    int arr[50];
    int n;cin>>n;for(int i=0;i<n;i++) cin>>arr[i];
    Node* head=arrayToDoublyLinkedList(arr,n);
    Node* last=head;
    while(last->next!=NULL) last=last->next;
    quickSort(head,last);
    while(head) {
        cout<<head->val<<" ";
        head=head->next;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}