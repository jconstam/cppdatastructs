#include "sort/sort_selection.hpp"

sort_selection::sort_selection( dataStor data ) : sortBase( data )
{

}

sort_selection::~sort_selection( )
{
	
}

void sort_selection::actualSort( )
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

std::string sort_selection::getName( )
{
	return "Selection";
}