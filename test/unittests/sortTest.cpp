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
		}

		void TearDown( ) override
		{

		}

		static dataStor<int> m_data;
};

dataStor<int> SortTest::m_data;

TEST_F( SortTest, Insertion )
{
	sort_insertion<int> sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}

TEST_F( SortTest, Selection )
{
	sort_selection<int> sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}
TEST_F( SortTest, Bubble )
{
	sort_bubble<int> sorter( m_data );
	sorter.doSort( );
	EXPECT_EQ( true, sorter.isSorted( ) );
}
