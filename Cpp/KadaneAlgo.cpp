#include<iostream>
using namespace std;
int kadane(int arr[], int ln)
{
	int max=0,present=0;
	for(int i=0;i<ln;i++)
	{
		present+=arr[i];
		if(present<0)
			present=0;
		else if(max<present)
			max=present;
	}
return max;
}
int main()
{
	int ln;
	cin>>ln;
	int arr[ln];
	for(int i=0;i<ln;i++)
		cin>>arr[i];
	int maxsub=kadane(arr,ln);
	cout<<maxsub;
	return 0;
}
