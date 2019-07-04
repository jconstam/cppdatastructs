#ifndef SORT_HPP__
#define SORT_HPP__

#include <chrono>

#include "data.hpp"

class sortBase
{
	public:
		sortBase( dataStor data );

		bool isSorted( );
		int getSwapCount( );
		int getAccessCount( );
		int getInsertCount( );
		int getRemoveCount( );
		int getOpsCount( );
		double getSortTime( );

		void outputGif( );
		void initGif( std::string fileName, int speedUpFactor );
		void doSortWithGif( std::string fileName, int speedUpFactor );
		void doSort( );

	protected:
		dataStor m_data;
		std::chrono::duration<double, std::ratio<1>> sortTime;

		virtual void actualSort( ) = 0;
};

#endif
