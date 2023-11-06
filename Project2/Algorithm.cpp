///////////////////////////////////////////////////////////////////////////
// CLASS DIJKSTRA - METHOD IMPLEMENTATIONS
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// ALGORITHM.LIBRARY.DLL
///////////////////////////////////////////////////////////////////////////

#include "Algorithm.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <limits.h>
#include <iomanip>
#include <memory>

using namespace std;

#pragma hdrstop
#pragma argsused

extern "C"
{
	//
	Dijkstra::Dijkstra()
	{
		//
	}
	//
	Dijkstra::~Dijkstra()
	{
		 //
	}
	//
	int Dijkstra::OpenFile()
	{
		// declaration of file pointer
		FILE* fp = NULL;
		// declaration of variable
		int x;
		// opening of file
		fopen_s(&fp, "file.txt", "w+");
		// checking of error
		if (!fp)
			return 1;
		// giving content
		for (x = 1; x <= 10; x++)
			fprintf(fp, "%d\n", x);
		// closing of file
		fclose(fp);
		//
		return 0;
	}
	//
	int Dijkstra::SetFile_int(int* array, int arraySize, char* fileName)
	{
		// declaration of file pointer
		FILE* fp = NULL;
		// declaration of variable
		int x;
		// opening of file
		fopen_s(&fp, fileName, "w+");
		// checking of error
		if (!fp)
			return 1;
		// giving content
		for (int i = 0; i < arraySize; i++)
			fprintf(fp, "%d\n", array[i]);
		// closing of file
		fclose(fp);
		//
		return 0;
	}
	//
	int Dijkstra::SetFile_char(char** array, int arraySize, char* fileName)
	{
		// declaration of file pointer
		FILE* fp = NULL;
		// opening of file
		fopen_s(&fp, fileName, "w+");
		// checking of error
		if (!fp)
			return 1;
		// giving content
		for (int i = 0; i < arraySize; i++)
			fprintf(fp, "%s\n", array[i]);
		// closing of file
		fclose(fp);
		//
		return 0;
	}
    //
	int Dijkstra::minDistance(vector<int> dist, vector<bool> sptSet, int p_vertexSize)
	{
		// Initialize min value
		int min = INT_MAX, min_index;

		for (int v = 0; v < p_vertexSize; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		return min_index;
	}
	//
	string Dijkstra::GetDijkstra(vector<string> vertex, int** graph, int p_vertexSize, int p_sampleSize, int p_sourcePoint)
	{
		//
		string status;
		// Driver Code
		SetDijkstra(graph, p_sourcePoint, p_vertexSize);
		//
		string integerFormat = "00";
		//
		for (int index = 0; index < p_vertexSize; index++)
		{
			// CORREGIR VALORES
			if (dist[index] >= INT_MAX)
			{
				dist[index] = 0;
			}
			//
			string separator            = (index < (p_vertexSize - 1)) ? "<br/>" : "";
			//
			string vertexIndex          = vertex[index].replace(vertex[index].find(","),1,";");
			//
			std::ostringstream oss_index;
			oss_index << std::setw(2) << std::setfill('0') << index;
			std::string formattedIndex = oss_index.str();
			//
			std::ostringstream oss_dist;
			oss_dist << std::setw(2) << std::setfill('0') << dist[index];
			std::string formattedDist  = oss_dist.str();
			//
			stringstream  ss;
			ss     << formattedIndex                                                /*.ToString(integerFormat)*/
				   <<"&lt;"
				   << vertexIndex                                                   /*.Replace(",", ";").Replace("|", "")*/
				   << "&gt;-"
				   << formattedDist                                                 /*.ToString(integerFormat)*/
				   << "-"
				   << path[index]                                                   /*.Replace(",", ";")*/
				   << separator;
			//
			string statusItem = ss.str();
			status += statusItem;
		}
		//
		return status;
	}
	// Function that implements Dijkstra's single source
	// shortest path algorithm for a graph represented using
	// adjacency matrix representation
	void Dijkstra::SetDijkstra(int** graph, int src, int V)
	{
		//
		//dist = new int[V];
		//
		//path = new vector<string>;
        //
		// distance from src to i
		//
		//bool sptSet[V];    // sptSet[i] will be true if vertex i is
		vector<bool> sptSet; // sptSet[i] will be true if vertex i is

		// included in shortest
		// path tree or shortest distance from src to i is
		// finalized

		// Initialize path
		// Initialize all distances as INFINITE and stpSet[] as false
		for (int i = 0; i < V; i++)
		{
			dist.push_back(INT_MAX);
			sptSet.push_back(false);
			path.push_back(string(""));
		}

		/*
		for (int i = 0; i < V; i++)  {
			dist[i]   = INT_MAX;
			sptSet[i] = false;
		}*/

		// Distance of source vertex from itself is always 0
		dist[src] = 0;

		// Find shortest path for all vertices
		for (int count = 0; count < V - 1; count++) {
			// Pick the minimum distance vertex from the set of
			// vertices not yet processed. u is always equal to
			// src in the first iteration.
			int u = minDistance(dist, sptSet, V);

			// Mark the picked vertex as processed
			sptSet[u] = true;

			// Update dist value of the adjacent vertices of the
			// picked vertex.
			for (int v = 0; v < V; v++)

				// Update dist[v] only if is not in sptSet,
				// there is an edge from u to v, and total
				// weight of path from src to  v through u is
				// smaller than current value of dist[v]
				if (!sptSet[v] && graph[u][v]
					&& dist[u] != INT_MAX
					&& dist[u] + graph[u][v] < dist[v])
				{
					dist[v] = dist[u] + graph[u][v];

					//path[v] = path[u] + string.Format("[{0},{1}]≡", u,v);
					stringstream ss;
					string       pathSeparator  = "≡";
                    //
					ss << "[" << u << ";" << v << "]" << pathSeparator;
					path[v] = path[u] + ss.str().c_str();
				}
		}
	}
	//
	vector<int> Dijkstra::FisherYates(int count)
	{
	   //
	   //int* deck    = new int[count];
	   vector<int> deck;

	   for (short i = 0; i < count; i++)
	   {
			//deck[i] = i;
			deck.push_back(i);
	   }


	   //
	   for (short i = 0; i <= count - 2; i++)
	   {
		   this->mt_1  = std::mt19937(rd_1());
		   std::uniform_int_distribution<int> dist(0, count - i);

		   //
		   int j = dist(mt_1); /*rand.Next(count - i)*/;
		   //
		   if (j > 0)
		   {
			   int curVal  = deck[i];
			   deck[i]     = deck[i + j];
			   deck[i + j] = curVal;
		   }
	   }
	   //
	   for (short i = count - 1; i >= 1; i--)
	   {
		   //std::mt19937 mt_2(rd_2());

		   // Create a random number generator engine
		   this->mt_1  = std::mt19937(rd_1());
		   std::uniform_int_distribution<int> dist(0, i + 1);
		   //
		   int j  = dist(mt_1);//*rand.Next(i + 1)/0;
		   //
		   if (j != i)
		   {
			   int curVal = deck[i];
			   deck[i]    = deck[j];
			   deck[j]    = curVal;
		   }
	   }
	   //
	   return deck;
	}
	//
	float Dijkstra::Pitagorean(float coord_x, float coord_y)
	{
		//
		double pitagorean = 0;
		double power      = 2;

		pitagorean        = sqrt(
												std::pow(coord_x, power)
												+
												std::pow(coord_y, power)
								);

		//
		return pitagorean;
	}
	//
	vector<string> Dijkstra::StringSplit(const char* p_inputString, std::string p_delimiter, bool adjust)
	{
		//
		std::string s(p_inputString);
		//
		std::vector<std::string> outputArr;
		size_t pos = 0;
		std::string token;
		//
		while ((pos = s.find(p_delimiter)) != std::string::npos) {
			token = s.substr(0, pos);
			s.erase(0, pos + p_delimiter.length());
			outputArr.push_back(token);
		}
		outputArr.push_back(s);
		// Printing Array to see the results
		int outputArrSize = outputArr.size();
		for ( int i=0;i<outputArrSize;i++){
				//
				if ( adjust == true) {
					std::string coordinate = outputArr[i];
					coordinate.replace(coordinate.find("["),1,"");
					coordinate.replace(coordinate.find("]"),1,"");
					outputArr[i] = coordinate;
				}
		}
		//
		return outputArr;
	}
	//
	float Dijkstra::GetHipotemuza(const char*vertexString, int index_x, int index_y)
	{

		//--------------------------------------------------------------
		//   string split
		//--------------------------------------------------------------
		std::string   p_delimiter = "|";
		vector<string> outputArr   = StringSplit(vertexString,p_delimiter,true);

		std::string  coord_source   = outputArr[index_y];
		std::string  coord_dest     = outputArr[index_x];

		std::vector<string> coord_source_array = StringSplit(coord_source.c_str(),",",false);
		std::vector<string> coord_dest_array   = StringSplit(coord_dest.c_str(),",",false);

		//
		float coord_source_x    = std::stof(coord_source_array[0]);
		float coord_source_y    = std::stof(coord_source_array[1]);
		float coord_dest_x      = std::stof(coord_dest_array[0]);
		float coord_dest_y      = std::stof(coord_dest_array[1]);
		//
		float coord_x = std::fabs(coord_dest_x - coord_source_x);
		float coord_y = std::fabs(coord_dest_y - coord_source_y);
		//
		float hipotemuza = Pitagorean(coord_x, coord_y);

		//
		// LogModel.Log(string.Format("DIJSTRA_DEMO. GENERATE_RANDOM_MATRIX : ({0},{1}) ({2}, {3}) = {4} ", coord_source[0], coord_source[1], coord_dest[0], coord_dest[1], hipotemuza));

		//
		return hipotemuza;
	}
	//
	string Dijkstra::GenerateRandomMatrix(const char* vertexString, int** graph ,int p_vertexSize)
	{
		//--------------------------------------------------------------
		// LA PARTE DIAGONAL DE LA MATRIZ SIEMPRE SERA 0
		// lA DISTANCIA ENTRE UN PUNTO Y EL MISMO SIEMPRE ES CERO
		//--------------------------------------------------------------
		for (int index = 0; index < p_vertexSize; index++)
		{
			graph[index][index] = 0;
		}

		//--------------------------------------------------------------
		// LLENAR EL RESTO DE LA MATRIZ DE FORMA ALEATORIA
		//--------------------------------------------------------------
		//
		for (int index_x = 0; index_x < p_vertexSize; index_x++)
		{
			//
			for (int index_y = (index_x + 1); index_y < p_vertexSize; index_y++)
			{
				// Create a random number generator engine
				this->mt_1  = std::mt19937(rd_1());
				std::uniform_int_distribution<int> dist(0, 1);

				int randomValue      = dist(mt_1);
				int hipotemuza       = 0;
				//--------------------------------------------------------------
				// EN VALORES POSITIVOS LLENAR LA MATRIZ CON DISTANCIAS
				//--------------------------------------------------------------

				if (randomValue == 1)
				{
					//
					hipotemuza = GetHipotemuza(vertexString, index_x, index_y);
				}

				//
				graph[index_x][index_y] = hipotemuza;
				graph[index_y][index_x] = hipotemuza;
			}
		}

		//----------------------------------------------------
		// GARANTIZAR CONECTIVIDAD DE AL MENOS UN PUNTO
		//----------------------------------------------------
		for (int index_x = 0; index_x < p_vertexSize; index_x++)
		{
			//
			int zeroCount = 0;

			//
			for (int index_y = 0; index_y < p_vertexSize; index_y++)
			{
				// DESCARTA DIAGONAL Y VERIFICAR EXISTENCIA DE VALOR "CERO"
				if ((index_x != index_y) && (graph[index_x][index_y] == 0))
				{
					//
					zeroCount++;

					// GARANTIZAR CONECTIVIDAD DE AL MENOS UN PUNTO
					if (zeroCount == (p_vertexSize - 1))
					{
						//
						int hipotemuza          = static_cast<int>(std::round(GetHipotemuza(vertexString, index_x, index_y)));
						graph[index_x][index_y] = hipotemuza;
						graph[index_y][index_x] = hipotemuza;
					}
				}
			}
		}
		//--------------------------------------------------------------------
		// REPRESENTAR MATRIZ EN CADENA
		//--------------------------------------------------------------------
		//
		string statusMessage = "";
		//
		for (int index_x = 0; index_x < p_vertexSize; index_x++) {

			//
			string separator_1 = (index_x < p_vertexSize - 1) ? "|" : "";
			//
			string stringArray       = "";
			//
			for (int index_y = 0; index_y < p_vertexSize; index_y++)
			{
				//
				stringstream  ss_y;
				//
				string separator_2   = (index_y < p_vertexSize - 1)? "," : "";
				ss_y << graph[index_x][index_y]<< separator_2;
				string vertexItem_y  = ss_y.str();
				//
				stringArray          += vertexItem_y;
			}
			//
			stringstream  ss_x;
			ss_x          << "{" << stringArray << "}";
			//
			string stringArrayValues = ss_x.str();
			//
			statusMessage += stringArrayValues + separator_1;
		}

		//
		return statusMessage;
	}
	//
	string Dijkstra::GetRandomPoints(int p_vertexSize, int p_sourcePoint)
	{
		//
		int  p_sampleSize      = 23;
		vector<int> vertex_X   = FisherYates(p_sampleSize);
		vector<int> vertex_Y   = FisherYates(p_sampleSize);

		// c++ diagnostics
		//SetFile_int(vertex_X, sampleSize, (char*)"fisherYates_x.txt");
		//SetFile_int(vertex_Y, sampleSize, (char*)"fisherYates_y.txt");

		//
		string _vertexArrayString = "";
		//
		for (int index = 0; index < p_vertexSize; index++) {
			//
			stringstream  ss;
			//
			string separator   = (index < p_vertexSize - 1)? "|" : "";
			ss << "[" << vertex_X[index] << "," << vertex_Y[index] << "]" << separator;
			string vertexItem  = ss.str();
			//
			_vertexArrayString += vertexItem;
		}

		//--------------------------------------------------------------
		// CREAR MATRIZ
		//--------------------------------------------------------------
		int** graph = new int*[p_vertexSize];
		for (int i = 0; i < p_vertexSize; i++) {
		   graph[i] = new int[p_vertexSize];
		}
		//
		string _vertexMatrix = GenerateRandomMatrix(_vertexArrayString.c_str(), graph, p_vertexSize);
		//
		string vertexList    = GetDijkstra(StringSplit(_vertexArrayString.c_str(),"|",false), graph, p_vertexSize, p_sampleSize, p_sourcePoint);
		//
		string        separator_1("~");
		stringstream  ss_statusMessage;
		ss_statusMessage << _vertexArrayString << separator_1 << _vertexMatrix << separator_1 << vertexList;
		string s_statusMessage      = ss_statusMessage.str();
		//
		return s_statusMessage;
	}


	///////////////////////////////////////////////////////////////////////////
	// ENTRY POINTS
	///////////////////////////////////////////////////////////////////////////

	// DUJKSTRA
	// RUN DIJKSTRA
	DLL_EXPORT const char* Dijkstra_GenerateRandomVertex_CPP(int p_vertexSize, int p_sourcePoint)
	{
		//
		std::unique_ptr<Dijkstra> uniquePtr = std::make_unique<Dijkstra>();
		return uniquePtr->GetRandomPoints(p_vertexSize, p_sourcePoint).c_str();
	};
};
