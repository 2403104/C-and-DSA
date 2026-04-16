#include <bits/stdc++.h>
const int N = 10000;
std::vector<int> arr(N);
void init() {
  for(int i = 0; i < N; i++) {
    arr[i] = rand() % 100;
  }
}
void fun1() {
  std::cout << "fun1 started..\n";
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      if(arr[i] < arr[j]) {
        cnt = cnt + 1;
      } else {
        // Do Nothing
      }
    } 
  }
  std::cout << "fun1 ended..\n";
}
void fun2() {
  std::cout << "fun2 started..\n";
  std::sort(arr.begin(), arr.end());
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      if(arr[i] < arr[j]) {
        cnt = cnt + 1;
      } else {
        // Do Nothing
      }
    }
  }
  std::cout << "fun2 ended..\n";
}
int main(){
  init();
  std::cout << "\n\n\n";

  auto start1 = std::chrono::high_resolution_clock::now();
  fun1();
  auto end1 = std::chrono::high_resolution_clock::now();
  std::cout << "Time for fun1: " << std::chrono::duration<double>(end1 - start1).count() << " seconds\n\n\n";

  auto start2 = std::chrono::high_resolution_clock::now();
  fun2();
  auto end2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time for fun2: " << std::chrono::duration<double>(end2 - start2).count() << " seconds\n\n\n";
  return 0;
}