#ifndef SORT_QUICK_HPP__
#define SORT_QUICK_HPP__

#include "sort.hpp"

class sort_quick : public sortBase
{
	public:
		sort_quick( dataStor data );
		~sort_quick( );

		void actualSort( );
		std::string getName( );

	private:
		void quick( int startIndex, int endIndex, int depth );
		int pickPivotIndex( int startIndex, int endIndex );
};

#endif
