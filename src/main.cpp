#include <cstring>

#include "gifenc.h"
#include "data.hpp"
#include "sort_insertion.hpp"
#include "sort_selection.hpp"
#include "sort_bubble.hpp"
#include "sort_merge.hpp"
#include "sort_quick.hpp"

int main( int argc, char* argv[ ] )
{
	dataStor test;

	//test.generate( 1000, 500 );
	for( int i = 1000; i >= 0; i-- )
	{
		test.add( i );
	}

	sort_insertion sort_insert( test );
	sort_insert.doSortWithGif( "images/insert.gif", 5 );
	
	sort_selection sort_select( test );
	sort_select.doSortWithGif( "images/select.gif", 5 );

	sort_merge sort_merge( test );
	sort_merge.doSortWithGif( "images/merge.gif", 10 );

	sort_bubble sort_bubble( test );
	sort_bubble.doSortWithGif( "images/bubble.gif", 1000 );

	sort_quick sort_quick( test );
	sort_quick.doSortWithGif( "images/quick.gif", 30 );
	return 0;
}