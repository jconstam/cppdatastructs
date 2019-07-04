#ifndef SORT_HPP__
#define SORT_HPP__

#include <chrono>

#include "data.hpp"

class sortBase
{
	public:
		sortBase( dataStor data )
		{
			m_data = data.replicate( );
		}

		bool isSorted( )
		{
			return m_data.isSorted( );
		}

		int getSwapCount( )
		{
			return m_data.getSwapCount( );
		}
		
		int getAccessCount( )
		{
			return m_data.getAccessCount( );
		}

		int getInsertCount( )
		{
			return m_data.getInsertCount( );
		}

		int getRemoveCount( )
		{
			return m_data.getRemoveCount( );
		}

		int getOpsCount( )
		{
			return m_data.getOpsCount( );
		}

		double getSortTime( )
		{
			return sortTime.count( );
		}

		void outputGif( )
		{
			m_data.outputGif( );
		}

		void initGif( std::string fileName, int speedUpFactor )
		{
			m_data.initGif( fileName, speedUpFactor );
		}

		void doSortWithGif( std::string fileName, int speedUpFactor )
		{
			initGif( fileName, speedUpFactor );
			doSort( );
			outputGif( );
		}

		void doSort( )
		{
			auto start = std::chrono::high_resolution_clock::now( );

			actualSort( );

			auto end = std::chrono::high_resolution_clock::now( );

			sortTime = std::chrono::duration_cast< std::chrono::nanoseconds >( end - start );
		}

	protected:
		dataStor m_data;
		std::chrono::duration<double, std::ratio<1>> sortTime;

		virtual void actualSort( ) = 0;
};

#endif
