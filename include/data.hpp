#include <vector>
#include <ctime>
#include <cstdlib>

template <typename T> class dataStor
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

			m_swapCount++;
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
			dataStor<T> newDataStor;
			for( size_t i = 0U; i < m_data.size( ); i++ )
			{
				newDataStor.add( m_data[ i ] );
			}

			return newDataStor;
		}
	private:
		std::vector<T> m_data;

		int m_swapCount;
		int m_accessCount;
};
