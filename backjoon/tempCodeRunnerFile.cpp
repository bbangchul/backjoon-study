#include <iostream>
using namespace std;

struct Node
{
    int vertex;
    Node *next;
};

void addEdge(Node **graph, int u, int v)
{
    Node *newNode1 = new Node;
    newNode1->vertex = v;
    newNode1->next = graph[u];
    graph[u] = newNode1;

    Node *newNode2 = new Node;
    newNode2->vertex = u;
    newNode2->next = graph[v];
    graph[v] = newNode2;
}

void dfs(Node **graph, bool *visited, int start)
{
    visited[start] = true;

    Node *cur = graph[start];
    while (cur != nullptr)
    {
        if (!visited[cur->vertex])
        {
            dfs(graph, visited, cur->vertex);
        }
        cur = cur->next;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 인접리스트 동적할당
    Node **graph = new Node *[N + 1];
    for (int i = 1; i <= N; i++)
    {
        graph[i] = nullptr;
    }

    // 방문 배열 동적할당
    bool *visited = new bool[N + 1];
    for (int i = 1; i <= N; i++)
    {
        visited[i] = false;
    }

    // 간선 입력
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    int count = 0;

    // 모든 정점 검사
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
            count++;
        }
    }

    cout << count << '\n';

    // 메모리 해제
    for (int i = 1; i <= N; i++)
    {
        Node *cur = graph[i];
        while (cur != nullptr)
        {
            Node *temp = cur;
            cur = cur->next;
            delete temp;
        }
    }

    delete[] graph;
    delete[] visited;

    return 0;
}