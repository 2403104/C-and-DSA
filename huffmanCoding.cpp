#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
struct Node {
  string ch;
  int freq;
  Node *left, *right;

  Node(string c, int f) {
      ch = c;
      freq = f;
      left = right = nullptr;
  }
};

struct cmp {
  bool operator()(Node* a, Node* b) {
    return a->freq > b->freq;
  }
};

Node* buildHuffmanTree(vector<char>& chars, vector<int>& freq) {
  int n = chars.size();
  priority_queue<Node*, vector<Node*>, cmp> pq;
  for(int i = 0; i < n; i++) {
    pq.push(new Node( string(1, chars[i]), freq[i]));
  }
  while(pq.size() > 1) {
    Node* left = pq.top(); pq.pop();
    Node* right = pq.top(); pq.pop();
    Node* merged = new Node(left -> ch + right -> ch, left->freq + right -> freq);
    merged -> left = left;
    merged -> right = right;
    pq.push(merged);
  }
  return pq.top();
}
map<char, string> mp;
void printCodes(Node* root, string code) {
  if (!root) return;

  if (!root->left && !root->right) {
      cout << root->ch << " : " << code << "\n";
      mp[(root -> ch)[0]] = code;
  }

  printCodes(root->left, code + "0");
  printCodes(root->right, code + "1");
}

int main(){
  vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<int> freq  = {5, 9, 12, 13, 16, 45};

  Node* root = buildHuffmanTree(chars, freq);

  cout << "Huffman Codes:\n";
  printCodes(root, "");

  string s = "faced";
  for(char ch : s) {
    cout << mp[ch];
  }
  cout << endl;
  
  return 0;
}