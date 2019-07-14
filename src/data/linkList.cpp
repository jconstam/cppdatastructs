#include "data/linkList.hpp"

linkListNode::linkListNode( int value, linkListNode* next )
{
	m_value = value;
	setNext( next );
}

void linkListNode::setNext( linkListNode* next )
{
	m_next = next;
}
void linkListNode::setValue( int value )
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
	head = nullptr;
}
linkList::~linkList( )
{
	deleteNode( head );
}

void linkList::add( int value )
{
	linkListNode* newNode = new linkListNode( value );
	if( head == nullptr )
	{
		head = newNode;
	}
	else
	{
		linkListNode* curr = head;
		while( curr->getNext( ) )
		{
			curr = curr->getNext( );
		}
		curr->setNext( newNode );
	}
}

int linkList::remove( const int index )
{
	if( index == 0 )
	{
		if( head )
		{
			linkListNode* lastHead = head;
			head = head->getNext( );

			int value = lastHead->getValue( );
			delete lastHead;

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

		return value;
	}
}

int linkList::get( const int index )
{
	return getNode( index )->getValue( );
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
	linkListNode* curr = head;
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