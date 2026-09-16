#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {

	private:
		T			*_data;
		size_t		_size;

	public:
		Array() : _data(NULL), _size(0) {}

		explicit Array(unsigned int n) : _data(n ? new T[n]() : NULL), _size(n) {}

		Array(Array const &other) : _data(NULL), _size(0) {
			*this = other;
		}

		Array &operator=(Array const &other) {
			if (this != &other) {
				delete[] _data;
				_size = other._size;
				_data = _size ? new T[_size] : NULL;
				for (size_t i = 0; i < _size; i++)
					_data[i] = other._data[i];
			}
			return (*this);
		}

		~Array() {
			delete[] _data;
		}

		T &operator[](size_t index) {
			if (index >= _size)
				throw std::exception();
			return (_data[index]);
		}

		T const &operator[](size_t index) const {
			if (index >= _size)
				throw std::exception();
			return (_data[index]);
		}

		size_t size() const {
			return (_size);
		}
};

#endif
