#include <iostream>
#include <map>
using namespace std;
 
const long long N = 2e5 + 5, MOD = 1e9 + 7, oo = 1e18;
 
map<long long, long long> mp;
long long a[N];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; 
    cin >> tc;
    while(tc--) {
        mp.clear();
        long long n, ans = 0; 
        cin >> n;
        for(long long i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i] - i]++;
            ans += mp[a[i] - i];
        }
        cout << abs(n - ans) << "\n";
    }
    return 0;
}