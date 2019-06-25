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

TEST( DataTest, Remove )
{
	dataStor<int> storage = dataStor<int>( );

	storage.add( 1 );
	storage.add( 2 );
	storage.add( 3 );
	storage.add( 4 );
	storage.add( 5 );

	EXPECT_EQ( 1, storage[ 0 ] );
	EXPECT_EQ( 2, storage[ 1 ] );
	EXPECT_EQ( 3, storage[ 2 ] );
	EXPECT_EQ( 4, storage[ 3 ] );
	EXPECT_EQ( 5, storage[ 4 ] );

	storage.remove( 2 );
	storage.remove( 1 );

	EXPECT_EQ( 1, storage[ 0 ] );
	EXPECT_EQ( 4, storage[ 1 ] );
	EXPECT_EQ( 5, storage[ 2 ] );
}

TEST( DataTest, Insert )
{
	dataStor<int> storage = dataStor<int>( );

	storage.add( 1 );
	storage.add( 2 );
	storage.add( 3 );

	storage.insert( 4, 1 );

	EXPECT_EQ( 1, storage[ 0 ] );
	EXPECT_EQ( 4, storage[ 1 ] );
	EXPECT_EQ( 2, storage[ 2 ] );
	EXPECT_EQ( 3, storage[ 3 ] );
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

	for( int i = 0; i < 100; i++ )
	{
		if( storage.isSorted( ) )
		{
			storage.randomize( );
		}
		else
		{
			EXPECT_EQ( false, storage.isSorted( ) );
		}
	}
}

TEST( DataTest, Replicate )
{
	dataStor<int> storage = dataStor<int>( );

	storage.add( 1 );
	storage.add( 2 );
	storage.add( 3 );

	storage.randomize( );

	dataStor<int> storage2 = storage.replicate( );

	EXPECT_EQ( storage[ 0 ], storage2[ 0 ] );
	EXPECT_EQ( storage[ 1 ], storage2[ 1 ] );
	EXPECT_EQ( storage[ 2 ], storage2[ 2 ] );
}

TEST( DataTest, Generate )
{
	dataStor<int> storage = dataStor<int>( );

	storage.generate( 10, -5, 5 );

	for( int i = 0; i < 10; i++ )
	{
		EXPECT_GE( 5, storage[ i ] );
		EXPECT_LE( -5, storage[ i ] );
	}
}