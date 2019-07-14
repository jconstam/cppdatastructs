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
	int result;
	try
	{
		result = m_list->remove( 0 );
		return result;
	}
	catch( linkListOutOfRangeException& ex )
	{
		throw stackEmptyException( );
	}
}