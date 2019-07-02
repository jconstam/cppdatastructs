#ifndef SORT_RADIX_HPP__
#define SORT_RADIX_HPP__

#include <cmath>

#include "sort.hpp"

class sort_merge : public sortBase
{
	public:
		sort_merge( dataStor data ) : sortBase( data )
		{

		}

		void doSort( )
		{
			merge( 0, m_data.size( ) - 1 );
		}

	private:
		void merge( int startIndex, int endIndex )
		{
			if( endIndex - startIndex < 1 )
			{
				return;
			}
			else if( endIndex - startIndex == 1 )
			{
				if( m_data[ endIndex ] < m_data[ startIndex ] )
				{
					m_data.swap( startIndex, endIndex );
				}
				return;
			}

			int middle = ( endIndex + startIndex ) / 2;

			merge( startIndex, middle - 1 );
			merge( middle, endIndex );

			int lowIndex = startIndex;
			int highIndex = middle;
			while( ( highIndex <= endIndex ) && ( lowIndex <= highIndex ) )
			{
				if( m_data[ highIndex ] < m_data[ lowIndex ] )
				{
					int value = m_data.remove( highIndex );
					m_data.insert( value, lowIndex );
					highIndex++;
				}
				lowIndex++;
			}
		}
};

#endif
