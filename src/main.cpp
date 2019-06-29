#include <cstring>

#include "gifenc.h"
#include "data.hpp"
#include "sort_insertion.hpp"

int main( int argc, char* argv[ ] )
{
	dataStor<int> test;

	test.generate( 1000, 1000 );

	sort_insertion sorter( test );
	sorter.doSort( );

	sorter.outputGif( );

	return 0;
}