#include <stdio.h>
#include <limits.h>

using namespace std;

#define V 5



int minDistance(int dist[], bool sptSet[])
{
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
  {
    if (sptSet[v] == false && dist[v] <= min)
    {
      min = dst[v], min_index = v;
    }
  }
  return min_index;
}


int printSolution(int dist[], int n)
{
  cout << ("Vertex Distance from Source\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d tt %d\n", i, dist[i]);
  }
}


void dijkstra(int graph[V][V], int src)
{

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
  const int AE = ;

  const int BC = ;
  const int BD = ;
  const int BE = ;

  const int CD = ;
  const int CE = ;

  const int DE = ;




  int graph[V][V];


  dijkstra(graph, reno);



  return 0;
}
