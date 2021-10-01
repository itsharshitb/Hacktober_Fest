#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int k, int n){

    for(int i = 0; i < n; i++){
        if(arr[i] == k)
            return i+1;
    }

    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)      // taking input of array elememnts
        cin>>arr[i];

    int k;
    cin>>k;
    int ans = linear_search(arr, k, n);
    cout<<"Element is present at index "<<ans<<endl;
    return 0;
}