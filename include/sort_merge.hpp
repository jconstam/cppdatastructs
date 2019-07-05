#ifndef SORT_RADIX_HPP__
#define SORT_RADIX_HPP__

#include "sort.hpp"

class sort_merge : public sortBase
{
	public:
		sort_merge( dataStor data );
		~sort_merge( );

		void actualSort( );
		std::string getName( );

	private:
		void merge( int startIndex, int endIndex );
};

#endif
