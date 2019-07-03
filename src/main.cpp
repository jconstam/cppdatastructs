#include <string>
#include <iostream>
#include <cstdlib>

#include "gifenc.h"
#include "data.hpp"
#include "sort_insertion.hpp"
#include "sort_selection.hpp"
#include "sort_bubble.hpp"
#include "sort_merge.hpp"
#include "sort_quick.hpp"

using namespace std;

static void generateReadmeImages( )
{
	const int count = 1000;
	const int maxValue = 200;
	const string folder = "images/readme/";

	cout << "Generating ReadMe Images" << endl;

	system( ( "mkdir -p " + folder ).c_str( ) );

	cout << "\tGenerating " << count << " values that are between 0 and " << maxValue << endl;
	dataStor test;
	test.generate( 500, 200 );

	cout << "\tInsertion Sort..." << endl;
	sort_insertion sort_insert( test );
	sort_insert.doSortWithGif( folder + "insert.gif", 5 );
	
	cout << "\tSelection Sort..." << endl;
	sort_selection sort_select( test );
	sort_select.doSortWithGif( folder + "select.gif", 5 );

	cout << "\tMerge Sort..." << endl;
	sort_merge sort_merge( test );
	sort_merge.doSortWithGif( folder + "merge.gif", 10 );

	cout << "\tBubble Sort..." << endl;
	sort_bubble sort_bubble( test );
	sort_bubble.doSortWithGif( folder + "bubble.gif", 1000 );

	cout << "\tQuick Sort..." << endl;
	sort_quick sort_quick( test );
	sort_quick.doSortWithGif( folder + "quick.gif", 30 );

	cout << "\tDone" << endl;
}

int main( int argc, char* argv[ ] )
{
	generateReadmeImages( );

	return 0;
}