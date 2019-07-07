#ifndef SORT_SELECTION_HPP__
#define SORT_SELECTION_HPP__

#include "sort/sort.hpp"

class sort_selection : public sortBase
{
	public:
		sort_selection( dataStor data );
		~sort_selection( );

		void actualSort( );
		std::string getName( );
};

#endif
