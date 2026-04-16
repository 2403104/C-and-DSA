#include <bits/stdc++.h>
using namespace std;

class functionState {
public:
    int* subArray;
    int left;
    int right;
    int pivotIndex;
    int nextLine;

    void printSubArray() {
        for (int i = left; i <= right; i++) {
            cout << subArray[i] << " ";
        }
        cout << endl;
    }
};

class systemStack {
private:
    int maxSize;
    functionState* systemArray;
    int top;

public:
    systemStack(int stackSize) {
        maxSize = stackSize;
        systemArray = new functionState[maxSize];
        top = -1;
    }

    ~systemStack() {
        delete[] systemArray;
    }

    bool isFull() {
        return (top == maxSize - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(functionState currentState) {
        systemArray[++top] = currentState;
        if (currentState.nextLine == 2)
            cout << "Push (about to sort left partition): ";
        else if (currentState.nextLine == 3)
            cout << "Push (about to sort right partition): ";
        else
            cout << "Push (about to partition): ";
        currentState.printSubArray();
    }

    functionState pop() {
        functionState topNode = systemArray[top--];
        if (topNode.nextLine == 2)
            cout << "Pop (done with left partition): ";
        else if (topNode.nextLine == 3)
            cout << "Pop (done with right partition): ";
        else
            cout << "Pop (done with partition): ";
        topNode.printSubArray();
        return topNode;
    }
};

systemStack quickStack(100);

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right) {
    int pivot;
    int nextLine;
    functionState functionObj;

    do {
        startPartition:
            if (left >= right) {
                if (!quickStack.isEmpty()) {
                    functionObj = quickStack.pop();
                    left = functionObj.left;
                    right = functionObj.right;
                    pivot = functionObj.pivotIndex;
                    nextLine = functionObj.nextLine;

                    if (nextLine == 2) {
                        goto startRightPartition;
                    } else if (nextLine == 3) {
                        goto startPartition;
                    }
                } else {
                    break;
                }
            }

            functionObj.left = left;
            functionObj.right = right;
            functionObj.subArray = arr;
            functionObj.nextLine = 1;
            quickStack.push(functionObj);

            pivot = partition(arr, left, right);
            quickStack.pop();
            functionObj.left = left;
            functionObj.right = right;
            functionObj.subArray = arr;
            functionObj.pivotIndex = pivot;
            functionObj.nextLine = 2;
            quickStack.push(functionObj);

            right = pivot - 1;
            goto startPartition;

        startRightPartition:
            left = pivot + 1;
            right = functionObj.right;
            goto startPartition;
    } while (!quickStack.isEmpty());

}


int main() {
    int arr[12] = {11,14,12,1,15,4,18,3,6,54,42,21};
    quickSort(arr, 0, 11);
    for (int i = 0; i < 12; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
