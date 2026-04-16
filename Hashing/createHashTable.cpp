
// class MyHashSet {
// private:
//     static const int size=1000;
//     vector<vector<int>>table;
//     int hash(int key){
//         return key%size;
//     }
// public:
//     MyHashSet() {
//         table=vector<vector<int>>(size);
//     }
    
//     void add(int key) {
//         int idx=hash(key);
//         for(int i: table[idx]){
//             if(i==key)     return;
//         }
//         table[idx].push_back(key);
//     }
    
//     void remove(int key) {
//         int idx=hash(key);
//         for(auto it=table[idx].begin();it!=table[idx].end();it++){
//             if(*it==key){
//                 table[idx].erase(it);
//                 return;
//             }
//         }
        
//     }
    
//     bool contains(int key) {
//         int idx=hash(key);
//         for(auto i: table[idx]) {
//             if(i==key) return true;
//         }
//         return false;
//     }
// };

// /**
//  * Your MyHashSet object will be instantiated and called as such:
//  * MyHashSet* obj = new MyHashSet();
//  * obj->add(key);
//  * obj->remove(key);
//  * bool param_3 = obj->contains(key);
//  */