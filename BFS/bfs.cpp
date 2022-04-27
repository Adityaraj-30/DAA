#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{

    for (int i = 1; i <= V; i++)
    {
        cout << "Adjacenct list for node " << i << " is : head";
        for (auto x : adj[i])
        {
            cout << "->" << x;
        }
        cout << endl;
    }

    cout << endl;
}

vector<int> bfs(vector<int> adj[], int n)
{
    vector<int> bfs;
    vector<int> hasVisited(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {

        if (!hasVisited[i])
        {

            queue<int> q;
            q.push(i);
            hasVisited[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto x : adj[i])
                {
                    if (!hasVisited[x])
                    {
                        q.push(x);
                        hasVisited[x] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

void printBFS(vector<int> bfs)
{
    cout << "BFS of the graph is : ";
    for (auto t : bfs)
    {
        cout << t << " , ";
    }
    cout << endl;
}

int main()
{

    int n, m;
    int u, v;

    cout << "Enter number of nodes : ";
    cin >> n;
    vector<int> adj[n + 1];

    cout << "Enter number of edges : ";
    cin >> m;

    cout << "Enter edges: ";
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        cout << "For edge " << i + 1 << endl;
        cout << "Enter starting node :";
        cin >> u;
        cout << "Enter ending node : ";
        cin >> v;
        cout << endl;
        addEdge(adj, u, v);
    }
    vector<int> b = bfs(adj, n);
    printBFS(b);
}