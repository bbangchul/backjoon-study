#include <bits/stdc++.h> // C++ 표준 라이브러리를 한 번에 포함
using namespace std;     // std:: 생략

static const int INF = 1e9; // 충분히 큰 값, 최소값 비교에서 초기 무한대 역할

struct TreapNode // Treap의 각 노드 정보
{
    int l = 0, r = 0; // 왼쪽/오른쪽 자식 노드 인덱스
    int prio = 0;     // heap 성질을 위한 우선순위
    int keyR = 0;     // BST 정렬 기준 1: 구간의 오른쪽 끝 압축값
    int keyId = 0;    // BST 정렬 기준 2: 원래 구간의 인덱스
    int mn = INF;     // 이 서브트리에서의 최소 인덱스
};

struct RNG // 간단한 난수 생성기
{
    uint64_t x = 88172645463393265ull; // 초기 seed
    uint32_t operator()()              // 함수처럼 호출 가능하게 오버로딩
    {
        x ^= x << 7;        // xorshift 단계 1
        x ^= x >> 9;        // xorshift 단계 2
        return (uint32_t)x; // 32비트 난수 반환
    }
} rng; // 전역 난수 생성기 객체

struct Solver // 전체 풀이를 담당하는 구조체
{
    int n, m;                  // n: 구간 개수, m: 좌표 압축 후 크기
    vector<long long> a, b, c; // a[i]: 시작점, b[i]: 길이, c[i]=a[i]+b[i]
    vector<int> L, R, revL;    // 압축된 왼쪽/오른쪽 좌표, 뒤집은 왼쪽 좌표
    vector<int> ans;           // 각 i의 정답 f_i 저장
    vector<int> bitRoot;       // Fenwick tree 각 칸의 Treap 루트

    vector<TreapNode> tr; // 모든 Treap 노드 저장 배열
    int ptr = 0;          // 현재까지 사용한 Treap 노드 수

    Solver(int n) : n(n) // 생성자: 크기 초기화
    {
        a.resize(n + 1);       // 1-indexed 사용
        b.resize(n + 1);       // 1-indexed 사용
        c.resize(n + 1);       // 1-indexed 사용
        L.resize(n + 1);       // 1-indexed 사용
        R.resize(n + 1);       // 1-indexed 사용
        revL.resize(n + 1);    // 1-indexed 사용
        ans.assign(n + 1, -1); // 아직 정답이 없음을 -1로 표시
    }

    int newNode(int keyR, int keyId) // 새 Treap 노드를 생성하고 인덱스 반환
    {
        ++ptr;                     // 새 노드 번호 할당
        tr[ptr].l = tr[ptr].r = 0; // 자식 없음으로 초기화
        tr[ptr].prio = (int)rng(); // 랜덤 우선순위 부여
        tr[ptr].keyR = keyR;       // 오른쪽 끝 좌표 저장
        tr[ptr].keyId = keyId;     // 원래 인덱스 저장
        tr[ptr].mn = keyId;        // 자기 자신만 있으니 최소 인덱스는 keyId
        return ptr;                // 생성된 노드 번호 반환
    }

    bool lessKey(int r1, int id1, int r2, int id2) // (r1,id1) < (r2,id2) 판정
    {
        if (r1 != r2)       // 오른쪽 끝이 다르면
            return r1 < r2; // 오른쪽 끝이 작은 쪽이 먼저
        return id1 < id2;   // 같으면 인덱스로 tie-break
    }

    int getMn(int t) // 노드 t의 서브트리 최소 인덱스 반환
    {
        return t ? tr[t].mn : INF; // 없으면 INF 반환
    }

    void pull(int t) // 자식 정보로 현재 노드 정보 갱신
    {
        if (!t)                                                           // 빈 노드면
            return;                                                       // 갱신할 것 없음
        tr[t].mn = min(tr[t].keyId, min(getMn(tr[t].l), getMn(tr[t].r))); // 서브트리 최소 인덱스 갱신
    }

    void insertNode(int &t, int node) // Treap에 node 삽입
    {
        if (!t) // 현재 위치가 비어 있으면
        {
            t = node; // 바로 삽입
            return;   // 종료
        }
        if (lessKey(tr[node].keyR, tr[node].keyId, tr[t].keyR, tr[t].keyId)) // 삽입 노드가 더 작으면
        {
            insertNode(tr[t].l, node);         // 왼쪽 서브트리에 삽입
            if (tr[tr[t].l].prio < tr[t].prio) // heap 성질이 깨졌으면
            {
                int p = tr[t].l;   // 왼쪽 자식을 올려 회전
                tr[t].l = tr[p].r; // 회전 처리 1
                tr[p].r = t;       // 회전 처리 2
                pull(t);           // 아래로 내려간 노드 갱신
                pull(p);           // 위로 올라간 노드 갱신
                t = p;             // 루트 교체
            }
            else // 회전이 필요 없으면
            {
                pull(t); // 현재 노드 정보만 갱신
            }
        }
        else // 삽입 노드가 현재 노드보다 크거나 같으면
        {
            insertNode(tr[t].r, node);         // 오른쪽 서브트리에 삽입
            if (tr[tr[t].r].prio < tr[t].prio) // heap 성질이 깨졌으면
            {
                int p = tr[t].r;   // 오른쪽 자식을 올려 회전
                tr[t].r = tr[p].l; // 회전 처리 1
                tr[p].l = t;       // 회전 처리 2
                pull(t);           // 아래로 내려간 노드 갱신
                pull(p);           // 위로 올라간 노드 갱신
                t = p;             // 루트 교체
            }
            else // 회전이 필요 없으면
            {
                pull(t); // 현재 노드 정보만 갱신
            }
        }
    }

    void eraseNode(int &t, int keyR, int keyId) // (keyR,keyId)에 해당하는 노드 삭제
    {
        if (!t)     // 빈 트리면
            return; // 삭제할 것 없음

        if (tr[t].keyR == keyR && tr[t].keyId == keyId) // 현재 노드가 삭제 대상이면
        {
            if (!tr[t].l || !tr[t].r) // 자식이 0개 또는 1개면
            {
                t = tr[t].l ? tr[t].l : tr[t].r; // 있는 자식으로 대체
            }
            else if (tr[tr[t].l].prio < tr[tr[t].r].prio) // 두 자식이 있으면 더 우선순위 높은 쪽 기준 회전
            {
                int p = tr[t].l;                 // 왼쪽 자식을 올림
                tr[t].l = tr[p].r;               // 회전 처리 1
                tr[p].r = t;                     // 회전 처리 2
                pull(t);                         // 아래 노드 갱신
                pull(p);                         // 위 노드 갱신
                t = p;                           // 루트 교체
                eraseNode(tr[t].r, keyR, keyId); // 내려간 원래 노드 계속 삭제
                pull(t);                         // 삭제 후 갱신
            }
            else // 오른쪽 자식을 올리는 경우
            {
                int p = tr[t].r;                 // 오른쪽 자식을 올림
                tr[t].r = tr[p].l;               // 회전 처리 1
                tr[p].l = t;                     // 회전 처리 2
                pull(t);                         // 아래 노드 갱신
                pull(p);                         // 위 노드 갱신
                t = p;                           // 루트 교체
                eraseNode(tr[t].l, keyR, keyId); // 내려간 원래 노드 계속 삭제
                pull(t);                         // 삭제 후 갱신
            }
            return; // 삭제 완료
        }

        if (lessKey(keyR, keyId, tr[t].keyR, tr[t].keyId)) // 삭제 키가 더 작으면
        {
            eraseNode(tr[t].l, keyR, keyId); // 왼쪽에서 탐색
        }
        else // 아니면
        {
            eraseNode(tr[t].r, keyR, keyId); // 오른쪽에서 탐색
        }
        pull(t); // 자식 변경 후 갱신
    }

    int queryLeq(int t, int qr) // Treap에서 keyR <= qr 인 노드들 중 최소 index 반환
    {
        if (!t)               // 빈 트리면
            return INF;       // 후보 없음
        if (tr[t].keyR <= qr) // 현재 노드의 오른쪽 끝이 조건을 만족하면
        {
            return min({getMn(tr[t].l), tr[t].keyId, queryLeq(tr[t].r, qr)}); // 왼쪽 전체 + 현재 + 오른쪽 일부 확인
        }
        else // 현재 노드의 keyR이 너무 크면
        {
            return queryLeq(tr[t].l, qr); // 왼쪽만 가능
        }
    }

    void bitInsert(int idx) // idx번 구간을 Fenwick tree에 삽입
    {
        int x = revL[idx]; // 뒤집은 왼쪽 좌표에서 시작
        int rr = R[idx];   // 오른쪽 좌표
        while (x <= m)     // Fenwick tree 갱신 범위 순회
        {
            int node = newNode(rr, idx);  // 이 Fenwick 칸에 들어갈 Treap 노드 생성
            insertNode(bitRoot[x], node); // 해당 Treap에 삽입
            x += x & -x;                  // 다음 Fenwick 칸으로 이동
        }
    }

    void bitErase(int idx) // idx번 구간을 Fenwick tree에서 삭제
    {
        int x = revL[idx]; // 삽입 때와 같은 경로 사용
        int rr = R[idx];   // 오른쪽 좌표
        while (x <= m)     // Fenwick tree 갱신 범위 순회
        {
            eraseNode(bitRoot[x], rr, idx); // 각 Treap에서 해당 노드 삭제
            x += x & -x;                    // 다음 Fenwick 칸으로 이동
        }
    }

    // 남아 있는 구간 중에서
    // left >= ql, right <= qr 인 것들 중 최소 index 반환
    int queryRange(int ql, int qr)
    {
        if (ql > qr)            // 잘못된 범위면
            return INF;         // 후보 없음
        int revQl = m - ql + 1; // left >= ql 를 뒤집은 좌표 prefix 조건으로 변환
        int ret = INF;          // 현재까지 최소 인덱스
        int x = revQl;          // Fenwick prefix 탐색 시작점
        while (x > 0)           // prefix를 따라 올라가며
        {
            ret = min(ret, queryLeq(bitRoot[x], qr)); // 각 Treap에서 right <= qr 조건까지 적용
            x -= x & -x;                              // 다음 prefix 구간으로 이동
        }
        return ret; // 조건 만족 최소 인덱스 반환
    }

    void solve() // 실제 문제 풀이 수행
    {
        for (int i = 1; i <= n; i++) // a 배열 입력
            cin >> a[i];
        for (int i = 1; i <= n; i++) // b 배열 입력
        {
            cin >> b[i];        // b[i] 입력
            c[i] = a[i] + b[i]; // 오른쪽 끝 계산
        }

        vector<long long> xs;        // 좌표 압축용 배열
        xs.reserve(2 * n);           // 시작점, 끝점 총 2n개 저장 예정
        for (int i = 1; i <= n; i++) // 모든 좌표 수집
        {
            xs.push_back(a[i]); // 시작점 추가
            xs.push_back(c[i]); // 끝점 추가
        }

        sort(xs.begin(), xs.end());                       // 정렬
        xs.erase(unique(xs.begin(), xs.end()), xs.end()); // 중복 제거
        m = (int)xs.size();                               // 압축 좌표 개수 저장

        for (int i = 1; i <= n; i++) // 각 구간 좌표 압축
        {
            L[i] = (int)(lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin()) + 1; // 시작점 압축
            R[i] = (int)(lower_bound(xs.begin(), xs.end(), c[i]) - xs.begin()) + 1; // 끝점 압축
            revL[i] = m - L[i] + 1;                                                 // left >= ql 처리를 위해 뒤집은 좌표 계산
        }

        bitRoot.assign(m + 1, 0); // Fenwick tree 초기화

        long long totalEntries = 0;  // 필요한 전체 Treap 노드 수 계산
        for (int i = 1; i <= n; i++) // 각 구간마다 Fenwick에 몇 번 들어가는지 계산
        {
            int x = revL[i]; // 시작 Fenwick 위치
            while (x <= m)   // Fenwick 갱신 경로 따라가며
            {
                totalEntries++; // 노드 하나 필요
                x += x & -x;    // 다음 위치
            }
        }
        tr.assign((size_t)totalEntries + 5, TreapNode()); // 노드 배열 미리 할당

        for (int i = 1; i <= n; i++) // 모든 구간을 자료구조에 삽입
            bitInsert(i);

        int remain = n; // 아직 색을 못 정한 구간 수
        int color = 0;  // 현재 칠할 색 번호

        while (remain > 0) // 남은 구간이 있는 동안 반복
        {
            vector<pair<int, int>> st; // 현재 색으로 칠할 수 있는 영역을 관리할 스택
            st.push_back({1, m});      // 전체 좌표 범위부터 시작

            while (!st.empty()) // 처리할 영역이 남아 있으면
            {
                auto [ql, qr] = st.back(); // 맨 위 영역 꺼내기
                st.pop_back();             // 스택에서 제거
                if (ql > qr)               // 빈 구간이면
                    continue;              // 건너뛰기

                int idx = queryRange(ql, qr); // 이 영역 안에 완전히 들어오는 최소 인덱스 구간 찾기
                if (idx == INF)               // 없으면
                    continue;                 // 건너뛰기

                ans[idx] = color; // 이 구간의 색을 현재 color로 지정
                bitErase(idx);    // 자료구조에서 제거
                remain--;         // 남은 구간 수 감소

                if (R[idx] + 1 <= qr)               // 현재 구간의 오른쪽 바깥 영역이 남아 있으면
                    st.push_back({R[idx] + 1, qr}); // 오른쪽 영역 추가
                if (ql <= L[idx] - 1)               // 현재 구간의 왼쪽 바깥 영역이 남아 있으면
                    st.push_back({ql, L[idx] - 1}); // 왼쪽 영역 추가
            }

            color++; // 한 층의 색칠이 끝났으니 다음 색으로 이동
        }

        for (int i = 1; i <= n; i++) // 정답 출력
        {
            cout << ans[i] << (i == n ? '\n' : ' '); // 공백 구분 출력, 마지막은 줄바꿈
        }
    }
};

int main() // 프로그램 시작점
{
    ios::sync_with_stdio(false); // C 입출력과 동기화 해제
    cin.tie(nullptr);            // cin/cout 묶음 해제

    int n;    // 구간 개수
    cin >> n; // 입력

    Solver solver(n); // solver 생성
    solver.solve();   // 풀이 실행
    return 0;         // 정상 종료
}