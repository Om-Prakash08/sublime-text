#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define rep(i,a,b) for(int i=a ;i<b;i++)

//#include <boost/functional/hash.hpp>
/*
int construct_segment_tree(int arr[] ,int st[] ,int start ,int end ,int index) //initial value start=0 ,end=n-1 ,index=0
  { if(start=end)
     {
      st[index]= arr[start] ;
      return st[index] ;
     } int mid=(start+end)>>2 ;
     st[index]=construct_segment_tree(arr,st,start,mid,2*index+1)+construct_segment_tree(arr,st,mid+1,end,2*index+2) ;
     return st[index] ;
  }
int getsum(int st[] ,int qs ,int qe ,int start ,int end ,int index ) // initial  start=0 ,end=n-1 ,index=0
{
  if(start>qe||end<qs)
    return 0 ;
  if(start>=qs && end<=qe)
     return st[index] ;
   int mid=(start+end)>>2 ;
   return getsum(st,qs,qe,start,mid,2*index+1)+getsum(st,qs,qe,,mid+1,end,2*index+2) ;
}
void upadaterec(int st[] ,int start ,int end ,int i ,int index ,int diff)
{

}*/


/*auto Z_array_generate(string s)
 {
  int n=s.size() ;
  std::vector<int> z(n);
  int l,r ;l=r=0 ;
  for(int i=1;i<n;i++)
  { if(i>r)
       {l=r=i ;
        while(r<n && s[r-l]==s[r] )
            {r++ ;}
        z[i]=r-l ;
        r-- ;}
    else{int index=i-l ;
        if(z[index]<r-i+1)
           {z[i]=z[index] ; }
        else
           {l=i ;
           while(r<n && s[r-l]==s[r])
               {r++ ;}
           z[i]=r-l ;
           r-- ;}
      }
  }
  return z ;
 }
 void z_algorithm(string s ,string pat)
 {
  string concate=pat+"$"+s ;
  auto z=Z_array_generate(concate) ;
  int n=s.size() ;
  int m=pat.size() ;
  for(int i=m;i<n+m+1;i++)
    if(z[i]==m)
      cout<<"pattern found at index-"<<i-(m+1)<<'\n';
    cout<<endl;
 }*/
void yes()
{
    cout << "YES" << '\n' ;
}
void no()
{
    cout << "NO" << '\n' ;
}

int gcd(ll a, ll b)
{
    if(b == 0)
        return a ;
    return gcd(b, a % b) ;
}

bool compare(pair<ll, int> &a, pair<ll, int> &b)
{
    return a.first <= b.first ;
}




struct s
{
    int x, y ;
};
bool check(ll x)
{
    ll p = sqrt(x) ;
    p = p - 1 >= 0 ? p - 1 : p ;
    while(p * p < x)
    {
        p++ ;
    }
    return p * p == x ? true : false ;
}

int pow(int a, int b)
{
    if(b == 0)
        return 1 ;
    ll y = pow(a, b / 2) ;
    if(b % 2)
    {
        return (((y * y) % mod) * a) % mod ;
    }
    return (y * y) % mod;
}
ll pow(int x)
{
    if(x == 0)
        return 1 ;
    if(x & 1)
        return pow(x / 2) * pow(x / 2) * 2 ;
    return pow(x / 2) * pow(x / 2) ;
}


bool check_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false ;
        }
    }
    return true ;
}


// Do not quit
// Keep trying, you're close
// No looking at standings
// Atleat C
// Try D

//#define int long long
int gcd_(int a, int b)
{
    if(a == 0)
        return b ;
    if(b == 0)
        return a ;
    return gcd_(b, a % b) ;
}

void main_()
{

}




signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1 ;
    //cin >> test ;
    while(test--)
    {
        main_();
    }
    return 0;
}
//ctrl+shift+B: Run/Build
//Shift+Alt+f: Quick Format.
//Shift+Alt+S: Selected Format.