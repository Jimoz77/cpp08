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
	unsigned int min_dist = sorted_span[1] - sorted_span[0];
	for(size_t i = 1; i < sorted_span.size() - 1; i++)
	{
		unsigned int current_dist = sorted_span[i + 1] - sorted_span[i];
		if(current_dist < min_dist)
			min_dist = current_dist;
	}
	return (min_dist);
}

unsigned int Span::longestSpan()
{
	if(_span.size() <= 1)
		throw emptyOrSingle();
	int min = *std::min_element(_span.begin(), _span.end());
	int max = *std::max_element(_span.begin(), _span.end());
	return (max - min);

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

