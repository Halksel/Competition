#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n;

int f(vi a, int n, int idx)
{
  vi kesu;

  for (int i = idx + 1; i < n; ++i) {
    if (a[i] != a[idx]) break;
    kesu.push_back(i);
  }
  for (int i = idx - 1; i >= 0; --i) {
    if (a[i] != a[idx]) break;
    kesu.push_back(i);
  }

  if (kesu.size() < 3) return n;

  while (!kesu.empty()) {
    a[kesu.back()] = 0;
    kesu.pop_back();
  }
  a[idx] = 0;

  vi b;

  int nextidx = -1;

  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      b.push_back(a[i]);
      if (nextidx == -1 && i >= 1 && a[i - 1] == 0) {
        nextidx = b.size() - 1;
      }
    } else {
      if (nextidx == -1) {
        if (!b.empty()) {
          nextidx = i - 1;
        }
      }
    }
  }

  return f(b, b.size(), nextidx);
}

int calc(vi a, int n, int idx)
{
  vi b = a;
  if (idx >= 3 && a[idx - 1] == a[idx - 2] && a[idx - 2] == a[idx - 3]) {
    b[idx] = b[idx - 1];
  } else if (idx <= n - 4 && a[idx + 1] == a[idx + 2] && a[idx + 2] == a[idx + 3]) {
    b[idx] = b[idx + 1];
  } else if (idx >= 2 && idx <= n - 2 && a[idx - 1] == a[idx - 2] && a[idx - 1] == a[idx + 1]) {
    b[idx] = b[idx - 1];
  } else if (idx >= 1 && idx <= n - 3 && a[idx - 1] == a[idx + 1] && a[idx - 1] == a[idx + 2]) {
    b[idx] = b[idx - 1];
  } else {
    return n;
  }

  return f(b, b.size(), idx);
}

int main()
{
  while (scanf("%d", &n), n) {
    vi arr;

    for (int i = 0; i < n; ++i) {
      int a; scanf("%d", &a);
      arr.push_back(a);
    }

    int mi = 10001;

    for (int i = 0; i < n; ++i) {
      mi = min(mi, calc(arr, arr.size(), i));
    }

    printf("%d\n", mi);
  }
}
