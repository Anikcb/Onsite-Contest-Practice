#include<bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR1(num) for(ll i = 1; i <= num; i++)
#define     mxx               100005
#define     MOD               1000000007



ll fact[mxx+5];


ll PrimePower (ll n , ll p )
{
    ll freq = 0;
    ll x = n;
    while ( x )
    {
        freq = freq +(x / p) % MOD;
        x = x / p;
    }

    return freq % MOD;
}

void fun()
{
    fact[0]=1;
    foR1(mxx)fact[i]=(fact[i-1]*i)%MOD;
}


ll bigmod ( ll a, ll p, ll m )
{
    ll res = 1;
    ll x = a%m;
    if(x==0)return 0;

    while ( p )
    {
        if ( p & 1 )
        {
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res;
}


int main()
{
//    IOS;
    ll tst=1;
    fun();
    scanf("%lld",&tst);
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll n,b,res=0;
        scanf("%lld %lld",&n,&b);
        for(ll i=0;i<=n;i++)
        {
            ll val1 = PrimePower(i,b)%MOD;
            ll val2 = (fact[n] * bigmod(fact[i],MOD-2,MOD))% MOD;
            val2 = (val2* bigmod(fact[n-i],MOD-2,MOD))% MOD;
            res = (res + (val1 * val2)% MOD)% MOD;
        }
        printf("Case %lld: %lld\n",tt,res);




    }


    return 0;
}
