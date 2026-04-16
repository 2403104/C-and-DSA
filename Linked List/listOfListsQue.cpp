#include <bits/stdc++.h>
using namespace std;
struct  Node{
    int data;
    Node* nextNode;
    Node(int val) : data(val) , nextNode(NULL) {}
};
struct ListOfLists{
    Node* listHead;
    ListOfLists* nextList;
    ListOfLists () : listHead(NULL), nextList(NULL) {}
};
int main(){
    vector<int>arr={1,4,5,2,6,3,5,8,9,6,5,8,7,4,5,6,9,5,2,9,6,5,4,7};
    int n=arr.size();
    int k=7;
    ListOfLists *head=NULL;
    ListOfLists *prevList=NULL;
    int mod=n%k;
    int idx=0;
    for(int i = 0; i < k; i++ ){
        int size=(i<mod?n/k+1:n/k);
        ListOfLists *temp=new ListOfLists();
        temp->listHead=new Node(arr[idx++]);
        Node* currNode=temp->listHead;
        for(int i=1;i<size;i++){
            currNode->nextNode=new Node(arr[idx++]);
            currNode=currNode->nextNode;
        }
        if(head==NULL){
            head=temp;
            prevList=temp;
            continue;
        }else{
            prevList->nextList=temp;
            prevList=temp;
        }
    }
    ListOfLists *ans=head;
    while(ans){
        Node* newNode=ans->listHead;
        ans=ans->nextList;
        while(newNode) {cout<<newNode->data<< ' ';newNode=newNode->nextNode;}
        cout<<endl;
    }



}