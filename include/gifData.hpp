#ifndef GIF_DATA_HPP__
#define GIF_DATA_HPP__

#include <vector>
#include <string>

#include "gifenc.h"

class gifData
{
	public:
		gifData( );
		~gifData( );
		
		void init( std::string fileName, std::vector<int> firstFrame, size_t maxValue, int speedUpFactor );

		void finalize( );

	    void addFrame( std::vector<int> frameData, std::vector<int> markedValues = {}, bool force = false );

	private:
		bool m_active;

		ge_GIF* m_gif;

		size_t m_maxValue;
		size_t m_count;
		int m_speedUpFactor;
};

#endif