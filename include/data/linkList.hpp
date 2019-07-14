#ifndef LINK_LIST_HPP__
#define LINK_LIST_HPP__

#include <exception>

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
		linkListNode( const int value, linkListNode* next = nullptr );

		void setNext( linkListNode* next );
		void setValue( const int value );

		linkListNode* getNext( );
		int getValue( );
	private:
		int m_value;
		linkListNode* m_next;
};

class linkList
{
	public:
		linkList( );
		~linkList( );

		void append( const int value );
		void prepend( const int value );
		void insert( const int value, const int index );
		int remove( const int index );
		int get( const int index );

		int getSize( );

	private:
		linkListNode* m_head;
		int m_size;

		void deleteNode( linkListNode* curr );
		linkListNode* getNode( const int index );
};

#endif