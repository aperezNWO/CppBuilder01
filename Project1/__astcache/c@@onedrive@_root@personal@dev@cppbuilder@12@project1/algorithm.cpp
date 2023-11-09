///////////////////////////////////////////////////////////////////////////
// CLASS DIJKSTRA - METHOD IMPLEMENTATIONS
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// ALGORITHM.WINFORM.EXE
///////////////////////////////////////////////////////////////////////////

#include "Dijkstra.h"
#include "Algorithm.h"
#include <memory>

extern "C"
{
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

}

