#include "data/heap.hpp"

heapNode::heapNode( int value )
{
	m_value = value;
	m_right = nullptr;
	m_left = nullptr;
}
heapNode::~heapNode( )
{
	delete m_right;
	delete m_left;
}

void heapNode::setRight( int value )
{
	m_right = new heapNode( value );
}
void heapNode::setLeft( int value )
{
	m_left = new heapNode( value );
}

int heapNode::getValue( )
{
	return m_value;
}
heapNode* heapNode::getRight( )
{
	return m_right;
}
heapNode* heapNode::getLeft( )
{
	return m_left;
}

heap::heap( )
{
	root = nullptr;
}
heap::~heap( )
{
	delete root;
}

void heap::printAll( )
{
	printNode( root, 0 );
}
void heap::printNode( heapNode* currNode, int depth )
{
	for( int i = 0; i < depth; i++ )
	{
		cout << "\t";
	}
	if( !currNode )
	{
		cout << "empty" << endl;
		return;
	}

	cout << "V: " << currNode->getValue( ) << endl;
	for( int i = 0; i < depth; i++ )
	{
		cout << "\t";
	}
	cout << "LEFT: " << endl;
	printNode( currNode->getLeft( ), depth + 1 );
	for( int i = 0; i < depth; i++ )
	{
		cout << "\t";
	}
	cout << "RIGHT: " << endl;
	printNode( currNode->getRight( ), depth + 1 );
}

void heap::add( int value )
{
	if( !addToNode( root, value ) )
	{
		root = new heapNode( value );
	}
}
bool heap::addToNode( heapNode* currNode, int value )
{
	if( !currNode )
	{
		return false;
	}
	else
	{
		int nodeValue = currNode->getValue( );
		if( value > nodeValue )
		{
			if( !addToNode( currNode->getLeft( ), value ) )
			{
				currNode->setLeft( value );
			}
		}
		else
		{
			if( !addToNode( currNode->getRight( ), value ) )
			{
				currNode->setRight( value );
			}
		}

		return true;
	}
}