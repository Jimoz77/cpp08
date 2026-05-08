#ifndef SPAN_HPP
#define SPAN_HPP


#include <exception>
#include <vector>
#include <iterator>

class Span
{
	private:
			unsigned int _nb;
			std::vector<int> _span;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		void addNumber(int nb);

		template<typename Itera>
		void addNumber(Itera begin, Itera end)
		{
			if(static_cast<unsigned int>(std::distance(begin, end)) > _nb - _span.size())
				throw maxCap();
			_span.insert(_span.end(), begin, end);
		}

		unsigned int shortestSpan();
		unsigned int longestSpan();
		Span &operator=(const Span &other);
		~Span();
		
	class maxCap : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Maximal capacity has been reach, you can't add more numbers\n");
		}
	};
	class emptyOrSingle : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("span is empty or single\n");
		}
	};
};



#endif
