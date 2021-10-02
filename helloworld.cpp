#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
#define pb push_back
#define fz(i,a,b) for(ll i=a; i<b; i++)
#define bz(i,a,b) for(ll i=a-1; i>=b; i--)
#define debug(x) cout << #x << " " << x << endl;
typedef long long int ll;
typedef long double lld;
 
/*#define debug(x);
printf(x);*/
 
void init()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt" , "r"  ,stdin); 
  freopen("output.txt" , "w" ,stdout);
  #endif
 
}
 
void  debugger()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt" , "r"  ,stdin); 
  freopen("output.txt" , "w" ,stdout);
  #endif
  #ifdef debugger
  #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
  #else
  #define debugger(x);
  #endif
} 
 
 
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
 
 
void precision(int a) 
{
  cout << setprecision(a) << fixed;
}
 
 
//** pritishcf307 **//
//**------------------------------------------------------------------------------------------------------**//

//airline restriction codechef



int main()
{
  init();
  cout << "hello world" << endl;
  cout << "hi" << endl;
}




// thank you
    
