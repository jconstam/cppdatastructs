#ifndef SORT_BUBBLE_HPP__
#define SORT_BUBBLE_HPP__

#include "sort.hpp"

template <typename T>
class sort_bubble : public sortBase<T>
{
	public:
		sort_bubble( dataStor<T> data ) : sortBase<T>( data )
		{

		}

		void doSort( )
		{
			while( 1 )
			{
				int swapCount = 0;

				for( size_t i = 0; i < this->m_data.size( ) - 1U; i++ )
				{
					if( this->m_data[ i ] > this->m_data[ i + 1U ] )
					{
						this->m_data.swap( i, i + 1U );
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
