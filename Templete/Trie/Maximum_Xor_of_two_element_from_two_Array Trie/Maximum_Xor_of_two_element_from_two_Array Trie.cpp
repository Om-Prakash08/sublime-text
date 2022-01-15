#include<bits/stdc++.h>
using namespace std ;



/************************************************************************************************************/
//Problem Statement
//You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’. 
//Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ 
//are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the 
//bitwise xor operation.
// link : https://www.codingninjas.com/codestudio/problems/maximum-xor_973113?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

class Node {
      public:
      Node *child[2] ; 
      Node(){
      child[0]=child[1]=NULL ;
  }
};
class Trie{
    Node *root ;
    public:
    Trie(){
        root=new Node() ;
    }
    void insert(int n){
        Node *curr=root ;
        for(int i=31;i>=0;i--){
          int index=(n>>i)&1 ;
          if(curr->child[index]==NULL)
              curr->child[index]=new Node() ;
          curr=curr->child[index] ;
        }
    }
   int maxXor(int n){
       Node *curr=root ;
       int ans=0 ;
       for(int i=31;i>=0;i--){
          int index=1-((n>>i)&1) ;
          if(curr->child[index])
          {
             curr=curr->child[index] ; 
             ans+=(1<<i) ;
          }else{
             curr=curr->child[1-index] ;  
          }
        }
       return ans ;
   }
};

//time :O(n*32+m*32) space:O(n*32*2) 
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{Trie trie=Trie() ;
 int ans=0 ;
 for(int i=0;i<n;i++)
     trie.insert(arr1[i]) ;
 for(int j=0;j<m;j++)
     ans=max(ans,trie.maxXor(arr2[j])) ;
 return ans ;
}

/************************************************************************************************************/
void main_()
{
    vector<int>a{4,5,7,2,4} ;
    vector<int>b{4,5,6666,24,55} ;
    cout<<maxXOR(5,5,a,b)<<' ';
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
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