#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "../utils/utils.hpp"
//#include "../utils/utilsVector.hpp"

namespace ft {

	template <class T> class iteratorVector {
	protected:
		T *pointer;
	public:
        typedef size_t size_type;
        typedef T& reference;
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
			return (*this->pointer);
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

//			this->pointer = this->pointer->next;
			return (it);
		}
		iteratorVector& operator--() { // --it
            this->pointer--;
//			this->pointer = this->pointer->prev;
			return (*this);
		}

		iteratorVector operator--(int) { // it--
            iteratorVector it(*this);
            this->pointer--;

//			this->pointer = this->pointer->prev;
			return (it);
		}
		iteratorVector& operator=(const iteratorVector &it) {
			this->pointer = it.pointer;
			return (*this);
		}

        iteratorVector operator+(size_type n) const {
            return (iteratorVector(this->pointer + n));
		}

        reference operator[](size_type n) {
            return (*(this->pointer + n));
        }
    };


	template < class T, class Alloc = std::allocator<T> > class vector {
	public:
		typedef T value_type;
		typedef size_t size_type;
		typedef Alloc allocator_type;
		typedef value_type& reference;
//		typedef	const reference const_reference;
//		typedef	allocator_type::pointer pointer;
//		typedef allocator_type::const_pointer const_pointer;
		typedef iteratorVector<T> iterator;
		typedef const iterator const_iterator;


		explicit vector(const allocator_type& alloc = allocator_type()): data(NULL), alloc(alloc), vector_size(0), vector_capacity() {}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type &alloc = allocator_type()) {
			this->vector_capacity = n;
            vector_size = n;
			data = this->alloc.allocate(n);
			for (int i = 0; i < n; ++i) {
				this->alloc.construct(data + i, val);
			}
		}

//		template <class InputIterator>
//		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
//
//		}

		vector(const vector& x) {

		}

		~vector() {
            this->clear();
            this->alloc.deallocate(this->data, this->vector_capacity);
		}

//        template <class InputIterator>
//        void assign (InputIterator first, InputIterator last) {
//
//		}

        void assign(size_type n, const value_type& val) {
            this->clear();
            if (this->vector_capacity < n) {
                getAllocate(n);
            }
            for (int i = 0; i < n; ++i) {
                this->alloc.construct(this->data + i, val);
            }
            this->vector_size = n;
        }


        iterator begin() {
            return (this->data);
		}

//        const_iterator begin() const {
//
//        }

        reference at(size_type n) {

		}

//        const_reference at (size_type n) const {}

//        reference back();

//        const_reference back() const;

//        reference front();

//        const_reference front() const;

        iterator end() {
            return (this->data + this->vector_size);
		}

//        const_iterator end() const {
//
//		}

        size_type max_size() const {
            return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		}

        bool empty() const {
		    return (this->vector_size == 0);
		}

        size_type size() const {
            return (this->vector_size);
		}

        size_type capacity() const {
            return (this->vector_capacity);
        }

        reference operator[](size_type n) {
            return (this->data[n]);
		}

//       const_reference operator[](size_type n) const {
//           return (this->data[n]);
//		}

        iterator insert(iterator position, const value_type& val) {
		    
		}

        void insert(iterator position, size_type n, const value_type& val) {

        }

//        template <class InputIterator>
//        void insert (iterator position, InputIterator first, InputIterator last) {
//
//		}

        iterator erase(iterator position) {
            iterator start_pos = position;
            iterator end = this->end();

            while ((position + 1) != end) {
                *position = *(position + 1);
                position++;
            }
            this->vector_size--;
            return (start_pos);
		}

        iterator erase(iterator first, iterator last) {
            iterator save_first = first;
            iterator end = this->end();
            size_type len = 0;

            while (first != last) {
                len++;
                first++;
            }
            first = save_first;

            while ((first + len) != end) {
                *first = *(first + len);
                first++;
            }
            this->vector_size -= len;
            return (save_first);

		}

        void pop_back() {
            if (this->vector_size == 0) {
                return ;
            }
            this->alloc.destroy(this->data + this->vector_size - 1);
            this->vector_size--;
		}


        void push_back(const value_type& val) {
            if (this->vector_capacity < this->vector_size + 1) {
                reserve(this->vector_capacity * 2 == 0 ? 1 : this->vector_capacity * 2);
            }
            this->alloc.construct(this->data + this->vector_size, val);
            this->vector_size++;
		}

        void resize(size_type n, value_type val = value_type()) {
            if (this->vector_size == n) {
                return ;
            }

		    if (this->vector_size > n) {
                while (this->vector_size != n) {
                    this->pop_back();
                }
		    } else {
                if (this->vector_capacity < n) {
                    reserve(max(n, this->vector_capacity * 2));
                }
                while (this->vector_size != n) {
                    this->push_back(val);
                }
		    }
        }

        void swap(vector& x) {
            swap(this->data, x.data);
            swap(this->vector_size, x.vector_size);
            swap(this->vector_capacity, x.vector_capacity);
            swap(this->alloc, x.alloc);
		}

        void reserve(size_type n) {
		    if (this->vector_capacity >= n)
                return ;
		    value_type *newData = this->alloc.allocate(n);
            for (int i = 0; i < this->vector_size; ++i) {
                this->alloc.construct(newData + i, this->data[i]);
            }
            for (int i = 0; i < this->vector_size; ++i) {
                this->alloc.destroy(this->data + i);
            }
            if (this->vector_capacity != 0) {
                this->alloc.deallocate(this->data, this->vector_capacity);
            }
            this->vector_capacity = n;
            this->data = newData;
		}

        void clear() {
            for (int i = 0; i < this->vector_size; ++i) {
                this->alloc.destroy(this->data + i);
            }
            this->vector_size = 0;
		}

	private:
		value_type *data;
		size_type vector_capacity;
		allocator_type alloc;
		size_type vector_size;


		size_type max(size_type x, size_type y) {
            return ((x > y) ? x : y);
		}

        template<typename A>
		void swap(A &x, A &y) {
            A tmp = x;
            x = y;
            y = tmp;
		}

		void getAllocate(size_type n) {
		    if (this->vector_capacity > 0) {
                this->alloc.deallocate(this->data, this->vector_capacity);
		    }
            this->data = this->alloc.allocate(n);
		    this->vector_capacity = n;
		}

	};
}
#endif //VECTOR_HPP
