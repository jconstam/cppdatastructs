#include "gtest/gtest.h"

#include "sort_insertion.hpp"

TEST( InsertionSort, Sort )
{
	dataStor<int> data;
	data.generate( 100, 0, 100 );

	sort_insertion<int> sorter( data );
	sorter.doSort( );
}