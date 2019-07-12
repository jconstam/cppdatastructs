#include "gtest/gtest.h"

#include "sort/sort.hpp"
#include "sort/sort_insertion.hpp"
#include "sort/sort_selection.hpp"
#include "sort/sort_bubble.hpp"
#include "sort/sort_merge.hpp"
#include "sort/sort_quick.hpp"

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

		template <typename T>
		static void TestSort( )
		{
			T sorter = T( m_data );
			sorter.doSort( );
			ASSERT_EQ( true, sorter.isSorted( ) );
			EXPECT_STRNE( "", sorter.getName( ).c_str( ) );
			EXPECT_GT( sorter.getSortTime( ), 0.0 );
			EXPECT_GE( sorter.getSwapCount( ), 0 );
			EXPECT_GE( sorter.getAccessCount( ), 0 );
			EXPECT_GE( sorter.getInsertCount( ), 0 );
			EXPECT_GE( sorter.getRemoveCount( ), 0 );
			EXPECT_GT( sorter.getOpsCount( ), 0 );

			T sorterWithGif = T( m_data );
			sorterWithGif.doSortWithGif( "test.gif", 100 );
			ASSERT_EQ( true, sorterWithGif.isSorted( ) );

			struct stat buffer;
			ASSERT_EQ( 0, stat( "test.gif", &( buffer ) ) );
			ASSERT_EQ( 0, remove( "test.gif" ) );

			dataStor secondStore;
			secondStore.add( 1 );
			secondStore.add( 0 );

			sorter.changeData( secondStore );
			EXPECT_EQ( false, sorter.isSorted( ) );
		}
};

dataStor SortTest::m_data;

TEST_F( SortTest, Insertion )
{
	TestSort<sort_insertion>( );
}

TEST_F( SortTest, Selection )
{
	TestSort<sort_selection>( );
}

TEST_F( SortTest, Bubble )
{
	TestSort<sort_bubble>( );
}

TEST_F( SortTest, Merge )
{
	TestSort<sort_merge>( );
}

TEST_F( SortTest, Quick )
{
	TestSort<sort_quick>( );
}
