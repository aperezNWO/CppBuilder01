///////////////////////////////////////////////////////////////////////////
// DIJTRA ALGORITHM
///////////////////////////////////////////////////////////////////////////


#ifndef Dijkstra_H // include guard
#define Dijkstra_H
#endif

#include "iterativeList.h"
#include "recursiveList.h"
#include <sstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <random>
#include <string>

   class Dijkstra
   {
	   public :
		  Dijkstra();
		  ~Dijkstra();
		  int             OpenFile();
		  int             SetFile_int(int* array, int arraySize, char* fileName);
		  int             SetFile_char(char** array, int arraySize, char* fileName);
		  int             minDistance(vector<int> dist, vector<bool> sptSet, int p_vertexSize);
		  string          GetDijkstra(vector<string> vertex, int** graph, int p_vertexSize, int p_sampleSize, int p_sourcePoint);
		  void            SetDijkstra(int** graph, int src, int vertexSize);
		  float           Pitagorean(float coord_x, float coord_y);
		  vector<int>     FisherYates(int count);
		  float           GetHipotemuza(const char*vertexString, int index_x, int index_y);
		  vector<string>  StringSplit(const char* p_inputString, std::string p_delimiter,bool adjust);
		  string          GenerateRandomMatrix(const char* vertexString, int** graph ,int p_vertexSize);
		  string          GetRandomPoints(int p_vertexSize, int p_sourcePoint);
	  public :
		  vector<int>    dist;         // The output array.  dist[i] will hold the shortest
		  vector<string> path;
		  std::random_device rd_1;    // Seed the generator with a random value om a hardware device
		  std::mt19937       mt_1;
   };
