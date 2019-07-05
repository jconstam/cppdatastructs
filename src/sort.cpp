#include "sort.hpp"

sortBase::sortBase( dataStor data )
{
	changeData( data );
}

sortBase::~sortBase( )
{
	
}

void sortBase::changeData( dataStor data )
{
	m_data = data.replicate( );
}

bool sortBase::isSorted( )
{
	return m_data.isSorted( );
}

int sortBase::getSwapCount( )
{
	return m_data.getSwapCount( );
}

int sortBase::getAccessCount( )
{
	return m_data.getAccessCount( );
}

int sortBase::getInsertCount( )
{
	return m_data.getInsertCount( );
}

int sortBase::getRemoveCount( )
{
	return m_data.getRemoveCount( );
}

int sortBase::getOpsCount( )
{
	return m_data.getOpsCount( );
}

double sortBase::getSortTime( )
{
	return sortTime.count( );
}

void sortBase::outputGif( )
{
	m_data.outputGif( );
}

void sortBase::initGif( std::string fileName, int speedUpFactor )
{
	m_data.initGif( fileName, speedUpFactor );
}

void sortBase::doSortWithGif( std::string fileName, int speedUpFactor )
{
	initGif( fileName, speedUpFactor );
	doSort( );
	outputGif( );
}

void sortBase::doSort( )
{
	auto start = std::chrono::high_resolution_clock::now( );

	actualSort( );

	auto end = std::chrono::high_resolution_clock::now( );

	sortTime = std::chrono::duration_cast< std::chrono::nanoseconds >( end - start );
}