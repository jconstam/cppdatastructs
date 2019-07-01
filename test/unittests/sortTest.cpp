#include "gtest/gtest.h"

#include "sort.hpp"
#include "sort_insertion.hpp"
#include "sort_selection.hpp"
#include "sort_bubble.hpp"

class SortTest : public ::testing::Test 
{
	protected:
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

		static dataStor m_data;
};

dataStor SortTest::m_data;

TEST_F( SortTest, Insertion )
{
	sort_insertion sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}

TEST_F( SortTest, Selection )
{
	sort_selection sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}
TEST_F( SortTest, Bubble )
{
	sort_bubble sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}
