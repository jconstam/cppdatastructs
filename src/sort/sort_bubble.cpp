#include "sort/sort_bubble.hpp"

sort_bubble::sort_bubble( dataStor data ) : sortBase( data )
{

}

sort_bubble::~sort_bubble( )
{
	
}

void sort_bubble::actualSort( )
{
	size_t counter = 1;
	while( 1 )
	{
		int swapCount = 0;

		for( size_t i = 0; i < m_data.size( ) - counter; i++ )
		{
			if( m_data[ i ] > m_data[ i + 1U ] )
			{
				m_data.swap( i, i + 1U );
				swapCount++;
			}
		}
		counter++;

		if( swapCount == 0 )
		{
			break;
		}
	}
}

std::string sort_bubble::getName( )
{
	return "Bubble";
}