
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

int main() {
  int N, C[128];
  scanf("%d", &N);
  REP(i, N) scanf("%d", &C[i]);

  sort(C, C+N);
  ll ans = 0;
  ll F = 1;
  REP(i, N) F *= i+1;

  REP(i, F) {
    ll coins[128];
    fill(coins, coins + N, 1);
    REP(i, N) {
      ans += coins[i];
      FOR(j, i+1, N) {
        if (C[j] % C[i] == 0) coins[j] ^= 1;
      }
    }
    //    REP(i, N) cout << C[i] << (i == N-1 ? '\n' : ' ');
    //    REP(i, N) cout << coins[i] << (i == N-1 ? '\n' : ' ');
    //    cout << endl;
    next_permutation(C, C+N);
  }
  cout << ans << ":"<<F<<endl;
  cout << setprecision(20) << 1.0 * ans / F << endl;
  return 0;
}
