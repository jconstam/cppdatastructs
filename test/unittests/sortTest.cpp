#include "gtest/gtest.h"

#include "sort.hpp"
#include "sort_insertion.hpp"
#include "sort_selection.hpp"
#include "sort_bubble.hpp"
#include "sort_merge.hpp"
#include "sort_quick.hpp"

class SortTest : public ::testing::Test 
{
	protected:
		static dataStor m_data;

		void SetUp( ) override
		{
			m_data.clear( );
			for( int i = 100; i >= 0; i-- )
			{
				m_data.add( i );
			}
			for( int i = 0; i <= 100; i++ )
			{
				m_data.add( i );
			}
		}

		void TearDown( ) override
		{

		}
};

dataStor SortTest::m_data;

TEST_F( SortTest, Insertion )
{
	sort_insertion sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}
TEST_F( SortTest, InsertionWithGif )
{
	sort_insertion sorter( m_data );
	sorter.doSortWithGif( "test.gif", 100 );
	EXPECT_EQ( true, sorter.isSorted( ) );

	struct stat buffer;
	ASSERT_EQ( 0, stat( "test.gif", &( buffer ) ) );
	EXPECT_EQ( 0, remove( "test.gif" ) );
}

TEST_F( SortTest, Selection )
{
	sort_selection sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}
TEST_F( SortTest, SelectionWithGif )
{
	sort_selection sorter( m_data );
	sorter.doSortWithGif( "test.gif", 100 );
	EXPECT_EQ( true, sorter.isSorted( ) );

	struct stat buffer;
	ASSERT_EQ( 0, stat( "test.gif", &( buffer ) ) );
	EXPECT_EQ( 0, remove( "test.gif" ) );
}

TEST_F( SortTest, Bubble )
{
	sort_bubble sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}
TEST_F( SortTest, BubbleWithGif )
{
	sort_bubble sorter( m_data );
	sorter.doSortWithGif( "test.gif", 100 );
	EXPECT_EQ( true, sorter.isSorted( ) );

	struct stat buffer;
	ASSERT_EQ( 0, stat( "test.gif", &( buffer ) ) );
	EXPECT_EQ( 0, remove( "test.gif" ) );
}

TEST_F( SortTest, Merge )
{
	sort_merge sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}
TEST_F( SortTest, MergeWithGif )
{
	sort_merge sorter( m_data );
	sorter.doSortWithGif( "test.gif", 100 );
	EXPECT_EQ( true, sorter.isSorted( ) );

	struct stat buffer;
	ASSERT_EQ( 0, stat( "test.gif", &( buffer ) ) );
	EXPECT_EQ( 0, remove( "test.gif" ) );
}

TEST_F( SortTest, Quick )
{
	sort_quick sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}
TEST_F( SortTest, QuickWithGif )
{
	sort_quick sorter( m_data );
	sorter.doSortWithGif( "test.gif", 100 );
	EXPECT_EQ( true, sorter.isSorted( ) );

	struct stat buffer;
	ASSERT_EQ( 0, stat( "test.gif", &( buffer ) ) );
	EXPECT_EQ( 0, remove( "test.gif" ) );
}
