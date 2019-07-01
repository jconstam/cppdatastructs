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

		void initGif( std::string fileName )
		{
			m_data.initGif( fileName );
		}

		void doSortWithGif( std::string fileName )
		{
			initGif( fileName );
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
