#ifndef SORT_HPP__
#define SORT_HPP__

#include <chrono>
#include <string>

#include "sort/dataStor.hpp"

class sortBase
{
	public:
		sortBase( dataStor data );
		virtual ~sortBase( );

		void changeData( dataStor data );

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

		virtual std::string getName( ) = 0;

	protected:
		dataStor m_data;
		std::chrono::duration<double, std::ratio<1>> sortTime;

		virtual void actualSort( ) = 0;
};

#endif
