#include <cmath>

#include "sort_merge.hpp"

sort_merge::sort_merge( dataStor data ) : sortBase( data )
{

}

sort_merge::~sort_merge( )
{
	
}

void sort_merge::actualSort( )
{
	merge( 0, m_data.size( ) - 1 );
}

void sort_merge::merge( int startIndex, int endIndex )
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

std::string sort_merge::getName( )
{
	return "Merge";
}