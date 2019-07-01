#ifndef SORT_INSERTION_HPP__
#define SORT_INSERTION_HPP__

#include <iostream>

#include "sort.hpp"

class sort_insertion : public sortBase
{
	public:
		sort_insertion( dataStor data ) : sortBase( data )
		{

		}

		void doSort( )
		{
			for( int i = 1; i < ( int ) this->m_data.size( ); i++ )
			{
				std::cout << i << std::endl;
				int j;
				int newValue = this->m_data.remove( i );
				for( j = 0; j < i; j++ )
				{
					if( newValue < this->m_data[ j ] )
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
