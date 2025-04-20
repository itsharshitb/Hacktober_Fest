#include <iostream>
using namespace std;

int getmax( int a[], int n){
    int max = 0, max2 = 0;
    for( int i=0; i<n; i++)
    {
        if( a[i] > max )
        {
            max = a[i];
        }
    }
    for( int i=0; i<n; i++)
    {
        if( a[i] != max )
        { if(a[i] > max2)
           max2 = a[i];
        }
    }

    return max2;
}

int getmin( int a[], int n){
    int min = a[0], secondmin  = a[0];
       for( int i=1; i<n; i++)
    {
        if( a[i] < min )
           min = a[i];
    }
    cout<<min<<endl;
    for( int i=1; i<n; i++)
    {
        if( a[i] != min )
        { if(a[i] < secondmin)
           secondmin = a[i];
        }
        if(secondmin == min)
        {
            secondmin = a[i++];
            i = 1;
        }
    }
    return secondmin;
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   for( int i=0; i<n; i++)
   {
       cin>>a[i];
   }
   int sec_max = getmax( a, n);
   int sec_min = getmin( a, n);
   cout<<"Second largest element of array is :"<<sec_max<<endl;
   cout<<"Second smallest element of array is :"<<sec_min<<endl;
}