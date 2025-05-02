#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int maxn=1e7;
 
int main() {
    ll i,j,n,k,t;
    vector<int>lp(maxn+1);
    vector<int>primes;
    for (i=2;i<=maxn;i++){
        if (lp[i]==0){
            lp[i]=i;
            primes.push_back(i);
        }
        for (j=0;j<primes.size() && primes[j]<=lp[i] && i*primes[j]<=maxn;j++){
            lp[i*primes[j]]=primes[j];
        }
    }
    vector<ll>ans(maxn+1);
    ans[1]=0;
    for (i=2;i<=maxn;i++){
        ll z=i/lp[i];
        if (z%lp[i]==0){
            ans[i]=ans[z];
        }
        else{
            ans[i]=ans[z]+1;
        }
    }
    for (i=1;i<=maxn;i++){
        ans[i]+=ans[i-1];
    }
    cin>>t;
    while (t--){
        cin>>n;
        cout<<ans[n]<<'\n';
    }
    return 0;
}