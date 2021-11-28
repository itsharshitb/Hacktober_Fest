#include<bits/stdc++.h>
int main()
{
    int a,b,m,n;
    printf("Enter Length and Breadth of Array1:");
    scanf("%d %d",&a,&b);
    printf("Enter Length and Breadth of Array2:");
    scanf("%d %d",&m,&n);
    if(b!=m)
    {
        printf("Array can't be Multiplied");
        return 0;
    }
    int arr1[a][b];
    int arr2[m][n];
    printf("Enter values of Array1:");
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter values of Array2:");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    int arr[a][n];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
            for(int k=0;k<b;k++)
            {
                arr[i][j]+=arr1[i][k]*arr2[k][j];                                                                       
            }
        }
    }
    printf("Multiplied Array is:");
    for(int i=0;i<a ;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",arr[i][j]);
        }
    }
    return 0;
}
