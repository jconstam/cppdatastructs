#include <cstring>

#include "gifenc.h"
#include "data.hpp"
#include "sort_insertion.hpp"
#include "sort_selection.hpp"
#include "sort_bubble.hpp"

int main( int argc, char* argv[ ] )
{
	dataStor<int> test;

	test.generate( 500, 300 );
	
	sort_selection sort_select( test );
	sort_select.doSortWithGif( "select.gif" );

	//sort_insertion sort_insert( test );
	//sort_insert.doSortWithGif( "insert.gif" );

	//sort_bubble sort_bubble( test );
	//sort_bubble.doSortWithGif( "bubble.gif" );

	return 0;
}