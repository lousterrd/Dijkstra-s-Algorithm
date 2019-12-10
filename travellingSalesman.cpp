#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define V 5

string pathSet(string &path, int k)
{

  if (k == 1)
    path += "B";
  else if (k == 2)
    path += "C";
  else if (k == 3)
    path += "D";
  else if (k == 4)
    path += "E";
  else
    path += "A";
  return path;
}

int TSP(int graph[V][V], int src)
{
  vector<int> vertex;
  for (int i = 0; i < V; i++)
  {
    if (i != src)
    {
      vertex.push_back(i);
    }
  }

  int minPath = INT_MAX;
  do
  {
    int currentWeight = 0;

    string path = "A";
    int k = src;
    for (int i = 0; i < vertex.size(); i++)
    {
        currentWeight += graph[k][vertex[i]];
        k = vertex[i];
        pathSet(path, k);
    }
    path += "A";
    cout << "Path: " << path << endl;
    currentWeight += graph[k][src];


    // update minimum
    minPath = min(minPath, currentWeight);
    cout << "Path Length: " << minPath << endl;

  } while (next_permutation(vertex.begin(), vertex.end()));
  cout << endl;
  return minPath;
}





int main()
{
  // Cities as Integers
  const int reno = 0;           // A
  const int sanFrancisco = 1;   // B
  const int saltLakeCity = 2;   // C
  const int seattle = 3;        // D
  const int lasVegas = 4;       // E

  //Cost Variables in Miles
  const int AB = 218;           // Reno to San Franciso
  const int AC = 518;           // Reno to Salt Lake City
  const int AD = 704;           // Reno to Seattle
  const int AE = 439;           // Reno to Las Vegas

  const int BC = 736;           // San Franciso to Salt Lake City
  const int BD = 808;           // San Franciso to Seattle
  const int BE = 569;           // San Franciso to Las Vegas

  const int CD = 840;           // Salt Lake City to Seattle
  const int CE = 421;           // Salt Lake City to Las Vegas

  const int DE = 1115;          // Seattle to Las Vegas




  int graph[V][V] = { {0, AB, AC, AD, AE}, // At A
                      {AB, 0, BC, BD, BE}, // At B
                      {AC, BC, 0, CD, CE}, // At C
                      {AD, BD, CD, 0, DE}, // At D
                      {AE, BE, CE, DE, 0}  // At E
                    };



  cout << TSP(graph, reno) << endl;
  cout << "When TSP(graph, reno) is called, it returns the above value as the ";
  cout << "shortest path." << endl;


  return 0;
}
