#include<bits/stdc++.h>
using namespace std;
#define ll long long
int fib1(ll n){
    ll dp[n+2];
        dp[0]=0;
        dp[1]=1;
        
        for(ll i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
}
int dp[10000];
int fib2(int n){
    if(n==0) return 0;
    if(n==1||n==2) return n-1;

    if(dp[n]!=NULL)return dp[n];

    else
    dp[n]=fib2(n-1)+fib2(n-2);

    return dp[n];
}

int main(){
    ll n;
    cin>>n;
    cout<<fib1(n);

}