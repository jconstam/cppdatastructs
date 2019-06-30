#include "data.hpp"

template <typename T>
class sortBase
{
	public:
		sortBase( dataStor<T> data )
		{
			m_data = data;
		}

		void outputGif( )
		{
			m_data.outputGif( );
		}

		void initGif( std::string fileName )
		{
			m_data.initGif( fileName );
		}

		virtual void doSort( ) = 0;

	protected:
		dataStor<T> m_data;
};
