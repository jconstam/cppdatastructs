#ifndef LINK_LIST_HPP__
#define LINK_LIST_HPP__

template<class T>
class linkListNode
{
	public:
		linkListNode( T value, linkListNode* next = nullptr )
		{
			m_value = value;
			setNext( next );
		}

		void setNext( linkListNode* next )
		{
			m_next = next;
		}
		void setValue( T value )
		{
			m_value = value;
		}

		linkListNode* getNext( )
		{
			return m_next;
		}
		T getValue( )
		{
			return m_value;
		}
	private:
		T m_value;
		linkListNode* m_next;
};

template<typename T>
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

		void add( T value )
		{
			linkListNode<T>* newNode = new linkListNode<T>( value );
			if( head == nullptr )
			{
				head = newNode;
			}
			else
			{
				linkListNode<T>* curr = head;
				while( curr->getNext( ) )
				{
					curr = curr->getNext( );
				}
				curr->setNext( newNode );
			}
		}

		T remove( const int index )
		{
			linkListNode<T>* prev = getNode( index - 1 );
			linkListNode<T>* curr = prev->getNext( );
			if( !curr )
			{
				outOfBoundsEx( );
			}
			T value = curr->getValue( );
			linkListNode<T>* next = curr->getNext( );

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

		T& operator[]( const int index )
		{
			return getNode( index )->getValue( );
		}

	private:
		linkListNode<T>* head;

		void outOfBoundsEx( )
		{
			throw "Linked List Out of Bounds";	
		}
		void deleteNode( linkListNode<T>* curr )
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

		linkListNode<T>* getNode( const int index )
		{
			linkListNode<T>* curr = head;
			for( int i = 0; i < index; i++ )
			{
				if( curr == nullptr )
				{
					outOfBoundsEx( );
				}
				curr = curr->getNext( );
			}

			if( curr == nullptr )
			{
				outOfBoundsEx( );
			}

			return curr;
		}
};

#endif