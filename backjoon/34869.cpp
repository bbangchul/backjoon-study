#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

struct TreapNode
{
    int l = 0, r = 0;
    int prio = 0;
    int keyR = 0;
    int keyId = 0;
    int mn = INF;
};

struct RNG
{
    uint64_t x = 88172645463393265ull;
    uint32_t operator()()
    {
        x ^= x << 7;
        x ^= x >> 9;
        return (uint32_t)x;
    }
} rng;

struct Solver
{
    int n, m;
    vector<long long> a, b, c;
    vector<int> L, R, revL;
    vector<int> ans;
    vector<int> bitRoot;

    vector<TreapNode> tr;
    int ptr = 0;

    Solver(int n) : n(n)
    {
        a.resize(n + 1);
        b.resize(n + 1);
        c.resize(n + 1);
        L.resize(n + 1);
        R.resize(n + 1);
        revL.resize(n + 1);
        ans.assign(n + 1, -1);
    }

    int newNode(int keyR, int keyId)
    {
        ++ptr;
        tr[ptr].l = tr[ptr].r = 0;
        tr[ptr].prio = (int)rng();
        tr[ptr].keyR = keyR;
        tr[ptr].keyId = keyId;
        tr[ptr].mn = keyId;
        return ptr;
    }

    bool lessKey(int r1, int id1, int r2, int id2)
    {
        if (r1 != r2)
            return r1 < r2;
        return id1 < id2;
    }

    int getMn(int t)
    {
        return t ? tr[t].mn : INF;
    }

    void pull(int t)
    {
        if (!t)
            return;
        tr[t].mn = min(tr[t].keyId, min(getMn(tr[t].l), getMn(tr[t].r)));
    }

    void insertNode(int &t, int node)
    {
        if (!t)
        {
            t = node;
            return;
        }
        if (lessKey(tr[node].keyR, tr[node].keyId, tr[t].keyR, tr[t].keyId))
        {
            insertNode(tr[t].l, node);
            if (tr[tr[t].l].prio < tr[t].prio)
            {
                int p = tr[t].l;
                tr[t].l = tr[p].r;
                tr[p].r = t;
                pull(t);
                pull(p);
                t = p;
            }
            else
            {
                pull(t);
            }
        }
        else
        {
            insertNode(tr[t].r, node);
            if (tr[tr[t].r].prio < tr[t].prio)
            {
                int p = tr[t].r;
                tr[t].r = tr[p].l;
                tr[p].l = t;
                pull(t);
                pull(p);
                t = p;
            }
            else
            {
                pull(t);
            }
        }
    }

    void eraseNode(int &t, int keyR, int keyId)
    {
        if (!t)
            return;

        if (tr[t].keyR == keyR && tr[t].keyId == keyId)
        {
            if (!tr[t].l || !tr[t].r)
            {
                t = tr[t].l ? tr[t].l : tr[t].r;
            }
            else if (tr[tr[t].l].prio < tr[tr[t].r].prio)
            {
                int p = tr[t].l;
                tr[t].l = tr[p].r;
                tr[p].r = t;
                pull(t);
                pull(p);
                t = p;
                eraseNode(tr[t].r, keyR, keyId);
                pull(t);
            }
            else
            {
                int p = tr[t].r;
                tr[t].r = tr[p].l;
                tr[p].l = t;
                pull(t);
                pull(p);
                t = p;
                eraseNode(tr[t].l, keyR, keyId);
                pull(t);
            }
            return;
        }

        if (lessKey(keyR, keyId, tr[t].keyR, tr[t].keyId))
        {
            eraseNode(tr[t].l, keyR, keyId);
        }
        else
        {
            eraseNode(tr[t].r, keyR, keyId);
        }
        pull(t);
    }

    int queryLeq(int t, int qr)
    {
        if (!t)
            return INF;
        if (tr[t].keyR <= qr)
        {
            return min({getMn(tr[t].l), tr[t].keyId, queryLeq(tr[t].r, qr)});
        }
        else
        {
            return queryLeq(tr[t].l, qr);
        }
    }

    void bitInsert(int idx)
    {
        int x = revL[idx];
        int rr = R[idx];
        while (x <= m)
        {
            int node = newNode(rr, idx);
            insertNode(bitRoot[x], node);
            x += x & -x;
        }
    }

    void bitErase(int idx)
    {
        int x = revL[idx];
        int rr = R[idx];
        while (x <= m)
        {
            eraseNode(bitRoot[x], rr, idx);
            x += x & -x;
        }
    }

    // 남아 있는 구간 중에서
    // left >= ql, right <= qr 인 것들 중 최소 index 반환
    int queryRange(int ql, int qr)
    {
        if (ql > qr)
            return INF;
        int revQl = m - ql + 1;
        int ret = INF;
        int x = revQl;
        while (x > 0)
        {
            ret = min(ret, queryLeq(bitRoot[x], qr));
            x -= x & -x;
        }
        return ret;
    }

    void solve()
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            c[i] = a[i] + b[i];
        }

        vector<long long> xs;
        xs.reserve(2 * n);
        for (int i = 1; i <= n; i++)
        {
            xs.push_back(a[i]);
            xs.push_back(c[i]);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        m = (int)xs.size();

        for (int i = 1; i <= n; i++)
        {
            L[i] = (int)(lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin()) + 1;
            R[i] = (int)(lower_bound(xs.begin(), xs.end(), c[i]) - xs.begin()) + 1;
            revL[i] = m - L[i] + 1;
        }

        bitRoot.assign(m + 1, 0);

        long long totalEntries = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = revL[i];
            while (x <= m)
            {
                totalEntries++;
                x += x & -x;
            }
        }
        tr.assign((size_t)totalEntries + 5, TreapNode());

        for (int i = 1; i <= n; i++)
            bitInsert(i);

        int remain = n;
        int color = 0;

        while (remain > 0)
        {
            vector<pair<int, int>> st;
            st.push_back({1, m});

            while (!st.empty())
            {
                auto [ql, qr] = st.back();
                st.pop_back();
                if (ql > qr)
                    continue;

                int idx = queryRange(ql, qr);
                if (idx == INF)
                    continue;

                ans[idx] = color;
                bitErase(idx);
                remain--;

                if (R[idx] + 1 <= qr)
                    st.push_back({R[idx] + 1, qr});
                if (ql <= L[idx] - 1)
                    st.push_back({ql, L[idx] - 1});
            }

            color++;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Solver solver(n);
    solver.solve();
    return 0;
}