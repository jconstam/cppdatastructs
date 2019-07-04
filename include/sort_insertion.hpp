#ifndef SORT_INSERTION_HPP__
#define SORT_INSERTION_HPP__

#include "sort.hpp"

class sort_insertion : public sortBase
{
	public:
		sort_insertion( dataStor data ) : sortBase( data )
		{

		}

		void actualSort( )
		{
			for( int i = 1; i < ( int ) m_data.size( ); i++ )
			{
				int j;
				int newValue = m_data.remove( i );
				for( j = 0; j < i; j++ )
				{
					if( newValue < m_data[ j ] )
					{
						m_data.insert( newValue, j );
						break;
					}
				}

				if( i == j )
				{
					m_data.insert( newValue, i );
				}
			}
		}
};

#endif
