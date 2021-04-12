#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

namespace ft {

	template <class T> class iteratorVector {
	protected:
		T *pointer;
	public:
//		template<typename myT, typename Alloc>
//		friend class list;

		iteratorVector(T *pointer = NULL):pointer(pointer) {}

		bool operator==(iteratorVector const &itV) {
			return (this->pointer == itV.pointer);
		}

		bool operator!=(iteratorVector const &itV) {
			return (!(*this == itV));
		}

		T& operator*() {
			return (this->pointer);


		}

		T* operator->() {
			return (&(this->pointer));
		}

		iteratorVector& operator++() { // ++it
			this->pointer++;
//			this->pointer = this->pointer->next;
			return (*this);
		}

		iteratorVector operator++(int) { // it++
			iteratorVector it(*this);
			this->pointer++;
//			++it;

//			this->pointer = this->pointer->next;
			return (it);
		}
		iteratorVector& operator--() { // --it
			this->pointer = this->pointer->prev;
			return (*this);
		}

		iteratorVector operator--(int) { // it--
			iteratorList it(*this);
			this->pointer = this->pointer->prev;
			return (it);
		}
		iteratorVector& operator=(const iteratorVector &it) {
			this->pointer = it.pointer;
			return (*this);
		}
	};




	template < class T, class Alloc = std::allocator<T> > class vector {
	public:
		typedef T value_type;
		typedef size_t size_type;
		typedef Alloc allocator_type;
		typedef allocator_type::reference reference;
		typedef	allocator_type::const_reference const_reference;
		typedef	allocator_type::pointer pointer;
		typedef allocator_type::const_pointer const_pointer;
		typedef IteratorVector<T> iterator;


		explicit vector(const allocator_type& alloc = allocator_type()):data(NULL), alloc(alloc), size_vector(0), capacity(0) {}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
			capacity = n;
			size_vector = n;
			data = alloc.allocate(n);
			for (int i = 0; i < n; ++i) {
				alloc.construct(data + i, val);
			}
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {

		}

		vector(const vector& x) {

		}

		~vector() {

		}

	private:
		value_type *data;
		size_type capacity;
		allocator_type alloc;
		size_type size_vector;
	};
}
#endif //VECTOR_HPP
