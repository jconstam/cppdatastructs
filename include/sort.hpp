#ifndef SORT_HPP__
#define SORT_HPP__

#include "data.hpp"

template <typename T>
class sortBase
{
	public:
		sortBase( dataStor<T> data )
		{
			m_data = data;
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

		virtual void doSort( ) = 0;

	protected:
		dataStor<T> m_data;
};

#endif
