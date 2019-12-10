#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define V 5



int minDistance(int dist[], bool sptSet[])
{
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
  {
    if (sptSet[v] == false && dist[v] <= min)
    {
      min = dist[v], min_index = v;
    }
  }
  return min_index;
}


void printSolution(int dist[], int n)
{
  cout << ("Vertex Distance from Source\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d tt %d\n", i, dist[i]);
  }
}


void dijkstra(int graph[V][V], int src)
{
  int dist[V];

  bool sptSet[V];

  for (int i = 0; i < V; i++)
  {
    dist[i] = INT_MAX, sptSet[i] = false;
  }

  dist[src] = 0;

  for (int cnt = 0; cnt < V - 1; cnt++)
  {
    int u = minDistance(dist, sptSet);
    sptSet[u] = true;

    for (int v = 0; v < V; v++)
    {
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
        (dist[u] + graph[u][v]) < dist[v])
        {
          dist[v] = dist[u] + graph[u][v];
        }
    }
  }
  printSolution(dist, V);
}



int TSP(int graph[V][V], int src)
{
  vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != src)
            vertex.push_back(i);


    int minPath = INT_MAX;
    for (int cnt = 0; cnt < vertex.size(); cnt++)
    {

        int currentWeight = 0;

        int k = src;
        for (int i = 0; i < vertex.size(); i++) {
            currentWeight += graph[k][vertex[i]];
            k = vertex[i];
        }
        currentWeight += graph[k][src];

        // update minimum
        minPath = min(minPath, currentWeight);

    } //while (next_permutation(vertex.begin(), vertex.end()));

    return minPath;
  }





int main()
{
  // Cities as integers
  const int reno = 0;           // A
  const int sanFrancisco = 1;   // B
  const int saltLakeCity = 2;   // C
  const int seattle = 3;        // D
  const int lasVegas = 4;       // E

  //Cost Variables
  const int AB = 218;
  const int AC = 518;
  const int AD = 704;
  const int AE = 439;

  const int BC = 736;
  const int BD = 808;
  const int BE = 569;

  const int CD = 840;
  const int CE = 421;

  const int DE = 1115;




  int graph[V][V] = { {0, AB, AC, AD, AE}, // At A
                      {AB, 0, BC, BD, BE}, // At B
                      {AC, BC, 0, CD, CE}, // At C
                      {AD, BD, CD, 0, DE}, // At D
                      {AE, BE, CE, DE, 0}  // At E
                    };



  cout << TSP(graph, reno);



  return 0;
}
