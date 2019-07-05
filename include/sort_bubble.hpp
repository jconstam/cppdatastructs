#ifndef SORT_BUBBLE_HPP__
#define SORT_BUBBLE_HPP__

#include "sort.hpp"

class sort_bubble : public sortBase
{
	public:
		sort_bubble( dataStor data );
		~sort_bubble( );
		
		void actualSort( );
		std::string getName( );
};

#endif
