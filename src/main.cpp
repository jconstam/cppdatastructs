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

#include "htmlGen.hpp"

using namespace std;

static void generateReadmeImages( )
{
	const int count = 1000;
	const int maxValue = 200;
	const string folder = "output/readme/";

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

static void generateHTMLReport_PrintSortData( htmlGen& generator, dataStor& data, string name )
{
	sort_insertion sort_insert( data );
	sort_insert.doSort( );
	sort_selection sort_select( data );
	sort_select.doSort( );
	sort_merge sort_merge( data );
	sort_merge.doSort( );
	sort_bubble sort_bubble( data );
	sort_bubble.doSort( );
	sort_quick sort_quick( data );
	sort_quick.doSort( );

	generator.openTag( HTML_TAG_TR );
	generator.writeTagWithValue( HTML_TAG_TD, name );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sort_insert.getOpsCount( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sort_select.getOpsCount( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sort_bubble.getOpsCount( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sort_merge.getOpsCount( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sort_quick.getOpsCount( ) ) );
	generator.closeTag( HTML_TAG_TR );
}

static void generateHTMLTable_Random( htmlGen& generator, int count )
{
	dataStor data;

	data.clear( );
	data.generate( count, count );

	generateHTMLReport_PrintSortData( generator, data, "Randomized array, " + to_string( count ) + " items" );
}

static void generateHTMLReport( )
{
	htmlGen generator;

	cout << "Generating HTML Report" << endl;
	cout << "\tCreating header..." << endl;
	generator.openTag( HTML_TAG_HTML );
	generator.writeTagWithValue( HTML_TAG_TITLE, "C++ Sorting" );
	generator.openTag( HTML_TAG_STYLE );
	generator.write( "table {" );
	generator.write( "\tborder-collapse: collapse;" );
	generator.write( "\twidth: 100%;" );
	generator.write( "}" );
	generator.write( "table, th, td {" );
	generator.write( "\tborder: 1px solid black;" );
	generator.write( "}" );
	generator.write( "th, td {" );
	generator.write( "\tpadding: 5px;" );
	generator.write( "}" );
	generator.write( "tr:nth-child(even) {" );
	generator.write( "\tbackground-color: #f2f2f2;" );
	generator.write( "}" );
	generator.closeTag( HTML_TAG_STYLE );
	generator.openTag( HTML_TAG_BODY );

	generator.openTag( HTML_TAG_DIV );
	generator.writeTagWithValue( HTML_TAG_H2, name );
	generator.openTag( HTML_TAG_TABLE );
	generator.openTag( HTML_TAG_TR );
	generator.writeTagWithValue( HTML_TAG_TH, "" );
	generator.writeTagWithValue( HTML_TAG_TH, "Insertion" );
	generator.writeTagWithValue( HTML_TAG_TH, "Selection" );
	generator.writeTagWithValue( HTML_TAG_TH, "Bubble" );
	generator.writeTagWithValue( HTML_TAG_TH, "Merge" );
	generator.writeTagWithValue( HTML_TAG_TH, "Quick" );
	generator.closeTag( HTML_TAG_TR );
	cout << "\tRandom data (100)..." << endl;
	generateHTMLTable_Random( generator, 100 );
	cout << "\tRandom data (1000)..." << endl;
	generateHTMLTable_Random( generator, 1000 );
	//cout << "\tRandom data (10000)..." << endl;
	//generateHTMLTable_Random( generator, 10000 );
	generator.closeTag( HTML_TAG_TABLE );
	generator.closeTag( HTML_TAG_DIV );

	generator.closeTag( HTML_TAG_BODY );
	generator.closeTag( HTML_TAG_HTML );

	cout << "\tOutputting file..." << endl;
	generator.writeFile( "output/test.html" );
	cout << "\tDone" << endl;
}

int main( int argc, char* argv[ ] )
{
	generateReadmeImages( );
	generateHTMLReport( );

	return 0;
}