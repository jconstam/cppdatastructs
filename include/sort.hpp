#ifndef SORT_HPP__
#define SORT_HPP__

#include <iostream>

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

		virtual void doSort( )
		{
			return;
		}

	protected:
		dataStor m_data;
};

#endif
