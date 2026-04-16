#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    int findParent(int i){
        return (i - 1) / 2;
    };
    int findLChild(int i){
        return 2 * i + 1;
    };
    int findRChild(int i){
        return 2 * i + 2;
    };
    bool isValidIndex(int i){
        return i >= 0 && i < heap.size();
    };

    void insert(int val){
        heap.push_back(val);
        shiftUp(heap.size() - 1);
    };
    int getMin(){
        if(!heap.empty()) return heap[0];
        return -1;
    };
    void extractMin(){
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();

        if(!heap.empty()) shiftDown(0);
    };

private:
    int shiftUp(int i){
        while(i > 0 && heap[findParent(i)] > heap[i]){
            swap(heap[findParent(i)], heap[i]);
            i = findParent(i);
        }
        return i;
    };
    int shiftDown(int i){
        int n = heap.size();
        while(true){
            int l = findLChild(i);
            int r = findRChild(i);
            int sm = i;
            if(l < n && heap[l] < heap[sm]) sm = l;
            if(r < n && heap[r] < heap[sm]) sm = r;
            if(sm != i){
                swap(heap[sm], heap[i]);
                i = sm;
            }else break;
        }
        return i;
    };

public:
    void printHeap(){
        for (int x : heap) cout << x << " ";
        cout << "\n";
    };
    int size(){
        return heap.size();
    };
    bool empty(){
        return heap.size() == 0;
    };
};
class MaxHeap {
    vector<int> heap;

public:
    int findParent(int i) {
        return (i - 1) / 2;
    }
    int findLChild(int i) {
        return 2 * i + 1;
    }
    int findRChild(int i) {
        return 2 * i + 2;
    }
    bool isValidIndex(int i) {
        return i >= 0 && i < heap.size();
    }

    void insert(int val) {
        heap.push_back(val);
        shiftUp(heap.size() - 1);
    }

    int getMax() {
        if (!heap.empty()) return heap[0];
        return -1;
    }

    void extractMax() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) shiftDown(0);
    }

private:
    int shiftUp(int i) {
        while (i > 0 && heap[findParent(i)] < heap[i]) {
            swap(heap[findParent(i)], heap[i]);
            i = findParent(i);
        }
        return i;
    }

    int shiftDown(int i) {
        int n = heap.size();
        while (true) {
            int l = findLChild(i);
            int r = findRChild(i);
            int largest = i;
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
        return i;
    }

public:
    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }

    int size() {
        return heap.size();
    }

    bool empty() {
        return heap.empty();
    }
};
int main() {
    MinHeap h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(1);
    h.insert(20);

    cout << "Heap elements: ";
    h.printHeap();

    cout << "Min element: " << h.getMin() << endl;

    h.extractMin();
    cout << "After extractMin: ";
    h.printHeap();

    h.insert(2);
    cout << "After inserting 2: ";
    h.printHeap();
}