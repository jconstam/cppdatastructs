#include <cstring>

#include "gifenc.h"
#include "data.hpp"
#include "sort_insertion.hpp"
#include "sort_selection.hpp"

int main( int argc, char* argv[ ] )
{
	dataStor<int> test;

	test.generate( 1000, 300 );

	sort_insertion sort_insert( test );
	sort_insert.doSortWithGif( "insert.gif" );
	
	sort_selection sort_select( test );
	sort_select.doSortWithGif( "select.gif" );

	return 0;
}