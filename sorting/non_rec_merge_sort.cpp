#include <bits/stdc++.h>
using namespace std;

class functionState {
public:
    int* subArray;
    int left;
    int right;
    int mid;
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
    class functionState* systemArray;
    int top;

public:
    systemStack(int stackSize) {
        maxSize = stackSize;
        systemArray = new class functionState[maxSize];
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

    void push(class functionState currentState) {
        systemArray[++top] = currentState;
        if (currentState.nextLine == 5)
            cout << "Push (about to execute left half):";
        else if (currentState.nextLine == 6)
            cout << "Push (about to execute right half):";
        else
            cout << "Push (about to start merge):";
        currentState.printSubArray();
    }

    class functionState pop() {
        class functionState topNode = systemArray[top--];
        if (topNode.nextLine == 5)
            cout << "Pop (done with left half):";
        else if (topNode.nextLine == 6)
            cout << "Pop (done with right half):";
        else
            cout << "Pop (done with merge):";
        topNode.printSubArray();
        return topNode;
    }
};

class systemStack mergeStack(100);

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    int mid;
    int nextLine;
    functionState functionObj;

    do {
    nextRecursion:
        if (left >= right) {
            if (!mergeStack.isEmpty()) {
                functionObj = mergeStack.pop();
                left = functionObj.left;
                right = functionObj.right;
                mid = functionObj.mid;
                nextLine = functionObj.nextLine;
                if (nextLine == 5)
                    goto startRightHalf;
                else if (nextLine == 6)
                    goto startMerge;
                else
                    continue;
            } else {
                break;
            }
        }

        mid = (left + right) / 2;

        functionObj.subArray = arr;
        functionObj.left = left;
        functionObj.mid = mid;
        functionObj.right = right;
        functionObj.nextLine = 5;
        mergeStack.push(functionObj);

        right = mid;
        goto nextRecursion;

    startRightHalf:
        mid = (left + right) / 2;
        functionObj.subArray = arr;
        functionObj.left = left;
        functionObj.mid = mid;
        functionObj.right = right;
        functionObj.nextLine = 6;
        mergeStack.push(functionObj);

        left = mid + 1;
        goto nextRecursion;

    startMerge:
        // mid = (left + right) / 2;
        functionObj.subArray = arr;
        functionObj.left = left;
        functionObj.right = right;
        functionObj.mid = mid;
        functionObj.nextLine = 7;
        mergeStack.push(functionObj);

        merge(arr, left, mid, right);
        mergeStack.pop();
        if (!mergeStack.isEmpty()) {
            functionObj = mergeStack.pop();
            left = functionObj.left;
            right = functionObj.right;
            mid = functionObj.mid;
            nextLine = functionObj.nextLine;

            if (nextLine == 5)
                goto startRightHalf;
            else if (nextLine == 6)
                goto startMerge;
        }
    } while (!mergeStack.isEmpty());
}

int main() {
    int arr[50];
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << endl;

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
