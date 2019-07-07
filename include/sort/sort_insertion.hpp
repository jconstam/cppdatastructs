#ifndef SORT_INSERTION_HPP__
#define SORT_INSERTION_HPP__

#include "sort/sort.hpp"

class sort_insertion : public sortBase
{
	public:
		sort_insertion( dataStor data );
		~sort_insertion( );

		void actualSort( );
		std::string getName( );
};

#endif
