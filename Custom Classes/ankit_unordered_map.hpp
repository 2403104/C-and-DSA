#pragma once
#include <iostream>
#include <utility>
#include <type_traits>
#include <string>
#include <iterator> 
using namespace std;
template<typename K, typename V>
class ankit_unordered_map{
    struct Node{
        K key;
        V value;
        Node* next;
        Node(const K&k, const V&v) : key(k), value(v), next(NULL) {}
    };
    vector<Node*>table;
    size_t tableSize, count;

    size_t HASH_FUNCTION(const K& key) const {
        size_t hash=0;
        const size_t p=31;
        size_t power=1;
        string s=to_string(key);
        for(char ch : s){
            hash=(hash+(ch-'a'+1)*power)%tableSize;
            power=(power*p)%tableSize;
        }
        return hash;
    }
    void RE_HASH(){
        size_t oldSize=tableSize;
        tableSize=max((size_t)8,tableSize*2);
        vector<Node*>newTable(tableSize,NULL);
        for(int i=0;i<oldSize;i++){
            Node* curr=table[i];
            while(curr){
                Node* next_node=curr->next;
                size_t idx=HASH_FUNCTION(curr->key);
                curr->next=newTable[idx];
                newTable[idx]=curr;
                curr=next_node;
            }
        }
        table.swap(newTable);
    }
public:
    ankit_unordered_map(size_t init_size=8){
        tableSize=init_size;
        table.resize(init_size,NULL);
        count=0;
    }
    void insert(const K &key, const V &val){
        if(count*1.0/tableSize>0.75){
            RE_HASH();
        }
        size_t idx=HASH_FUNCTION(key);
        Node* curr=table[idx];
        while(curr){
            if(curr->key==key) {
                curr->value=val;
                return;
            }
            curr=curr->next;
        }
        Node* newNode= new Node(key, val);
        newNode->next=table[idx];
        table[idx]=newNode;
        count++;
    }
    bool contains(const K &key){
        size_t idx=HASH_FUNCTION(key);
        Node* curr=table[idx];
        while(curr){
            if(curr->key==key) return true;
            curr=curr->next;
        }
        return false;
    }
    V& operator[] (const K &key){
        size_t idx=HASH_FUNCTION(key);
        Node* curr=table[idx];
        while(curr){
            if(curr->key==key) return curr->value;
            curr=curr->next;
        }
        Node* newNode = new Node(key, V());
        newNode->next = table[idx];
        table[idx] = newNode;
        count++;
        return newNode->value;
    }
    void print_all() {
        for(size_t i=0; i<tableSize; i++){
            Node* curr = table[i];
            while(curr){
                cout << curr->key << " " << curr->value << endl;
                curr = curr->next;
            }
        }
    }
};