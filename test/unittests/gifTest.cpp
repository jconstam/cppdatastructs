#include "gtest/gtest.h"

#include "gifData.hpp"

TEST( GifTest, Base )
{
	std::vector<int> data = { 0, 1, 2, 3 };

	gifData gif;

	gif.init( "test.gif", data, 3, 5 );
	for( int i = 0; i < 10; i++ )
	{
		gif.addFrame( data );
	}
	for( int i = 0; i < 10; i++ )
	{
		gif.addFrame( data, { 2 }, true );
	}
}