#include "data/linkList.hpp"

linkListNode::linkListNode( const int value, linkListNode* next )
{
	m_value = value;
	setNext( next );
}

void linkListNode::setNext( linkListNode* next )
{
	m_next = next;
}
void linkListNode::setValue( const int value )
{
	m_value = value;
}

linkListNode* linkListNode::getNext( )
{
	return m_next;
}
int linkListNode::getValue( )
{
	return m_value;
}

linkList::linkList( )
{
	m_head = nullptr;
	m_size = 0;
}
linkList::~linkList( )
{
	deleteNode( m_head );
}

void linkList::append( const int value )
{
	linkListNode* newNode = new linkListNode( value );
	if( m_head == nullptr )
	{
		m_head = newNode;
	}
	else
	{
		linkListNode* curr = m_head;
		while( curr->getNext( ) )
		{
			curr = curr->getNext( );
		}
		curr->setNext( newNode );
	}

	m_size++;
}

void linkList::prepend( const int value )
{
	linkListNode* newNode = new linkListNode( value );
	newNode->setNext( m_head );
	m_head = newNode;

	m_size++;
}

void linkList::insert( const int value, const int index )
{
	linkListNode* newNode = new linkListNode( value );
	linkListNode* currNode = m_head;
	linkListNode* prevNode = nullptr;
	if( !currNode )
	{
		if( index == 0 )
		{
			m_head = newNode;
			m_size++;
			return;
		}
		else
		{
			delete newNode;
			throw linkListOutOfRangeException( );
		}
	}

	for( int i = 0; i < index; i++ )
	{
		prevNode = currNode;
		currNode = currNode->getNext( );
		if( !currNode && i < index - 1 )
		{
			delete newNode;
			throw linkListOutOfRangeException( );
		}
	}

	if( currNode )
	{
		newNode->setNext( currNode );
	}

	if( prevNode )
	{
		prevNode->setNext( newNode );
	}
	else
	{
		m_head = newNode;
	}

	m_size++;
}

int linkList::remove( const int index )
{
	if( index == 0 )
	{
		if( m_head )
		{
			linkListNode* lastHead = m_head;
			m_head = m_head->getNext( );

			int value = lastHead->getValue( );
			delete lastHead;

			m_size--;

			return value;
		}
		else
		{
			throw linkListOutOfRangeException( );
		}
	}
	else
	{
		linkListNode* prev = getNode( index - 1 );
		linkListNode* curr = prev->getNext( );
		if( !curr )
		{
			throw linkListOutOfRangeException( );
		}
		int value = curr->getValue( );
		linkListNode* next = curr->getNext( );

		if( next )
		{
			prev->setNext( next );
		}
		else
		{
			prev->setNext( nullptr );
		}

		delete curr;

		m_size--;

		return value;
	}
}

int linkList::get( const int index )
{
	return getNode( index )->getValue( );
}

int linkList::getSize( )
{
	return m_size;
}

void linkList::deleteNode( linkListNode* curr )
{
	if( curr == nullptr )
	{
		return;
	}
	else if( curr->getNext( ) )
	{
		deleteNode( curr->getNext( ) );
	}

	delete curr;
}

linkListNode* linkList::getNode( const int index )
{
	linkListNode* curr = m_head;
	for( int i = 0; i < index; i++ )
	{
		if( curr == nullptr )
		{
			throw linkListOutOfRangeException( );
		}
		curr = curr->getNext( );
	}

	if( curr == nullptr )
	{
		throw linkListOutOfRangeException( );
	}

	return curr;
}
