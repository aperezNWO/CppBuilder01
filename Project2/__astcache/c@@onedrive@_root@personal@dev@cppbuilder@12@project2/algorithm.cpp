///////////////////////////////////////////////////////////////////////////
// CLASS DIJKSTRA - METHOD IMPLEMENTATIONS
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// ALGORITHM.WINFORM.DLL
///////////////////////////////////////////////////////////////////////////

#include "Dijkstra.h"
#include "Algorithm.h"
#include "SortBenchMark.h"
#include <memory>

	///////////////////////////////////////////////////////////////////////////
	// ENTRY POINTS
	///////////////////////////////////////////////////////////////////////////
	extern "C"
	{
		// DUJKSTRA
		DLL_EXPORT const char* Dijkstra_GenerateRandomVertex_CPP(int p_vertexSize, int p_sourcePoint)
		{
			//
			std::unique_ptr<Dijkstra> uniquePtr = std::make_unique<Dijkstra>();
			return uniquePtr->GetRandomPoints(p_vertexSize, p_sourcePoint).c_str();
		};

		//"http://localhost:83/demos/_GetSort?p_sortAlgoritm=1&p_unsortedList=13|3|9|10|19|16|0|2|18|20|24|23|7|5|12|1|21|4|22|15|6|8|14|11|17" succeeded in 143 ms.
		// SORT BENCHMARK
		DLL_EXPORT const char* SortBenchMark_GetSort(int p_sortAlgoritm, char* p_unsortedList)
		{
			//
			int ARRAY_SIZE      = 25;
			//
			std::unique_ptr<SortBenchMark> uniquePtr = std::make_unique<SortBenchMark>(
					  p_unsortedList
					, ARRAY_SIZE
			);
			return uniquePtr->GetSort(p_sortAlgoritm, p_unsortedList).c_str();
		};

	}
