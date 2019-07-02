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

	test.generate( 10, 10 );
/*
	sort_insertion sort_insert( test );
	sort_insert.doSortWithGif( "images/insert.gif", 5 );
	
	sort_selection sort_select( test );
	sort_select.doSortWithGif( "images/select.gif", 5 );

	sort_merge sort_merge( test );
	sort_merge.doSortWithGif( "images/merge.gif", 5 );

	sort_bubble sort_bubble( test );
	sort_bubble.doSortWithGif( "images/bubble.gif", 1000 );
	*/

	sort_quick sort_quick( test );
	sort_quick.doSortWithGif( "images/quick.gif", 20 );
	return 0;
}