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
