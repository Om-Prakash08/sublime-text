#include<bits/stdc++.h>
using namespace std ;



/************************************************************************************************************/

#define charSize 26 
//Space :O(26*word.size()*TotalWord) 
class TrieNode { 
public:
	bool isEnd ;
	TrieNode *children[charSize] ;
	TrieNode(){
		isEnd=false ;
		for(int i=0;i<charSize;i++)
			children[i]=NULL ;
	}
};

//Time:O(word.size()) 
void insertWord(TrieNode *root, string &word) {
	for (char &c : word) {
		int index = c - 'a';
		if (root->children[index]==NULL)
			root->children[index] =new TrieNode();
		root = root->children[index];
	}
	root->isEnd = true;
}

//Time:O(word.size())
bool searchWord(TrieNode *root ,string &word){
	for(char c :word){
		int index=c-'a' ;
		if(root->children[index]==NULL)
			return false ;
		root=root->children[index] ;
	}
	return root->isEnd ;
}

//Time :O(26*TotalWord)=O(26*n)
void searchPrefixUtilDfs(TrieNode *root ,string curr, vector<string>&ans){
    if(root->isEnd)
    	ans.push_back(curr) ;
    for(int i=0;i<charSize;i++)
    	if(root->children[i])
    		searchPrefixUtilDfs(root->children[i], curr+(char)(i+'a'),ans) ;
}

//Time:O(pref.size()+26*TotalWord)
vector<string> searchPrefix(TrieNode *root ,string &pref){
	vector<string>ans ;
	for(char c:pref){
       int index=c-'a' ;
		if(root->children[index]==NULL)
			return ans ;
		root=root->children[index] ;
	}
	searchPrefixUtilDfs(root ,pref,ans) ;
	return ans ;
}





/************************************************************************************************************/
void main_(){
   TrieNode *root=new TrieNode() ;
   int n,m,p; cin>>n;
   string s ;
   for(int i=0;i<n;i++)
      {cin>>s ; 
       insertWord(root,s);}
   cin>>m ;
   while(m--){
   	cin>>s ;
   	cout<<searchWord(root,s)<<' ';
   }
   cout<<endl ;
   cin>>p ;
   while(p--){
   	cin>>s ;
    vector<string>ans=searchPrefix(root,s) ;
    for(auto s:ans)
    	cout<<s<<' ';
    cout<<endl ;
   }
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
//ctrl+shift+B: Run/Build
//Shift+Alt+f: Quick Format.
//Shift+Alt+S: Selected Format.