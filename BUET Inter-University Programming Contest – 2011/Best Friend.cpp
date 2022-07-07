#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define          IOS                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          ll                     long long int
#define          EPS                    10E-10
#define          ull                    unsigned long long int
#define          db                     double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          mxx                    100005
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          ff                     first
#define          ss                     second
#define          re                     return
#define          QI                     queue<int>
#define          SI                     stack<int>
#define          iseq(a,b)              (fabs(a-b)<eps)
#define          SZ(x)                  ((int) (x).size())
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          scch1(ch)              scanf("%s",ch)
#define          scch2(ch1,ch2)         scanf("%s %s",ch1,ch2)
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     3.141592653589793238462643
#define          rep( i , a , b )       for( i=a ; i<b ; i++)
#define          rev( i , a , b )       for( i=a ; i>=b ; i--)
#define          repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define          RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          get_pos(c,x)           (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          CASEL(t)               printf("Case %d:\n",t)
#define          Unique(X)             (X).erase(unique(all(X)),(X).end())
const int xx = (int) 1e6 + 1;
//printf(p % 2 ? "Yes\n" : "No\n");

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
/*
ll knx[]= {+2,+2,+1,+1,-1,-1,-2,-2};
ll kny[]= {-1,+1,-2,+2,-2,+2,-1,+1};
*/

bool sortinrev(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    return (a.first > b.first);
}

//string s(5, '#');
// s+="%%%";
// s.insert(0,"%%%");
ll A[1000000];
ll B[1000000];
map<ll,vector<ll> >ps;
vector<ll>v;

ll phi(ll n)
{
    ll result = n;
    for (ll p = 2; p * p <= n; ++p) {

        if (n % p == 0) {

            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    if (n > 1)
        result -= result / n;
    return result;
}

void fun(ll n)
{
    ll res=0;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(n/i==i)v.pb(i);
            else v.pb(i),v.pb(n/i);
        }
    }
    sort(all(v));
    for(ll i=0;i<SZ(v);i++)
    {
        ll val=n/v[i];
        res+=(phi(val));
        A[i]=res;
    }
}

int main()
{
    // input;
    // output;
    // cout<<"Case "<<i<<": ";
     IOS;
     ll t;
     cin>>t;
     for(ll j=1;j<=t;j++)
     {
         ll n,q;
         cin>>n>>q;
         cout<<"Case "<<j<<endl;
         fun(n);
         for(ll i=1;i<=q;i++)
         {
             ll a;
             cin>>a;
             ll lb=lower_bound(v.begin(),v.end(),a)-v.begin();
             if(v[lb]!=a)lb--;
             cout<<A[lb]<<endl;
         }
         v.clear();
     }











    return 0;
}
