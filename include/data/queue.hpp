#ifndef QUEUE_HPP__
#define QUEUE_HPP__

#include "data/linkList.hpp"

#include <exception>

struct queueEmptyException : public std::exception
{
	const char * what () const throw () 
	{
		return "Queue Empty";
	}
};

class queue
{
	public:
		queue( );
		~queue( );

		void push( const int value );
		int pop( );

	private:
		linkList* m_list;
};

#endif