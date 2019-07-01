#ifndef DATA_HPP__
#define DATA_HPP__

#include <vector>
#include <cstdlib>

#include <unistd.h>

#include "gifData.hpp"

using namespace std;

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

			m_maxValue = 0;

			m_gif = gifData( );
		}

		size_t size( )
		{
			return m_data.size( );
		}

		void add( const int value )
		{
			m_data.push_back( value );
		}

		void swap( const int index1, const int index2 )
		{
			int temp = m_data[ index1 ];
			m_data[ index1 ] = m_data[ index2 ];
			m_data[ index2 ] = temp;

			addGifFrame( { index1, index2 } );

			m_swapCount++;
		}

		int remove( const int index )
		{
			int value = m_data[ index ];

			m_data.erase( m_data.begin( ) + index );

			m_removeCount++;

			return value;
		}

		void insert( const int value, const int index )
		{
			m_data.insert( m_data.begin( ) + index, value );

			addGifFrame( { index } );

			m_insertCount++;
		}

		int& operator[]( const int index )
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
			std::vector<int> newData;

			srand( time( 0 ) );

			while( m_data.size( ) > 0 )
			{
				int index = ( rand( ) % m_data.size( ) );

				newData.push_back( m_data[ index ] );
				m_data.erase( m_data.begin( ) + index );
			}

			m_data = std::vector<int>( newData );
		}

		dataStor replicate( )
		{
			dataStor newDataStor( m_maxValue );
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

			m_maxValue = maxValue;
		}

		void initGif( std::string fileName )
		{
			m_gif.init( fileName, m_data, m_maxValue );
		}

		void outputGif( )
		{
			m_gif.finalize( );
		}
	private:
		dataStor( int maxValue ) : dataStor( )
		{
			m_maxValue = maxValue;
		}

		std::vector<int> m_data;

		int m_swapCount;
		int m_accessCount;
		int m_insertCount;
		int m_removeCount;

		int m_maxValue;

		gifData m_gif;

	    void addGifFrame( std::vector<int> markedValues = {} )
	    {
	    	m_gif.addFrame( m_data, markedValues );
	    }
};

#endif