#include<bits/stdc++.h>
using namespace std;
void build(vector<int> &tree, vector<int> &a, int idx, int st, int en) // building the segment tree
{
    if(st==en)
    {
        tree[idx]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(tree,a,(2*idx)+1,st,mid);
    build(tree,a,(2*idx)+2,mid+1,en);
    tree[idx]=min(tree[(2*idx)+1],tree[(2*idx)+2]); // change this line as per requirement
}
void update(vector<int> &tree, vector<int> &a, int idx, int st, int en, int y, int z) // point update, A[y]=z
{
    if(st==en)
    {
        tree[idx]=z;
        return;
    }
    int mid=(st+en)/2;
    if(st<=y && y<=mid)
    update(tree,a,(2*idx)+1,st,mid,y,z);
    else
    update(tree,a,(2*idx)+2,mid+1,en,y,z);
    tree[idx]=min(tree[(2*idx)+1],tree[(2*idx)+2]); // change this line as per requirement
}
int query(vector<int> &tree, int idx, int st, int en, int l, int r) // query of finding something in range L to R
{
    if(l>en || r<st)
    return INT_MAX;
    if(l<=st && r>=en)
    return tree[idx];
    int mid=(st+en)/2;
    return min(query(tree,(2*idx)+1,st,mid,l,r),query(tree,(2*idx)+2,mid+1,en,l,r)); // change this line as per requirement
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n); // input array
	vector<int> tree(4*n); // segment tree
    build(tree,a,0,0,n-1);
    int q;
    cin>>q;
}
