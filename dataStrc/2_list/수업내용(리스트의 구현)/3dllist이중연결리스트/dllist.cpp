// [알고리즘 C.7] dllist.cpp
// 이중 연결 리스트: 각 노드가 이전 노드와 다음 노드의 주소를 모두 저장한다.
// 예: head_ → [2] ⇄ [3] ⇄ [5] ← tail_
// 포인터의 값이 0이면 가리키는 노드가 없다는 뜻이다.
#include <iostream>
#include "dllist.h"
using namespace std;

// 생성자: 처음에는 노드가 없는 빈 리스트로 시작한다.
dllist::dllist()
{
    head_ = 0;
    tail_ = 0;
}

// item을 넣어 값이 작은 노드부터 큰 노드 순서로 유지한다.
void dllist::Insert(int item)
{
    // 1. 빈 리스트: 새 노드 하나가 첫 노드이자 마지막 노드가 된다.
    if (head_ == 0)
    {
        head_ = new dlnode(item); // 새 노드를 만들고 그 주소를 head_에 저장
        tail_ = head_;
        return;
    }
    // 2. 첫 값보다 작거나 같으면 맨 앞에 삽입한다.
    if (item <= head_->data_)
    {
        dlnode *ptr = new dlnode(item, 0, head_); // 새 노드의 next_는 기존 첫 노드
        head_->prev_ = ptr;                       // 기존 첫 노드의 이전 노드를 새 노드로 연결
        head_ = ptr;                              // 리스트의 시작 위치를 새 노드로 변경
        return;
    }
    // 3. 마지막 값보다 크면 맨 뒤에 삽입한다.
    if (tail_->data_ < item)
    {
        dlnode *ptr = new dlnode(item, tail_, 0); // 새 노드의 prev_는 기존 마지막 노드
        tail_->next_ = ptr;                       // 기존 마지막 노드에서 새 노드로 연결
        tail_ = ptr;                              // 리스트의 끝 위치를 새 노드로 변경
        return;
    }
    // 4. item 이상인 첫 노드를 찾아 그 노드 바로 앞에 삽입한다.
    // ptr은 탐색용 포인터이므로 이동해도 head_는 바뀌지 않는다.
    dlnode *ptr = head_;
    while (ptr->data_ < item)
        ptr = ptr->next_;
    // 삽입 전: 이전 노드 ⇄ ptr
    // 삽입 후: 이전 노드 ⇄ nptr ⇄ ptr
    dlnode *nptr = new dlnode(item, ptr->prev_, ptr);
    ptr->prev_->next_ = nptr; // 이전 노드의 next_를 새 노드로 변경
    ptr->prev_ = nptr;        // ptr의 prev_를 새 노드로 변경
}

// value와 같은 값을 가진 첫 번째 노드 하나를 찾아 삭제한다.
void dllist::Delete(int value)
{
    // 첫 노드부터 next_를 따라 이동하며 삭제할 노드를 찾는다.
    dlnode *ptr = head_;
    while (ptr != 0 && ptr->data_ != value)
        ptr = ptr->next_;
    if (ptr == 0) // 값이 없음
        return;

    // 앞쪽 연결을 수정해서 삭제할 노드를 건너뛴다.
    if (ptr->prev_ == 0) // 맨 앞 노드
        head_ = ptr->next_;
    else
        ptr->prev_->next_ = ptr->next_;

    // 뒤쪽 연결도 수정한다. 양방향 연결을 모두 바꿔야 한다.
    if (ptr->next_ == 0) // 맨 뒤 노드
        tail_ = ptr->prev_;
    else
        ptr->next_->prev_ = ptr->prev_;

    // 노드가 하나뿐이었다면 위 과정에서 head_와 tail_이 모두 0이 된다.
    delete ptr; // 연결에서 제외한 노드의 메모리를 해제한다.
}

// 첫 노드부터 next_를 따라가며 오름차순으로 출력한다.
void dllist::Print()
{
    for (dlnode *ptr = head_; ptr != 0; ptr = ptr->next_)
        cout << ptr->data_ << " ";
    cout << endl;
}

// 마지막 노드부터 prev_를 따라가며 내림차순으로 출력한다.
void dllist::PrintReverse()
{
    for (dlnode *ptr = tail_; ptr != 0; ptr = ptr->prev_)
        cout << ptr->data_ << " ";
    cout << endl;
}

int main()
{
    dllist lst; // 포인터가 아닌 dllist 객체. 생성자가 호출되어 빈 리스트가 된다.
    int v;      // 사용자가 입력한 값을 잠시 저장한다.

    // 정수 7개를 입력받아 정렬된 위치에 각각 삽입한다.
    for (int i = 0; i < 7; i++)
    {
        cin >> v;
        lst.Insert(v);
    }
    // 정수 3개를 입력받아 해당 값의 노드를 각각 삭제한다.
    for (int i = 0; i < 3; i++)
    {
        cin >> v;
        lst.Delete(v);
    }
    lst.Print();        // 남은 값을 앞에서 뒤로 출력
    lst.PrintReverse(); // 남은 값을 뒤에서 앞으로 출력
    // 현재 클래스에는 소멸자가 없어 남은 노드를 직접 해제하는 처리는 없다.
}