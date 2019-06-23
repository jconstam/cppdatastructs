#include "gtest/gtest.h"

#include "data.hpp"

TEST( DataTest, Constructor )
{
	DataStorage<int> storage = DataStorage<int>( );

	EXPECT_EQ( 0, storage.getSwapCount( ) );
	EXPECT_EQ( 0, storage.getAccessCount( ) );
}

TEST( DataTest, Access )
{
	DataStorage<int> storage = DataStorage<int>( );

	storage.Add( 1 );
	storage.Add( 2 );
	storage.Add( 3 );

	EXPECT_EQ( 1, storage[ 0 ] );
	EXPECT_EQ( 2, storage[ 1 ] );
	EXPECT_EQ( 3, storage[ 2 ] );
	EXPECT_EQ( 3, storage.getAccessCount( ) );
	EXPECT_EQ( 0, storage.getSwapCount( ) );
}

TEST( DataTest, Swap )
{
	DataStorage<int> storage = DataStorage<int>( );

	storage.Add( 1 );
	storage.Add( 2 );
	storage.Add( 3 );

	storage.Swap( 0, 2 );
	storage.Swap( 0, 1 );	

	EXPECT_EQ( 2, storage[ 0 ] );
	EXPECT_EQ( 3, storage[ 1 ] );
	EXPECT_EQ( 1, storage[ 2 ] );
	EXPECT_EQ( 3, storage.getAccessCount( ) );
	EXPECT_EQ( 2, storage.getSwapCount( ) );
	EXPECT_EQ( 3, storage.getAccessCount( ) );	
}