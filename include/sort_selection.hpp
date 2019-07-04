#ifndef SORT_SELECTION_HPP__
#define SORT_SELECTION_HPP__

#include "sort.hpp"

class sort_selection : public sortBase
{
	public:
		sort_selection( dataStor data ) : sortBase( data )
		{

		}

		void actualSort( )
		{
			for( size_t i = 0; i < m_data.size( ); i++ )
			{
				int minValue = m_data[ i ];
				int minValueIndex = ( int ) i;

				for( size_t j = i + 1; j < m_data.size( ); j++ )
				{
					if( m_data[ j ] < minValue )
					{
						minValue = m_data[ j ];
						minValueIndex = ( int ) j;	
					}
				}

				m_data.swap( i, minValueIndex );
			}
		}
};

#endif
