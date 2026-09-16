#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {

	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		void addNumber(int n);

		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end) {
			if (_numbers.size() + static_cast<size_t>(std::distance(begin, end)) > _maxSize)
				throw std::length_error("range too large for Span");
			_numbers.insert(_numbers.end(), begin, end);
		}

		int shortestSpan() const;
		int longestSpan() const;
};

#endif
