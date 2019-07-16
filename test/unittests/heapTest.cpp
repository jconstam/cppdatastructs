#include "gtest/gtest.h"

#include "data/heap.hpp"

class HeapTest : public ::testing::Test 
{
	protected:
		heap* testHeap;

		void SetUp( ) override
		{
			testHeap = new heap( );
		}

		void TearDown( ) override
		{
			delete testHeap;
		}
};

TEST_F( HeapTest, Heap )
{
	testHeap->add( 3 );
	testHeap->add( 1 );
	testHeap->add( 5 );
	testHeap->add( 2 );
	testHeap->add( 4 );
	testHeap->printAll( );
}
