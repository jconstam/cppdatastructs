#include "data/queue.hpp"

queue::queue( )
{
	m_list = new linkList( );
}

queue::~queue( )
{
	delete m_list;
}

void queue::push( const int value )
{
	m_list->prepend( value );
}

int queue::pop( )
{
	int result;
	try
	{
		result = m_list->remove( 0 );
		return result;
	}
	catch( linkListOutOfRangeException& ex )
	{
		throw queueEmptyException( );
	}
}