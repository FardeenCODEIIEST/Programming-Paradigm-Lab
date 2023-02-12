#include <bits\stdc++.h>
using namespace std;

class Graph
{
private:
  int V;
  list<int> *adj;

public:
  Graph(int);
  void addEdge(int, int);
  void Union(Graph &);
  void Intersection(Graph &);
  void display();
  void DFS(int, bool *);
  bool isConnected();
  int disconnectedVertex();
  void degree();
  bool isReachable(int, int);
};

Graph::Graph(int v)
{
  this->V = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int a, int b)
{
  adj[a].push_back(b);
  adj[b].push_back(a);
}

void Graph::display()
{
  for (int i = 0; i < this->V; i++)
  {
    for (auto it : adj[i])
    {
      cout << i << "-->" << it << "\n";
    }
  }
}

void Graph::Intersection(Graph &G)
{
  Graph G3(this->V);
  set<pair<int, int>> mp;
  for (int i = 0; i < this->V; i++)
  {
    for (auto it : adj[i])
    {
      mp.insert({i, it});
    }
  }
  for (int i = 0; i < G.V; i++)
  {
    for (auto it : G.adj[i])
    {
      pair<int, int> r1 = {i, it};
      pair<int, int> r2 = {it, i};
      if (mp.find(r1) != mp.end() || mp.find(r2) != mp.end())
      {
        G3.adj[i].push_back(it);
      }
    }
  }
  G3.display();
}

void Graph::Union(Graph &G)
{
  Graph G1(this->V + G.V);
  set<pair<int, int>> mp;
  for (int i = 0; i < this->V; i++)
  {
    for (auto it : adj[i])
    {
      mp.insert({i, it});
      G1.adj[i].push_back(it);
    }
  }
  for (int i = 0; i < G.V; i++)
  {
    for (auto it : G.adj[i])
    {
      pair<int, int> r1 = {i, it};
      pair<int, int> r2 = {it, i};
      if (mp.find(r1) != mp.end() || mp.find(r2) != mp.end())
        continue;
      G1.adj[i].push_back(it);
    }
  }
  G1.display();
}

void Graph::DFS(int v, bool *visited)
{
  visited[v] = true;
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); i++)
  {
    if (!visited[*i])
    {
      DFS(*i, visited);
    }
  }
}

bool Graph::isConnected()
{
  bool visited[V];
  memset(visited, false, sizeof(visited));
  DFS(0, visited);
  for (int i = 1; i < V; i++)
  {
    if (visited[i] == false)
    {
      return false;
    }
  }
  return true;
}

int Graph::disconnectedVertex()
{
  int i;
  for (i = 0; i < V; i++)
  {
    if (adj[i].empty())
    {
      break;
    }
  }
  return i;
}

void Graph::degree()
{
  int d[V] = {};
  for (int i = 0; i < V; i++)
  {
    int c = 0;
    for (auto it : adj[i])
    {
      if (it != i)
      {
        c++;
      }
    }
    d[i] = c;
  }
  for (int i = 0; i < V; i++)
  {
    cout << "Degree of node " << i << " is : " << d[i] << "\n";
  }
}

bool Graph::isReachable(int u, int v)
{
  if (u == v)
  {
    return true;
  }
  vector<bool> visited(V, false);
  queue<int> q;
  visited[u] = true;
  q.push(u);
  while (!q.empty())
  {
    u = q.front();
    q.pop();
    for (auto it : adj[u])
    {
      if (it == v)
      {
        return true;
      }
      if (!visited[it])
      {
        visited[it] = true;
        q.push(it);
      }
    }
  }
  return false;
}

int main()
{
  cout << "\t\t Graph Implementation in C++ via adjacency list approach\n";
  cout << "Graph G1\n";
  cout << "Enter the number of vertices in Graph G1\n";
  int g1;
  cin >> g1;
  Graph G1(g1);
  cout << "Enter the number of edges in Graph G1\n";
  int ed1;
  cin >> ed1;
  cout << "Enter the edges source followed by destination\n";
  for (int i = 0; i < ed1; i++)
  {
    int a, b;
    cin >> a >> b;
    G1.addEdge(a, b);
  }
  cout << "Graph G2\n";
  cout << "Enter the number of vertices in Graph G2\n";
  int g2;
  cin >> g2;
  Graph G2(g2);
  cout << "Enter the number of edges in Graph G2\n";
  int ed2;
  cin >> ed2;
  cout << "Enter the edges source followed by destination\n";
  for (int i = 0; i < ed2; i++)
  {
    int a, b;
    cin >> a >> b;
    G2.addEdge(a, b);
  }
  cout << "Graph G1 is:\n";
  G1.display();
  cout << "Graph G2 is:\n";
  G2.display();
  cout << "Union of G1 and G2 is\n";
  G1.Union(G2);
  cout << "Intersection of G1 and G2 is\n";
  G1.Intersection(G2);
  if (G1.isConnected())
  {
    cout << "G1 is connected graph\n";
  }
  else
  {
    cout << "G1 is disconnected at vertex: " << G1.disconnectedVertex() << "\n";
  }
  if (G2.isConnected())
  {
    cout << "G2 is connected graph\n";
  }
  else
  {
    cout << "G2 is disconnected at vertex: " << G2.disconnectedVertex() << "\n";
  }
  cout << "Degree of nodes in G1\n";
  G1.degree();
  cout << "Degree of nodes is G2\n";
  G2.degree();
  cout << "Enter the vertices where path is to be found in G1\n";
  int u1, v1;
  cin >> u1 >> v1;
  if (G1.isReachable(u1, v1))
  {
    cout << "There exists a path between " << u1 << " and " << v1 << "\n";
  }
  else
  {
    cout << "There is no path\n";
  }
  cout << "Enter the vertices where path is to be found in G2\n";
  int u2, v2;
  cin >> u2 >> v2;
  if (G2.isReachable(u2, v2))
  {
    cout << "There exists a path between " << u2 << " and " << v2 << "\n";
  }
  else
  {
    cout << "There is no path\n";
  }
  return 0;
}