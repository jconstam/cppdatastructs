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
	int size = m_list->getSize( );
	if( size == 0 )
	{
		throw queueEmptyException( );	
	}
	else
	{
		return m_list->remove( size - 1 );
	}
}

int queue::getSize( )
{
	return m_list->getSize( );
}