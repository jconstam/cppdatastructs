#ifndef SORT_BUBBLE_HPP__
#define SORT_BUBBLE_HPP__

#include "sort.hpp"

class sort_bubble : public sortBase
{
	public:
		sort_bubble( dataStor data ) : sortBase( data )
		{

		}

		void doSort( )
		{
			while( 1 )
			{
				int swapCount = 0;

				for( size_t i = 0; i < m_data.size( ) - 1U; i++ )
				{
					if( m_data[ i ] > m_data[ i + 1U ] )
					{
						m_data.swap( i, i + 1U );
						swapCount++;
					}
				}

				if( swapCount == 0 )
				{
					break;
				}
			}
		}
};

#endif