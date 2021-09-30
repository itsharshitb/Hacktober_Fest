#include<bits/stdc++.h>
#include<vector>
using namespace std;
void bsearch(vector<int>&v,int l,int h,int s){
    
           int mid=(l+h)/2;
        if(v[mid]>s){
          bsearch(v,l,mid,s);
        }
        else if(v[mid]<s){
            bsearch(v,mid,h,s);
        }
        else if(v[mid]==s){
            cout<<"the number "<<s<<" is found at "<<mid+1;
        }
        else{
            cout<<"the number is not found";
        }
     
}
int main(){
      int n;
     vector<int>v;
    cout<<"Enter element ";
    cin>>n;
    for(int i=0;i<n;i++){
          int x;
          cin>>x;
        v.push_back(x);
    }
    int s;
    cout<<"Enter the element to be search ";
    cin>>s;
    bsearch(v,0,n,s);
    return 0;
}