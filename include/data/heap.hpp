#ifndef HEAP_HPP__
#define HEAP_HPP__

#include <iostream>
using namespace std;

class heapNode
{
	public:
		heapNode( int value );
		~heapNode( );

		void setRight( int value );
		void setLeft( int value );

		int getValue( );
		heapNode* getRight( );
		heapNode* getLeft( );

	private:
		int m_value;
		heapNode* m_right;
		heapNode* m_left;
};

class heap
{
	public:
		heap( );
		~heap( );

		void add( int value );

		void printAll( );

	private:
		heapNode* root;

		bool addToNode( heapNode* currNode, int value );
		void printNode( heapNode* currNode, int depth );
};

#endif
