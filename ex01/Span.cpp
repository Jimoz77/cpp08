#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span() : _nb(0)
{
}

Span::Span(unsigned int n) : _nb(n)
{
}

Span::Span(const Span &other) : _nb(other._nb) , _span(other._span)
{
}

void Span::addNumber(int nb)
{
	if(_span.size() >= _nb)
		throw maxCap();
	_span.push_back(nb);
}


unsigned int Span::shortestSpan()
{
	if(_span.size() <= 1)
		throw emptyOrSingle();
	std::vector<int> sorted_span = _span;
	std::sort(sorted_span.begin(),sorted_span.end());
	long min_dist_long = static_cast<long>(sorted_span[1]) - static_cast<long>(sorted_span[0]);
	unsigned int min_dist = static_cast<unsigned int>(min_dist_long);
	for(size_t i = 1; i < sorted_span.size() - 1; i++)
	{
		long current_dist_long = static_cast<long>(sorted_span[i + 1]) - static_cast<long>(sorted_span[i]);
		unsigned int current_dist = static_cast<unsigned int>(current_dist_long);
		if(current_dist < min_dist)
			min_dist = current_dist;
	}
	return (min_dist);
}

unsigned int Span::longestSpan()
{
	if(_span.size() <= 1)
		throw emptyOrSingle();
	long min = *std::min_element(_span.begin(), _span.end());
	long max = *std::max_element(_span.begin(), _span.end());
	return (static_cast<unsigned int>(max - min));

}

Span& Span::operator=(const Span &other)
{
	if(this != &other)
	{
		_nb = other._nb;
		_span = other._span;
	}
	return (*this);

}

Span::~Span()
{
}

