///////////////////////////////////////////////////////////////////////////
// REGEX MANAGER
///////////////////////////////////////////////////////////////////////////

#ifndef RegExManager_H // include guard
#define RegExManager_H
#endif


#include "algorithm.h"

class RegExManager :
	public Algorithm
{
	public :
		 RegExManager();
		 ~RegExManager();
         string RegExEval(char* p_tagSearch, char* p_textSearch);
};
