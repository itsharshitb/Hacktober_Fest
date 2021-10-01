#include<bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void permute(char str[], int L, int R)
{

	int i;
	if(L==R)
		cout<<str<<endl;
	else
	{
		for(i=1;i<=R;i++)
		{
			swap((str+L),(str+i));
			permute(str,L+1,R);
			swap((str+i),(str+L));
		}
	}
}

int main()
{
	int len;
	cin>>len;
	char str[len];
	cin>>str;
	permute(str, 0, len-1);
	return 0;
}
