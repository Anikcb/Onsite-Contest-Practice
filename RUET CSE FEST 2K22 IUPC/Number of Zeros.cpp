#include<bits/stdc++.h>


using namespace std;
typedef unsigned long long ll;

#define foR1(num) for(ll i = 1; i <= num; i++)
#define     mxx               100005
#define     MOD               1000000007



ll fact[mxx+5];
ll inv[mxx+5];


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


void fun()
{
    fact[0]=1;
    inv[0]=1;
    foR1(mxx)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        inv[i]=bigmod(fact[i],MOD-2,MOD);
    }
}




int main()
{
    ll tst=1;
    fun();

    cin>>tst;
    for(ll tt=1; tt<=tst; tt++)
    {
        //code
        ll n,b,res=0;
        cin>>n>>b;n--;
        for(ll i=0;i<=n;i++)
        {
            ll val1 = PrimePower((i+1),b)% MOD;
            ll val2 = (fact[n] * inv[i])% MOD;
            val2 = (val2 * inv[n-i])% MOD;
            res = (res + (val1 * val2)% MOD)% MOD;
        }
        cout<<"Case "<<tt<<": "<<res<<endl;




    }


    return 0;
}
