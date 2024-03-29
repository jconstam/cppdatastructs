#include <sys/stat.h>

#include "gifData.hpp"

gifData::gifData( )
{
	m_active = false;
	m_gif = nullptr;
	m_maxValue = 0;
	m_count = 0;
}

gifData::~gifData( )
{
	if( m_active )
	{
		ge_close_gif( m_gif );
	}
}

void gifData::init( std::string fileName, std::vector<int> firstFrame, size_t maxValue, int speedUpFactor )
{
	uint8_t palette[ ] = {
	    0x00, 0x00, 0x00,	// Black
	    0xFF, 0xFF, 0xFF,	// White
	    0xFF, 0x00, 0x00,	// Red
	    0x00, 0x00, 0xFF	// Blue
	};

	int depth = 2;

	m_count = firstFrame.size( );
	m_maxValue = maxValue;
	m_active = true;
	m_speedUpFactor = speedUpFactor;

	struct stat buffer;
	if( stat( "test.gif", &( buffer ) ) == 0 )
	{
		remove( "test.gif" );
	}

	m_gif = ge_new_gif( fileName.c_str( ), m_count, m_maxValue, palette, depth, -1 );

	addFrame( firstFrame );
}

void gifData::finalize( )
{
	if( m_active )
	{
		ge_close_gif( m_gif );
		m_active = false;
	}
}

void gifData::addFrame( std::vector<int> frameData, std::vector<int> markedValues, bool force )
{
	static int speedUpCount = 0;

	if( !m_active )
	{
		return;
	}

	if( !force )
	{
    	speedUpCount++;
    	speedUpCount %= m_speedUpFactor;

    	if( speedUpCount != 0 )
    	{
    		return;
    	}

		for( size_t i = 0U; i < m_count * m_maxValue; i++ )
		{
			m_gif->frame[ i ] = 1;
		}
	}


	for( size_t i = 0U; i < m_count; i++ )
	{
		bool isMarked = false;
		for( auto &v : markedValues )
		{
			if( v == ( int ) i )
			{
				isMarked = true;
				break;
			}
		}

		for( int j = 0; j < frameData[ i ]; j++ )
		{
			if( isMarked )
			{
				m_gif->frame[ ( m_maxValue - j - 1 ) * m_count + i ] = 2;
			}
			else
			{
				m_gif->frame[ ( m_maxValue - j - 1 ) * m_count + i ] = 0;
			}
		}
	}

	ge_add_frame( m_gif, 0 );
}