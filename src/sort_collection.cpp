#include "sort_collection.hpp"

#include "data.hpp"

#include "sort.hpp"
#include "sort_bubble.hpp"
#include "sort_selection.hpp"
#include "sort_insertion.hpp"
#include "sort_merge.hpp"
#include "sort_quick.hpp"

#include <iostream>
using namespace std;

sortCollection::sortCollection( dataStor data )
{
	addSorter<sort_bubble>( data );
	addSorter<sort_selection>( data );
	addSorter<sort_insertion>( data );
	addSorter<sort_merge>( data );
	addSorter<sort_quick>( data );
}
sortCollection::~sortCollection( )
{
	for( map<string, sortBase*>::iterator it = sorters.begin( ); it != sorters.end( ); it++ )
	{
		delete it->second;
	}
}

void sortCollection::doSortAll( )
{
	for( map<string, sortBase*>::iterator it = sorters.begin( ); it != sorters.end( ); it++ )
	{
		it->second->doSort( );
	}
}

void sortCollection::doSortWithGif( string name, string fileName, int speedUpFactor )
{
	if( sorters.find( name ) != sorters.end( ) )
	{
		sorters[ name ]->doSortWithGif( fileName, speedUpFactor );
	}
}

sortBase* sortCollection::getSorter( std::string name )
{
	if( sorters.find( name ) == sorters.end( ) )
	{
		return nullptr;
	}
	else
	{
		return sorters[ name ];
	}
}

template<typename T>
void sortCollection::addSorter( dataStor& data )
{
	T* sorter = new T( data );
	sorters[ sorter->getName( ) ] = sorter;
}
