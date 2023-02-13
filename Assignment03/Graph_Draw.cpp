#include "Simulation.h"
#include "Graph.h"
#include <bits\stdc++.h>
using namespace std;

class GraphDraw : public Screen
{
private:
  int jump;
  int x;
};

int main()
{
  cout << "\t\t Graph Drawing in c++\n";
  cout << "Enter the number of vertices in the graph\n";
  int v;
  cin >> v;
  Graph G(v);
  cout << "Enter the number of edges in the graph\n";
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter the source point followed by destination\n";
    int a, b;
    G.addEdge(a, b);
  }
  for (int i = 0; i < v; i++)
  {
  }
}