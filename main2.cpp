#include <iostream>
#include <vector>

int main() {
  std::vector<int> S{5, 3, 8, 6, 2};
  int n = S.size();

  for (int i = 1; i < n; i++) {
    int curr = S[i];
    int j = i - 1;
    while ((j >= 0) && (S[j] >= curr)) {
      S[j + 1] = S[j];
      j = j - 1;
    }
    S[j + 1] = curr;
  }

  int w = 17;
  void *p = &w;
  int *pw = static_cast<int *>(p);
  std::cout << *(static_cast<int *>(p)) << '\n';

  const int *p1 = &w;
  int *const p2 = &w;
  // *p1 = 18; // errore
  *p2 = 18;
  // p2 = p1; // errore

  return 0;
}