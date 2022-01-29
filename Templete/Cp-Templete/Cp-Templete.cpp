#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 1000000007
#define pb push_back
#define rep(i,a,b) for(int i=a ;i<b;i++)
//#include <boost/functional/hash.hpp>



/************************************Segment Tree********************************************************************************************************************************************/
class Segment_tree
{
    int construct_segment_tree(int arr[], int st[], int start, int end, int index) //initial value start=0 ,end=n-1 ,index=0
    {
        if(start = end)
        {
            st[index] = arr[start] ;
            return st[index] ;
        }
        int mid = (start + end) >> 2 ;
        st[index] = construct_segment_tree(arr, st, start, mid, 2 * index + 1) + construct_segment_tree(arr, st, mid + 1, end, 2 * index + 2) ;
        return st[index] ;
    }
    int getsum(int st[], int qs, int qe, int start, int end, int index ) // initial  start=0 ,end=n-1 ,index=0
    {
        if(start > qe || end < qs)
            return 0 ;
        if(start >= qs && end <= qe)
            return st[index] ;
        int mid = (start + end) >> 2 ;
        return getsum(st, qs, qe, start, mid, 2 * index + 1) + getsum(st, qs, qe, mid + 1, end, 2 * index + 2) ;
    }
    // void upadaterec(int st[], int start, int end, int i, int index, int diff) // initial  start=0 ,end=n-1 ,index=0
    // {

    // }
};
/****************************************************************************************************************************************************************************/






/*****************************************String Matching Alog**********************************************************************************************************************/
class z_algorithm   //O(n+m) time and space 
{
public:
    vector<int> Z_array_generate(string s)
    {
        int n = s.size() ;
        vector<int> z(n,0); // z[i]:-length of longest substring starting at i which is also prefix of string s.
                           // Example: s="AAAB" , z[4]={x,2,1,0}
        for (int i = 1, l = 0, r = 0; i < n; i++)
        {   // segment[l,r] is rightmost segment match with prefix segment[0,r-l]
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z ;
    }
    void PrintAllOccurence(string s, string pat)
    {
        string concate = pat + "$" + s ;
        auto z = Z_array_generate(concate) ;
        int n = s.size() ;
        int m = pat.size() ;
        for(int i = m + 1; i < n + 2; i++)
            if(z[i] == m)
                cout << "pattern found at index-" << i - (m + 1) << '\n';
        cout << endl;
    }
    bool isFind(string s, string pat)
    {
        string concate = pat + "$" + s ;
        auto z = Z_array_generate(concate) ;
        int n = s.size() ;
        int m = pat.size() ;
        for(int i = m + 1; i < n + 2; i++)
            if(z[i] == m)
                return true ;
        return false ;
    }
};
//https://cp-algorithms.com/string/z-function.html#efficient-algorithm-to-compute-the-z-function
/******************************************************************************************************************************************************************/






/***********************************Disjoint Set Union(DSU)************************************************************************************************/
class disjoint_set_union{
public:
    int parent[2001], size[2001] ;
    int find_set(int v)
    {
        if(v == parent[v])
            return v ;
        return parent[v] = find_set(parent[v]) ;
    }
    void make_set(int v)
    {
        parent[v] = v, size[v] = 1 ;
    }
    void merge(int a, int b)
    {
        a = find_set(a) ;
        b = find_set(b) ;
        if(a != b)
        {
            if(size[a] >= size[b])
            {
                parent[b] = a, size[a] += size[b] ;
            }
            else
            {
                parent[a] = b, size[b] += size[a] ;
            }
        }
    }
};
/*********************************************************************************************************************************************************************************/






/***************************************** Simple Function **************************************************************************************************************************/
int gcd(ll a, ll b)
{
    if(b == 0)
        return a ;
    return gcd(b, a % b) ;
}

bool check_Perfect_Square(ll x)  
{
    ll p = sqrt(x) ;
    p = p - 1 >= 0 ? p - 1 : p ;
    while(p * p < x)
    {
        p++ ;
    }
    return p * p == x ? true : false ;
}

int pow(int a, int b) //return (a^b)%mod
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

ll pow(int x)  // return 2^x 
{
    if(x == 0)
        return 1 ;
    if(x & 1)
        return pow(x / 2) * pow(x / 2) * 2 ;
    return pow(x / 2) * pow(x / 2) ;
}

bool check_prime(int n)
{
    if(n == 1)
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

void yes()
{
    cout << "YES" << '\n' ;
}

void no()
{
    cout << "NO" << '\n' ;
}
/***************************************************************************************************************************************************************************************/



// void dfs(vector<vector<int>> &v, int i, bool visited[], stack<int> &s)
// {
//     visited[i] = true ;
//     for(auto x : v[i])
//     {
//         if(visited[x] == false)
//         {
//             dfs(v, x, visited, s) ;
//         }
//     }
//     s.push(i) ;
// }
// void dfsutil(vector<vector<int>> &v, bool visited[], int i, vector<int> &ans)
// {
//     visited[i] = true ;
//     ans.push_back(i + 1) ;
//     for(auto x : v[i])
//     {
//         if(visited[x] == false)
//         {
//             dfsutil(v, visited, x, ans) ;
//         }
//     }
// }







// Do not quit
// Keep trying, you're close
// No looking at standings
// Atleat C
// Try D
#define ppi pair<pair<int,int>,int>
#define pi  pair<int,int>
//const int maxm = 2 * (int)(1e5) + 2 ;
//#define int long long




void main_()
{
  string s ;cin>>s ;
  int n=s.size() ;
  if(n==1)
  {
    cout<<"Just a legend" ;
    return ;
  }
  z_algorithm obj ;
  vector<int>z=obj.Z_array_generate(s);
  vector<int>maxm(n) ;
  maxm[0]=0 ;
  for(int i=1;i<n;i++)
     maxm[i]=max(maxm[i-1],z[i]) ;
  int ans=0 ;
  for(int i=n-1;i>=1;i--)
  {
    if(z[i]==n-i&&maxm[i-1]>=z[i])
        ans=z[i] ;
  }
  // for(auto x:z)
  //   cout<<x<<' ';
  if(ans>0)
  cout<<s.substr(0,ans);
  else
   cout<<"Just a legend" ; 
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int test = 1 ;
    //cin >> test ;
    while(test--)
    {
        main_();
    }
    return 0;
}
//run    ctrl+shift+B
//Shift+Alt+f: Quick Format.
//Shift+Alt+s: Selected Format.