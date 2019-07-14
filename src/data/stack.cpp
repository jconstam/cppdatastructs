#include "data/stack.hpp"

stack::stack( )
{
	m_list = new linkList( );
}

stack::~stack( )
{
	delete m_list;
}

void stack::push( const int value )
{
	m_list->prepend( value );
}

int stack::pop( )
{
	if( m_list->getSize( ) == 0 )
	{
		throw stackEmptyException( );	
	}
	else
	{
		return m_list->remove( 0 );
	}
}

int stack::getSize( )
{
	return m_list->getSize( );
}