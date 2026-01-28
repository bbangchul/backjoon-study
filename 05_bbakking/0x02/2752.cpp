#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> v(3);
    int a, b, c;
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < 3; i++)
    {
        cout << v[i] << " ";
    }
}

// int main(void)
// {
//     vector<int> v(3);
//     int big;
//     int mid;
//     int sml;
//     for (int i = 0; i < 3; i++)
//     {
//         cin >> v[i];
//     }
//     if (v[0] > v[1])
//     {
//         if (v[0] > v[2])
//         {
//             big = v[0];
//             if (v[1] > v[2])
//             {
//                 mid = v[1];
//                 sml = v[2];
//             }
//             else
//             {
//                 mid = v[2];
//                 sml = v[1];
//             }
//         }
//         else
//         {
//             big = v[2];
//             mid = v[0];
//             sml = v[1];
//         }
//     }
//     else
//     {
//         if (v[1] > v[2])
//         {
//             big = v[1];
//             if (v[2] > v[0])
//             {
//                 mid = v[2];
//                 sml = v[0];
//             }
//             else
//             {
//                 mid = v[0];
//                 sml = v[2];
//             }
//         }
//         else
//         {
//             big = v[2];
//             mid = v[1];
//             sml = v[0];
//         }
//     }

//     cout << sml << ' ' << mid << ' ' << big;
// }