#include <bits/stdc++.h>
using namespace std;
//longest common prefix 
/*
SUFFIX ARRAY AND LCP ARRAY - EXPLANATION
========================================

1. What is a Suffix Array?
---------------------------
A suffix array is an array of integers representing the starting positions 
of all suffixes of a string, sorted in lexicographical (dictionary) order.

Example:
---------
Let s = "banana"

All suffixes of s:
Index | Suffix
------|--------
  0   | banana
  1   | anana
  2   | nana
  3   | ana
  4   | na
  5   | a

Sorted suffixes:
Index | Suffix
------|--------
  5   | a
  3   | ana
  1   | anana
  0   | banana
  4   | na
  2   | nana

So, the suffix array is:
[5, 3, 1, 0, 4, 2]


2. What is the LCP (Longest Common Prefix) Array?
---------------------------------------------------
The LCP array stores the lengths of the longest common prefixes between 
consecutive suffixes in the suffix array.

From the sorted suffixes above:
LCP between "a" and "ana"      = 1
LCP between "ana" and "anana"  = 3
LCP between "anana" and "banana" = 0
LCP between "banana" and "na"  = 0
LCP between "na" and "nana"    = 2

So, the LCP array is:
[0, 1, 3, 0, 0, 2]
(Note: Some implementations skip the first 0)

KEY IDEAS TO IMPLEMENT SUFFIX ARRAY + LCP ARRAY
===============================================

1. Suffix Array using Prefix Doubling
--------------------------------------

Idea:
- Assign an initial rank to each character in the string.
- Iteratively sort suffixes based on pairs of ranks:
    (current rank, next rank) where next rank is rank[i + k]
- Double the value of k in each step (1, 2, 4, 8, ...)

Steps:
a. Initialize rank[i] = ASCII value or 0-indexed char rank of s[i]
b. Sort all suffixes based on (rank[i], rank[i+k]) using counting sort.
c. After sorting, assign new ranks based on ordering.
d. Repeat with k *= 2 until all suffixes are uniquely ranked.

Optimization:
- Use counting sort or radix sort for sorting suffix indices by rank pairs.

Time Complexity: O(n log n)

---------------------------------------------------

2. LCP Array using Kasai's Algorithm
-------------------------------------

Idea:
- Once suffix array is built, create a rank array where:
    rank[suffix_array[i]] = i
- For each suffix s[i], compare it with the previous suffix in the sorted order.
- Use previous LCP value to minimize character comparisons.

Steps:
a. Build rank array from the suffix array.
b. Initialize k = 0.
c. For i = 0 to n-1:
    If rank[i] == 0:
        LCP[rank[i]] = 0
    Else:
        j = suffix_array[rank[i] - 1]
        While s[i + k] == s[j + k], increment k.
        LCP[rank[i]] = k
        If k > 0, decrement k

Time Complexity: O(n)

---------------------------------------------------

3. Data Structures to Use
--------------------------
- vector<int> for suffix array
- vector<int> for rank array (used in doubling and Kasai's algorithm)
- vector<int> for temporary sorting and new rank assignment
- vector<int> for LCP array

---------------------------------------------------

4. Edge Cases
--------------
- Add a sentinel character (like '$') at the end to ensure uniqueness
- Handle bounds carefully: i+k may exceed n

---------------------------------------------------

5. Applications
---------------
- Substring search: Use binary search over suffix array
- Count distinct substrings: n*(n+1)/2 - sum(LCP[i])
- Find longest repeated substring: max(LCP)


3. Time Complexity
-------------------
Efficient algorithms build the suffix array and LCP array as follows:

- Suffix Array using Prefix Doubling + Counting Sort: O(n log n)
- LCP Array using Kasai's Algorithm: O(n)
Suffix Array and LCP Array - Complexity Explanation

1. Suffix Array (Prefix Doubling Algorithm with Counting Sort)

The suffix array is constructed by sorting suffixes based on their first 1 character, then first 2 characters, then 4, 8, and so on, doubling each time until the length exceeds the string length.

- Number of phases: O(log n) because we double the prefix length each time.
- Each phase involves sorting suffixes using counting sort, which runs in O(n).
- Updating ranks after sorting also takes O(n).

Overall Time Complexity for building suffix array:
O(n log n)

2. LCP Array (Kasai's Algorithm)

Kasai's algorithm builds the Longest Common Prefix (LCP) array using the suffix array and the rank array.

- It performs a single linear scan over the string.
- Each character comparison during LCP computation happens at most twice.
  
Overall Time Complexity for building LCP array:
O(n)

Summary:

| Structure      | Time Complexity |
|----------------|-----------------|
| Suffix Array   | O(n log n)      |
| LCP Array      | O(n)            |

Total complexity for building both suffix and LCP arrays:
O(n log n)


*/
vector<int> buildSuffixArray(const string &s){
    int n=s.size();
    vector<int>sa(n),rank(n),temp(n);
    for(int i=0;i<n;i++){
        sa[i]=i;
        rank[i]=s[i];
    }
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif

    

    return 0;
}