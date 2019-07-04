#ifndef SORT_QUICK_HPP__
#define SORT_QUICK_HPP__

#include "sort.hpp"

class sort_quick : public sortBase
{
	public:
		sort_quick( dataStor data );

		void actualSort( );

	private:
		void quick( int startIndex, int endIndex, int depth );
		int pickPivotIndex( int startIndex, int endIndex );
};

#endif
