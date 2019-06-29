#include "data.hpp"

template <typename T>
class sortBase
{
	public:
		sortBase( dataStor<T> data )
		{
			m_data = data.replicate( );
		}

		void outputGif( )
		{
			m_data.outputGif( );
		}

		virtual void doSort( ) = 0;

	protected:
		dataStor<T> m_data;
};
