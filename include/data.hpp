#ifndef DATA_H__
#define DATA_H__

#include <vector>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <iostream>

#include <unistd.h>

#include "gifenc.h"

using namespace std;

template <typename T>
class dataStor
{
	public:
		dataStor( )
		{
			clear( );
		}

		void clear( )
		{
			m_data.clear( );

			m_swapCount = 0;
			m_accessCount = 0;
			m_insertCount = 0;
			m_removeCount = 0;
		}

		size_t size( )
		{
			return m_data.size( );
		}

		void add( const T value )
		{
			m_data.push_back( value );
		}

		void swap( const int index1, const int index2 )
		{
			T temp = m_data[ index1 ];
			m_data[ index1 ] = m_data[ index2 ];
			m_data[ index2 ] = temp;

			addGifFrame( );

			m_swapCount++;
		}

		T remove( const int index )
		{
			T value = m_data[ index ];

			m_data.erase( m_data.begin( ) + index );

			m_removeCount++;

			return value;
		}

		void insert( const T value, const int index )
		{
			m_data.insert( m_data.begin( ) + index, value );

			addGifFrame( index );

			m_insertCount++;
		}

		T& operator[]( const int index )
		{
			m_accessCount++;

			return m_data[ index ];
		}

		int getSwapCount( )
		{
			return m_swapCount;
		}
		
		int getAccessCount( )
		{
			return m_accessCount;
		}

		bool isSorted( )
		{
			for( size_t i = 0U; i < m_data.size( ) - 1U; i++ )
			{
				if( m_data[ i ] > m_data[ i + 1U ] )
				{
					return false;
				}
			}

			return true;
		}

		void randomize( )
		{
			std::vector<T> newData;

			srand( time( 0 ) );

			while( m_data.size( ) > 0 )
			{
				int index = ( rand( ) % m_data.size( ) );

				newData.push_back( m_data[ index ] );
				m_data.erase( m_data.begin( ) + index );
			}

			m_data = std::vector<T>( newData );
		}

		dataStor<T> replicate( )
		{
			dataStor<T> newDataStor( m_gif_count, m_gif_maxValue );
			for( size_t i = 0U; i < m_data.size( ); i++ )
			{
				newDataStor.add( m_data[ i ] );
			}

			return newDataStor;
		}

		void generate( int count, int maxValue )
		{
			clear( );
			srand( time( 0 ) );

			for( int i = 0; i < count; i++ )
			{
				add( rand() % ( maxValue + 1 ) );
			}

			generateGif( count, maxValue );
			addGifFrame( );
		}

		void outputGif( )
		{
			ge_close_gif( m_gif );
		}
	private:
		dataStor( int count, int maxValue ) : dataStor( )
		{
			generateGif( count, maxValue );
		}

		std::vector<T> m_data;

		int m_swapCount;
		int m_accessCount;
		int m_insertCount;
		int m_removeCount;

		ge_GIF* m_gif;
		int m_gif_count;
		int m_gif_maxValue;

		void generateGif( int count, int maxValue )
		{
			m_gif_count = count;
			m_gif_maxValue = maxValue;

			uint8_t palette[ ] = {
			    0x00, 0x00, 0x00,	// Black
			    0xFF, 0xFF, 0xFF,	// White
			    0xFF, 0x00, 0x00,	// Red
			    0x00, 0x00, 0xFF	// Blue
			};

			int depth = 2;

			m_gif = ge_new_gif( "test.gif", m_gif_count, m_gif_maxValue, palette, depth, 0 );
		}

	    void addGifFrame( int markedValue = INT_MAX )
	    {
			for( int i = 0; i < m_gif_count; i++ )
			{
				for( int j = 0; j < m_data[ i ]; j++ )
				{
					m_gif->frame[ j * m_gif_count + i ] = 1;
				}
				for( int j = m_data[ i ]; j < m_gif_maxValue; j++ )
				{
					if( j == markedValue )
					{
						m_gif->frame[ j * m_gif_count + i ] = 2;
					}
					else
					{
						m_gif->frame[ j * m_gif_count + i ] = 0;
					}
				}
			}

			ge_add_frame( m_gif, 1 );
	    }
};

#endif