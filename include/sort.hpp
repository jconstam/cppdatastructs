#include "data.hpp"

template <typename T>
class sortBase
{
	public:
		sortBase( dataStor<T> data )
		{
			m_data = data.replicate( );
		}

		virtual void doSort( ) = 0;

	protected:
		dataStor<T> m_data;
};
