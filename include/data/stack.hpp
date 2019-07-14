#ifndef STACK_HPP__
#define STACK_HPP__

#include "data/linkList.hpp"

#include <exception>

struct stackEmptyException : public std::exception
{
	const char * what () const throw () 
	{
		return "Stack Empty";
	}
};

class stack
{
	public:
		stack( );
		~stack( );

		void push( const int value );
		int pop( );

	private:
		linkList* m_list;
};

#endif