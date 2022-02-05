#ifndef __MUTANT_STACK_HPP__
#define __MUTANT_STACK_HPP__

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef	typename std::stack<T>::container_type::iterator		iterator;

	iterator begin( void ) { return(this->c.begin()); }
	iterator end( void ) { return(this->c.end()); }
};

#endif