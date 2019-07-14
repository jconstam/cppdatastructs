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
		linkListNode( int value, linkListNode* next = nullptr );

		void setNext( linkListNode* next );
		void setValue( int value );

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

		void add( int value );
		int remove( const int index );
		int get( const int index );

	private:
		linkListNode* head;

		void deleteNode( linkListNode* curr );
		linkListNode* getNode( const int index );
};

#endif