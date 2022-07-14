#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>



using namespace std;

typedef int ll;
#define foR1(num) for(ll i = 1; i <= num; i++)
#define     pb                push_back
#define     SZ(x)             ((ll) (x).size())
#define     mxx               1000005
#define     IOS               ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector <ll> vll;


ll divi[mxx+2];
ll parent[mxx+5];
ll siz[mxx+2];



ll find_set(ll v)
{
    if (v == parent[v])return v;
    return parent[v] = find_set(parent[v]);
}


int main()
{
    ll tst=1;
    scanf("%d",&tst);
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll n,cnt=0,val=1;
        long long int res=0;
        scanf("%d",&n);
        foR1(n)parent[i]=i,siz[i]=1;

        for(ll i=n;i>=1;i--)
        {
            for(ll j=2; j<=n && i*j<=n; j++)
            {
                ll x=i;
                ll y=i*j;
                ll u=find_set(x);
                ll v=find_set(y);
                if(u!=v)
                {
                    if (siz[u] < siz[v])swap(u, v);
                    parent[v] = u;
                    siz[u] += siz[v];
                    res+=x;
                    cnt++;
                }
                if(cnt>=n-1)break;
            }
        }
        printf("Case %d: ",tt);
        if(n<4)printf("%d\n",n-1);
        else printf("%lld\n",res);



    }


    return 0;
}
