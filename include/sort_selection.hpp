#ifndef SORT_SELECTION_HPP__
#define SORT_SELECTION_HPP__

#include "sort.hpp"

template <typename T>
class sort_selection : public sortBase<T>
{
	public:
		sort_selection( dataStor<T> data ) : sortBase<T>( data )
		{

		}

		void doSort( )
		{
			for( size_t i = 0; i < this->m_data.size( ); i++ )
			{
				T minValue = this->m_data[ i ];
				int minValueIndex = ( int ) i;

				for( size_t j = i + 1; j < this->m_data.size( ); j++ )
				{
					if( this->m_data[ j ] < minValue )
					{
						minValue = this->m_data[ j ];
						minValueIndex = ( int ) j;	
					}
				}

				this->m_data.swap( i, minValueIndex );
			}
		}
};

#endif
