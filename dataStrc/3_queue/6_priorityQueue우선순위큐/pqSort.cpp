// [알고리즘 D.8] PQ의 응용 sorting
// priorityQueue의 구현이 priorityQueue.h에 있다고 가정함.

#include "priorityQueue.h"
#include <iostream>
using namespace std;

int main() {
    priorityQueue pq;
    int v;

    for (int i=0; i<7; i++) {
        cin >> v;
        pq.InsertQ(v);
    }
    while(!pq.IsEmpty()) {
        cout << pq.DeleteQ() << " ";
    }
    cout << endl;
}
