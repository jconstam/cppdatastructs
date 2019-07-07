#ifndef SORT_COLLECTION_HPP__
#define SORT_COLLECTION_HPP__

#include <map>
#include <string>

#include "sort/sort.hpp"

class sortCollection
{
	public:
		sortCollection( dataStor data );
		~sortCollection( );

		void doSortAll( );
		void doSortWithGif( std::string name, std::string fileName, int speedUpFactor );
		sortBase* getSorter( std::string name );
	private:
		map<std::string, sortBase*> sorters;

		template<typename T>
		void addSorter( dataStor& data );
};

#endif