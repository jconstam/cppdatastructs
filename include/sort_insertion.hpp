#ifndef SORT_INSERTION_HPP__
#define SORT_INSERTION_HPP__

#include "sort.hpp"

template <typename T>
class sort_insertion : public sortBase<T>
{
	public:
		sort_insertion( dataStor<T> data ) : sortBase<T>( data )
		{

		}

		void doSort( )
		{
			for( int i = 1; i < ( int ) this->m_data.size( ); i++ )
			{
				int j;
				T newValue = this->m_data.remove( i );
				for( j = 0; j < i; j++ )
				{
					if( newValue <= this->m_data[ j ] )
					{
						this->m_data.insert( newValue, j );
						break;
					}
				}

				if( i == j )
				{
					this->m_data.insert( newValue, i );
				}
			}
		}
};

#endif
