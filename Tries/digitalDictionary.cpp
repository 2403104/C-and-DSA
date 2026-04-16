#include <iostream>
using namespace std;

class Node {
public:
    Node *next[26];
    bool end;
    Node() {
        end = false;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};

class Trie {
    Node *root;

public:
    Trie() { root = new Node(); }

    void insert(string &s) {
        Node *it = root;
        for (char c : s) {
            if (it->next[c - 'a'] == NULL) {
                it->next[c - 'a'] = new Node();
            }
            it = it->next[c - 'a'];
        }
        it->end = true;
    }

    bool search(string &s) {
        Node *it = root;
        for (char c : s) {
            if (it->next[c - 'a'] == NULL) return false;
            it = it->next[c - 'a'];
        }
        return it->end;
    }

    void find(string &s) {
        Node *it = root;
        for (char c : s) {
            if (it->next[c - 'a'] == NULL) {
                cout << "No word found!!" << endl;
                insert(s);
                return;
            }
            it = it->next[c - 'a'];
        }
        printAll(it, s);
    }

    void printAll(Node *it, string curr) {
        if (it == NULL) return;
        if (it->end) cout << curr << endl;
        for (int i = 0; i < 26; i++) {
            if (it->next[i]) {
                printAll(it->next[i], curr + char('a' + i));
            }
        }
    }
};

int main() {
    Trie t;
    int n;
    cout << "Enter number of words in dictionary: ";
    cin >> n;
    
    cout << "Enter words: " << endl;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        t.insert(s);
    }
    string s;
    cin>>s;
    t.find(s);

    return 0;
}
