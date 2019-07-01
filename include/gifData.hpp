#ifndef GIF_DATA_HPP__
#define GIF_DATA_HPP__

#include <vector>
#include <string>

#include "gifenc.h"

class gifData
{
	public:
		gifData( std::string fileName, std::vector<int> firstFrame, size_t maxValue )
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

			m_gif = ge_new_gif( fileName.c_str( ), m_count, m_maxValue, palette, depth, -1 );

			addFrame( firstFrame );
		}

		void finalize( )
		{
			ge_close_gif( m_gif );
		}

	    void addFrame( std::vector<int> frameData, std::vector<int> markedValues = {} )
	    {
	    	static int speedUpCount = 0;

	    	if( m_count * m_maxValue == 0U )
	    	{
	    		return;
	    	}

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

				for( int j = 0; j <= frameData[ i ]; j++ )
				{
					if( isMarked )
					{
						m_gif->frame[ ( m_maxValue - j ) * m_count + i ] = 2;
					}
					else
					{
						m_gif->frame[ ( m_maxValue - j ) * m_count + i ] = 0;
					}
				}
			}

			ge_add_frame( m_gif, 0 );
	    }

	private:
		ge_GIF* m_gif;
		size_t m_maxValue;
		size_t m_count;

		static const int m_speedUpFactor = 10;
};

#endif