#ifndef DATA_STOR_HPP__
#define DATA_STOR_HPP__

#include <vector>
#include <cstdlib>

#include <unistd.h>

#include "gifData.hpp"

using namespace std;

class dataStor
{
	public:
		dataStor( );

		void clear( );

		size_t size( );

		void add( const int value );
		void swap( const int index1, const int index2 );
		int remove( const int index );
		void insert( const int value, const int index );
		int& operator[]( const int index );

		int getSwapCount( );
		int getAccessCount( );
		int getInsertCount( );
		int getRemoveCount( );
		int getOpsCount( );

		bool isSorted( );
		void randomize( );
		dataStor replicate( );
		void generate( int count, int maxValue );

		void initGif( std::string fileName, int speedUpFactor );
		void outputGif( );
	private:
		dataStor( int maxValue );

		std::vector<int> m_data;

		int m_swapCount;
		int m_accessCount;
		int m_insertCount;
		int m_removeCount;

		int m_maxValue;

		gifData m_gif;

	    void addGifFrame( std::vector<int> markedValues = {}, bool force = false );
};

#endif