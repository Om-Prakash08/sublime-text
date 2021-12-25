#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
{   if(n==1)
 return false ;
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


// ll power(ll a ,ll b){
//     if(b==0)
//         return 1 ;
//     ll temp=power(a,b/2) ;
//     temp=(temp*temp)%mod ;
//     if(b&1)
//         return (temp*a)%mod ;
//     else
//         return temp ;
// }
// ll solve(ll n ,ll k){
//     if(k==0)
//         return 1;
//     ll ans=power(2,n*k-n) ;
//     ll temp=(p-1) ;
//     temp=(temp*solve(n,k-1))%mod ;
//     ans=(ans+temp)%mod ;
//     return ans ;
// }
void dfs(vector<vector<int>> &v, int i, bool visited[], stack<int> &s)
{
    visited[i] = true ;
    for(auto x : v[i])
    {
        if(visited[x] == false)
        {
            dfs(v, x, visited, s) ;
        }
    }
    s.push(i) ;
}
void dfsutil(vector<vector<int>> &v, bool visited[], int i, vector<int> &ans)
{
    visited[i] = true ;
    ans.push_back(i + 1) ;
    for(auto x : v[i])
    {
        if(visited[x] == false)
        {
            dfsutil(v, visited, x, ans) ;
        }
    }
}
// const int maxm = 100001 ;
// int parent[maxm], size_[maxm] ;
// int parent1[maxm], size_1[maxm] ;
// int find_set(int v)
// {
//     if(v == parent[v])
//         return v ;
//     return parent[v] = find_set(parent[v]) ;
// }
// void make_set(int v)
// {
//     parent[v] = v, size_[v] = 1 ;
// }
// void merge(int a, int b)
// {
//     a = find_set(a) ;
//     b = find_set(b) ;
//     if(a != b)
//     {
//         if(size_[a] >= size_[b])
//         {
//             parent[b] = a, size_[a] += size_[b] ;
//         }
//         else
//         {
//             parent[a] = b, size_[b] += size_[a] ;
//         }
//     }
// }

//#define int long long
const int maxm=2*(int)(1e5)+2 ;
int arr[maxm][32] ;
void solveAnd(){
    memset(arr,0,sizeof(arr)) ;
    for(int i=0;i<maxm;i++)
    {if(i==0)
      {for(int j=0;j<32;j++){
         arr[i][j]=1;
      }}
    else{
    for(int j=0;j<32;j++){
       if(((1<<j)&i)==0)
         arr[i][j]=arr[i-1][j]+1  ;
       else
        arr[i][j]=arr[i-1][j] ;
    }}
    }

    // for(int i=0;i<4;i++)
    //  {
    //     for(int j=0;j<32;j++)
    //         cout<<arr[i][j]<<' ';
    //     cout<<endl ;
    //  }
}
void main_()
{    
  int l ,r ;cin>>l>>r ;
  int temp[32] ;
  for(int i=0;i<32;i++)
    temp[i]=arr[r][i]-arr[l-1][i] ;
  cout<<*min_element(temp,temp+32)<<'\n' ;
}




signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int test = 1 ;
    cin >> test ;
    solveAnd() ;
    while(test--)
    {
        main_();
    }
    return 0;
}
//run ctrl+shift+B
//format alt+shift+F
//Ctrl+Shift+Alt+Q: Quick Format.
//Ctrl+Shift+Alt+S: Selected Format.