#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct TrieNode
{
	map<char,TrieNode*> mp;
	bool isEnd;
	TrieNode()
	{
		isEnd=false;
	}
};
struct TrieNode* root;

void insertNode(string s)
{
	TrieNode* curr=root;
	for(int i=0;i<s.length();i++)
	{
		if(curr->mp.count(s[i])==0)
		curr->mp[s[i]]=new TrieNode();
		curr=curr->mp[s[i]];
	}
	curr->isEnd=true;
}

void deleteNode(string s)
{
	TrieNode* curr=root, *parent=root;
	char child=s[0];
	for(int i=0;i<s.length();i++)
	{
		if(curr->mp[s[i]]->mp.size()>1)
		{
			parent=curr->mp[s[i]];
			if(i<s.length()-1)
			child=s[i+1];
		}
		curr=curr->mp[s[i]];
	}
	curr->isEnd=false;
	if(curr->mp.empty())
	{
		parent->mp.erase(child);
	}
}

bool searchNode(string s)
{
	TrieNode* curr=root;
	for(int i=0;i<s.length();i++)
	{
		if(curr->mp.count(s[i])==0)
		return false;
		curr=curr->mp[s[i]];
	}
	return curr->isEnd;
}
int main()
{
	root=new TrieNode();
	insertNode("ghanshyam");
	insertNode("ghanshyaminathan");
//	insertNode("qqrs");
//	insertNode("pqst");
//	insertNode("pqrs");
	deleteNode("ghanshyam");
//	deleteNode("pqrs");
	cout<<searchNode("ghanshyaminathan");
	cout<<searchNode("ghanshyam");
}
