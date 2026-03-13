#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <iostream>



class notFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("No occurence has been found\n");
		}
};

class empty : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Parameter T is empty\n");
		}
};



template<typename T>
typename T::iterator easyfind(T& arg, int n)
{
	 if(arg.empty())
		throw empty();
	typename T::iterator result = std::find(arg.begin(),arg.end(), n);
	if (result == arg.end())
		throw notFound();

	return result;	
}


#endif
