#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
public:
    Graph(int V) : adj(V) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected Graph
    }

    void bfs(int s)
    {
        cout << "BFS starting from " << s << " : \n";
        queue<int> q;
        vector<bool> visited(adj.size(), false);
        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int curr = q.front();
            cout << curr << " ";
            q.pop();

            for (int x : adj[curr])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        cout << endl;
    }
    void dfs(int s)
    {
        cout << "DFS starting from " << s << " : \n";
        stack<int> st;
        vector<bool> visited(adj.size(), false);
        visited[s] = true;
        st.push(s);

        while (!st.empty())
        {
            int curr = st.top();
            cout << curr << " ";
            st.pop();

            for (int x : adj[curr])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    st.push(x);
                }
            }
        }
        cout << endl;
    }

private:
    vector<vector<int>> adj;
};

int main()
{
    // Number of vertices in the graph
    int V = 6;

    // Create a graph object
    Graph g(V);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    // Perform BFS traversal starting from vertex 0
    g.bfs(0);
    g.dfs(0);

    return 0;
}