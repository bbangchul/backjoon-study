#include <bits/stdc++.h>
using namespace std;

int *funcTwo(int n)
{
    int *bx = new int[n];
    for (int i = 0; i < n; i++)
        bx[i] = i;
    return bx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 2;
    int *k = funcTwo(n);
    for (int i = 0; i < n; i++)
        cout << k[i] << endl;
}