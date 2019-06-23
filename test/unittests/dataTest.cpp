#include "gtest/gtest.h"

#include "data.hpp"

TEST( DataTest, Constructor )
{
	dataStor<int> storage = dataStor<int>( );

	EXPECT_EQ( 0, storage.getSwapCount( ) );
	EXPECT_EQ( 0, storage.getAccessCount( ) );
}

TEST( DataTest, Access )
{
	dataStor<int> storage = dataStor<int>( );

	storage.add( 1 );
	storage.add( 2 );
	storage.add( 3 );

	EXPECT_EQ( 1, storage[ 0 ] );
	EXPECT_EQ( 2, storage[ 1 ] );
	EXPECT_EQ( 3, storage[ 2 ] );
	EXPECT_EQ( 3, storage.getAccessCount( ) );
	EXPECT_EQ( 0, storage.getSwapCount( ) );
}

TEST( DataTest, swap )
{
	dataStor<int> storage = dataStor<int>( );

	storage.add( 1 );
	storage.add( 2 );
	storage.add( 3 );

	storage.swap( 0, 2 );
	storage.swap( 0, 1 );	

	EXPECT_EQ( 2, storage[ 0 ] );
	EXPECT_EQ( 3, storage[ 1 ] );
	EXPECT_EQ( 1, storage[ 2 ] );
	EXPECT_EQ( 3, storage.getAccessCount( ) );
	EXPECT_EQ( 2, storage.getSwapCount( ) );

	storage.clear( );

	EXPECT_EQ( 0, storage.getAccessCount( ) );
	EXPECT_EQ( 0, storage.getSwapCount( ) );
}

TEST( DataTest, Sorted )
{
	dataStor<int> storage = dataStor<int>( );

	storage.add( 1 );
	storage.add( 2 );
	storage.add( 3 );

	EXPECT_EQ( true, storage.isSorted( ) );

	storage.swap( 0, 2 );

	EXPECT_EQ( false, storage.isSorted( ) );
}

TEST( DataTest, Randomize )
{
	dataStor<int> storage = dataStor<int>( );

	storage.add( 1 );
	storage.add( 2 );
	storage.add( 3 );

	EXPECT_EQ( true, storage.isSorted( ) );

	storage.randomize( );

	EXPECT_EQ( false, storage.isSorted( ) );
}