#include "sort_insertion.hpp"

sort_insertion::sort_insertion( dataStor data ) : sortBase( data )
{

}

void sort_insertion::actualSort( )
{
	for( int i = 1; i < ( int ) m_data.size( ); i++ )
	{
		int j;
		int newValue = m_data.remove( i );
		for( j = 0; j < i; j++ )
		{
			if( newValue < m_data[ j ] )
			{
				m_data.insert( newValue, j );
				break;
			}
		}

		if( i == j )
		{
			m_data.insert( newValue, i );
		}
	}
}