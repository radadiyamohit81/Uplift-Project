#include <iostream>
#include <list>
using namespace std;
class Graph
{
        int V; 
        list<int> *adj;
    public:
        Graph(int V);
        void addEdge(int v, int w);
        bool isReachable(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int> [V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}

bool Graph::isReachable(int s, int d)
{
    if (s == d)
        return true;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;
 
    visited[s] = true;
    queue.push_back(s);
 
    list<int>::iterator i;
 
    while (!queue.empty())
    {
        s = queue.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (*i == d)
                return true;
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
 
    return false;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
	}
    Graph g(10);
    int e;
    cin >> e;
    for(int i=0;i<e;i++){
		int u,v;
		cin >> u >> v;
		g.addEdge(u, v);
    }
	int s, d;
    cin >> s >> d;
    if (g.isReachable(s, d))
        cout << 1;
    else
        cout << 0;
    return 0;
}
