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

void dfs_G(int node, vector<int> &hasVisited, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(node);
    hasVisited[node] = 1;

    for (auto x : adj[node])
    {
        if (!hasVisited[x])
        {
            dfs_G(x, hasVisited, adj, dfs);
        }
    }
}

vector<int> Dfs(vector<int> adj[], int n)
{
    vector<int> dfs;
    vector<int> hasVisited(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!hasVisited[i])
        {
            dfs_G(i, hasVisited, adj, dfs);
        }
    }
    return dfs;
}

void printDFS(vector<int> dfs)
{
    cout << "DFS of the graph : ";
    for (auto t : dfs)
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

    vector<int> d = Dfs(adj, n);
    printDFS(d);
}