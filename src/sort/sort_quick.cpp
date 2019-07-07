#include "sort/sort_quick.hpp"

sort_quick::sort_quick( dataStor data ) : sortBase( data )
{

}

sort_quick::~sort_quick( )
{
	
}

void sort_quick::actualSort( )
{
	srand( time( 0 ) );
	quick( 0, m_data.size( ) - 1, 0 );
}

void sort_quick::quick( int startIndex, int endIndex, int depth )
{
	if( endIndex - startIndex < 1 )
	{
		return;
	}

	int pivotIndex = pickPivotIndex( startIndex, endIndex );
	int pivot = m_data[ pivotIndex ];

	int lessCount = startIndex;
	for( int i = startIndex; i < endIndex; i++ )
	{
		int value = m_data.remove( i );
		if( value <= pivot )
		{
			m_data.insert( value, startIndex );
			lessCount++;
		}
		else
		{
			m_data.insert( value, lessCount );
		}
	}

	m_data.remove( endIndex );
	m_data.insert( pivot, lessCount );

	quick( startIndex, lessCount - 1, depth + 1 );
	quick( lessCount + 1, endIndex, depth + 1 );
}

int sort_quick::pickPivotIndex( int startIndex, int endIndex )
{
	int midIndex = ( startIndex + endIndex ) / 2;

	if( m_data[ midIndex ] < m_data[ startIndex ] )
	{
		m_data.swap( startIndex, midIndex );
	}
	if( m_data[ endIndex ] < m_data[ startIndex ] )
	{
		m_data.swap( startIndex, endIndex );
	}
	if( m_data[ midIndex ] < m_data[ endIndex ] )
	{
		m_data.swap( midIndex, endIndex );
	}

	return endIndex;
}

std::string sort_quick::getName( )
{
	return "Quick";
}