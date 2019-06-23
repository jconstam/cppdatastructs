#include <vector>

template <typename T> class DataStorage
{
	public:
		DataStorage( )
		{
			Clear( );
		}

		void Clear( )
		{
			m_data.clear( );

			m_swapCount = 0;
			m_accessCount = 0;
		}

		void Add( const T value )
		{
			m_data.push_back( value );
		}

		void Swap( const int index1, const int index2 )
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
	private:
		std::vector<T> m_data;

		int m_swapCount;
		int m_accessCount;
};
