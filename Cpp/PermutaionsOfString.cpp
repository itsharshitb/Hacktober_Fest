#include <bits/stdc++.h>
using namespace std;

void Perm(string s, int k)
{
    static int A[10] = {0};
    static char Res[10];
    int i;

    if (s[k] == '\0')
    {
        Res[k] = '\0';
        cout << Res << endl;
    }

    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                Perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    string name;
    cin >> name;
    Perm(name, 0);
    return 0;
}