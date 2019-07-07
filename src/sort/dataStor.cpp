#include "sort/dataStor.hpp"

dataStor::dataStor( )
{
	clear( );
}

dataStor::dataStor( int maxValue ) : dataStor( )
{
	m_maxValue = maxValue;
}

void dataStor::clear( )
{
	m_data.clear( );

	m_swapCount = 0;
	m_accessCount = 0;
	m_insertCount = 0;
	m_removeCount = 0;

	m_maxValue = 0;

	m_gif = gifData( );
}

size_t dataStor::size( )
{
	return m_data.size( );
}

void dataStor::add( const int value )
{
	m_data.push_back( value );
	m_maxValue = std::max( value, m_maxValue );
}

void dataStor::swap( const int index1, const int index2 )
{
	int temp = m_data[ index1 ];
	m_data[ index1 ] = m_data[ index2 ];
	m_data[ index2 ] = temp;

	addGifFrame( { index1, index2 } );

	m_swapCount++;
}

int dataStor::remove( const int index )
{
	int value = m_data[ index ];

	m_data.erase( m_data.begin( ) + index );

	m_removeCount++;

	return value;
}

void dataStor::insert( const int value, const int index )
{
	m_data.insert( m_data.begin( ) + index, value );

	addGifFrame( { index } );

	m_insertCount++;
}

int& dataStor::operator[]( const int index )
{
	m_accessCount++;

	return m_data[ index ];
}

int dataStor::getSwapCount( )
{
	return m_swapCount;
}

int dataStor::getAccessCount( )
{
	return m_accessCount;
}

int dataStor::getInsertCount( )
{
	return m_insertCount;
}

int dataStor::getRemoveCount( )
{
	return m_removeCount;
}

int dataStor::getOpsCount( )
{
	return m_swapCount + m_accessCount + m_insertCount + m_removeCount;
}

bool dataStor::isSorted( )
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

void dataStor::randomize( )
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

dataStor dataStor::replicate( )
{
	dataStor newDataStor( m_maxValue );
	for( size_t i = 0U; i < m_data.size( ); i++ )
	{
		newDataStor.add( m_data[ i ] );
	}

	return newDataStor;
}

void dataStor::generate( int count, int maxValue )
{
	clear( );
	srand( time( 0 ) );

	for( int i = 0; i < count; i++ )
	{
		add( rand() % ( maxValue + 1 ) );
	}

	m_maxValue = maxValue;
}

void dataStor::initGif( std::string fileName, int speedUpFactor )
{
	m_gif.init( fileName, m_data, m_maxValue, speedUpFactor );
}

void dataStor::outputGif( )
{
	addGifFrame( {}, true );
	m_gif.finalize( );
}

void dataStor::addGifFrame( std::vector<int> markedValues, bool force )
{
	m_gif.addFrame( m_data, markedValues, force );
}