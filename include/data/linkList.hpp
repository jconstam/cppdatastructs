#ifndef LINK_LIST_HPP__
#define LINK_LIST_HPP__

#include <exception>

#include <iostream>
using namespace std;

struct linkListOutOfRangeException : public std::exception
{
	const char * what () const throw () 
	{
		return "Linked List Out of Bounds";
	}
};

class linkListNode
{
	public:
		linkListNode( int value, linkListNode* next = nullptr )
		{
			m_value = value;
			setNext( next );
		}

		void setNext( linkListNode* next )
		{
			m_next = next;
		}
		void setValue( int value )
		{
			m_value = value;
		}

		linkListNode* getNext( )
		{
			return m_next;
		}
		int getValue( )
		{
			return m_value;
		}
	private:
		int m_value;
		linkListNode* m_next;
};

class linkList
{
	public:
		linkList( )
		{
			head = nullptr;
		}
		~linkList( )
		{
			deleteNode( head );
		}

		void add( int value )
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

		int remove( const int index )
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

		int get( const int index )
		{
			return getNode( index )->getValue( );
		}

	private:
		linkListNode* head;

		void deleteNode( linkListNode* curr )
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

		linkListNode* getNode( const int index )
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
};

#endif