#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> L = {1, 2};
    auto t = L.begin(); // t는 1을 가리키는 중
    // == list<int>::iterator t = L.gein();
    L.push_front(10); // 10, 1 , 2
    cout << *t << '\n';
    L.push_back(5); // 10, 1, 2, 5
    L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
    t++;            // t를 1칸 전진, t는 2
    t = L.erase(t);

    cout << *t << '\n';
    for (auto i : L)
        cout << i << ' ';
    cout << '\n';
    for (list<int>::iterator i = L.begin(); i != L.end(); i++)
        cout << *i << ' ';
}