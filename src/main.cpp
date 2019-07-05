#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>

#include "gifenc.h"

#include "data.hpp"
#include "sort_insertion.hpp"
#include "sort_selection.hpp"
#include "sort_bubble.hpp"
#include "sort_merge.hpp"
#include "sort_quick.hpp"

#include "htmlGen.hpp"

using namespace std;

static map<string, sortBase*> getSorters( dataStor temp )
{
	return map<string, sortBase*>
	{ 
		{ "Bubble", new sort_bubble( temp ) },
		{ "Selection", new sort_selection( temp ) },
		{ "Insertion", new sort_insertion( temp ) },
		{ "Merge", new sort_merge( temp ) },
		{ "Quick", new sort_quick( temp ) }
	};
}

static void cleanSorters( map<string, sortBase*> sorters )
{
	for( map<string, sortBase*>::iterator it = sorters.begin( ); it != sorters.end( ); it++ )
	{
		delete it->second;
	}
}

static void generateReadmeImages( )
{
	const int count = 500;
	const int maxValue = 200;
	const string folder = "output/readme/";

	cout << fixed << setprecision( 9 );
	cout << "Generating ReadMe Images" << endl;

	system( ( "mkdir -p " + folder ).c_str( ) );

	cout << "\tGenerating " << count << " values that are between 0 and " << maxValue << endl;
	dataStor test;
	test.generate( count, maxValue );

	map<string, sortBase*> sorters = getSorters( test );

	for( map<string, sortBase*>::iterator it = sorters.begin( ); it != sorters.end( ); it++ )
	{
		cout << "\t" << it->first << " Sort..." << endl;
		it->second->doSortWithGif( folder + "bubble.gif", 1000 );
		cout << "\t\tTook " << it->second->getSortTime( ) << " seconds" << endl;
	}

	cleanSorters( sorters );

	cout << "\tDone" << endl;
}

static void generateHTMLReport_PrintSortData( htmlGen& generator, dataStor& data, string name )
{
	map<string, sortBase*> sorters = getSorters( data );
	for( map<string, sortBase*>::iterator it = sorters.begin( ); it != sorters.end( ); it++ )
	{
		it->second->doSort( );
	}

	generator.openTag( HTML_TAG_TR );
	generator.writeTagWithValue( HTML_TAG_TD, name, { "id=rowLead" } );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( int( pow( data.size( ), 2 ) ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( int( data.size( ) * log( data.size( ) ) ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Bubble" ]->getOpsCount( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Bubble" ]->getSortTime( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Selection" ]->getOpsCount( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Selection" ]->getSortTime( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Insertion" ]->getOpsCount( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Insertion" ]->getSortTime( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Merge" ]->getOpsCount( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Merge" ]->getSortTime( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Quick" ]->getOpsCount( ) ) );
	generator.writeTagWithValue( HTML_TAG_TD, to_string( sorters[ "Quick" ]->getSortTime( ) ) );
	generator.closeTag( HTML_TAG_TR );
}

static void generateHTMLTable_Random( htmlGen& generator, int count )
{
	dataStor data;

	data.clear( );
	data.generate( count, count );

	generateHTMLReport_PrintSortData( generator, data, "Randomized array, " + to_string( count ) + " items" );
}

static void generateHTMLTable_ReverseSorted( htmlGen& generator, int count )
{
	dataStor data;

	data.clear( );
	for( int i = count; i > 0; i-- )
	{
		data.add( i );
	}

	generateHTMLReport_PrintSortData( generator, data, "Reverse-sorted array, " + to_string( count ) + " items" );
}

static void generateHTMLTable_Sorted( htmlGen& generator, int count )
{
	dataStor data;

	data.clear( );
	for( int i = 0; i < count; i++ )
	{
		data.add( i );
	}

	generateHTMLReport_PrintSortData( generator, data, "Sorted array, " + to_string( count ) + " items" );
}

static void generateHTMLTables( htmlGen& generator, int count )
{
	cout << "\tSorted (" << count << ")..." << endl;
	generateHTMLTable_Sorted( generator, count );
	cout << "\tReverse Sorted (" << count << ")..." << endl;
	generateHTMLTable_ReverseSorted( generator, count );
	cout << "\tRandom data (" << count << ")..." << endl;
	generateHTMLTable_Random( generator, count );
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
	generator.write( "\ttext-align: center;" );
	generator.write( "\tpadding: 5px;" );
	generator.write( "}" );
	generator.write( "#rowLead {" );
	generator.write( "\ttext-align: left;" );
	generator.write( "}" );
	generator.write( "tr:nth-child(even) {" );
	generator.write( "\tbackground-color: #e0e0e0;" );
	generator.write( "}" );
	generator.closeTag( HTML_TAG_STYLE );
	generator.openTag( HTML_TAG_BODY );

	generator.openTag( HTML_TAG_DIV );
	generator.openTag( HTML_TAG_TABLE );
	generator.openTag( HTML_TAG_TR );
	generator.writeTagWithValue( HTML_TAG_TH, "" );
	generator.writeTagWithValue( HTML_TAG_TH, "N^2" );
	generator.writeTagWithValue( HTML_TAG_TH, "N LOG(N)" );
	generator.writeTagWithValue( HTML_TAG_TH, "Bubble", { "colspan=2" } );
	generator.writeTagWithValue( HTML_TAG_TH, "Selection", { "colspan=2" } );
	generator.writeTagWithValue( HTML_TAG_TH, "Insertion", { "colspan=2" } );
	generator.writeTagWithValue( HTML_TAG_TH, "Merge", { "colspan=2" } );
	generator.writeTagWithValue( HTML_TAG_TH, "Quick", { "colspan=2" } );
	generator.closeTag( HTML_TAG_TR );
	generateHTMLTables( generator, 100 );
	generateHTMLTables( generator, 1000 );
	#ifdef BIG_STUFF
	generateHTMLTables( generator, 10000 );
	#endif
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