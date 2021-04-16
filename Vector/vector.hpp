#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "../utils/utils.hpp"
//#include "../utils/utilsVector.hpp"

namespace ft {

	template <class T> class iteratorVector {

//        template <class A>
//        friend class iteratorConstReverseVector;

	protected:
		T *pointer;
	public:
        typedef size_t size_type;
        typedef T& reference;

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

        iteratorVector operator-(size_type n) const {
            return (iteratorVector(this->pointer - n));
        }

        reference operator[](size_type n) {
            return (*(this->pointer + n));
        }
    };

    template <class T> class iteratorConstVector : public iteratorVector<T> {
    public:

        iteratorConstVector() {}
        iteratorConstVector(T *pointer) {
            this->pointer = pointer;
        }
        iteratorConstVector(iteratorVector<T> const &itConst):iteratorVector<T>(itConst) {
//            *this = itReverse;
        }
        ~iteratorConstVector() {}

        const T& operator*() {
            return (*this->pointer);
        }

        const T* operator->() {
            return (&(this->pointer));
        }

        iteratorConstVector& operator=(const iteratorVector<T> &it) {
            this->pointer = it.pointer;
            return (*this);
        }
    };

    template <class T> class iteratorReverseVector : public iteratorVector<T> {
    public:

        iteratorReverseVector() {}
        iteratorReverseVector(T *pointer) {
            this->pointer = pointer;
        }
        iteratorReverseVector(iteratorReverseVector const &itReverse) {
            *this = itReverse;
        }
        ~iteratorReverseVector() {}

        iteratorReverseVector& operator++() { // ++it
            this->pointer--;
            return (*this);
        }

        iteratorReverseVector operator++(int) { // it++
            iteratorReverseVector it(*this);
            this->pointer--;
            return (it);
        }
        iteratorReverseVector& operator--() { // --it
            this->pointer++;
            return (*this);
        }

        iteratorReverseVector operator--(int) { // it--
            iteratorReverseVector it(*this);
            this->pointer++;
            return (it);
        }

        iteratorReverseVector& operator=(const iteratorVector<T> &it) {
            this->pointer = it.pointer;
            return (*this);
        }
    };

    template <class T> class iteratorConstReverseVector : public iteratorReverseVector<T> {
    public:

        iteratorConstReverseVector() {}
        iteratorConstReverseVector(T *pointer) {
            this->pointer = pointer;
        }
        iteratorConstReverseVector(iteratorReverseVector<T> const &itReverse):iteratorReverseVector<T>(itReverse) {}
        ~iteratorConstReverseVector() {}

        const T& operator*() {
            return (*this->pointer);
        }

        const T* operator->() {
            return (&(this->pointer));
        }

        iteratorConstReverseVector& operator=(const iteratorReverseVector<T> &it) {
            this->pointer = it.pointer;
            return (*this);
        }
    };

	template < class T, class Alloc = std::allocator<T> > class vector {
	public:
		typedef T value_type;
		typedef size_t size_type;
		typedef Alloc allocator_type;
//		typedef value_type& reference;
//		typedef	const value_type& const_reference;
//		typedef	allocator_type::pointer pointer;
//		typedef allocator_type::const_pointer const_pointer;
        typedef	typename allocator_type::reference reference;
        typedef	typename allocator_type::const_reference const_reference;
        typedef iteratorVector<T> iterator;
        typedef iteratorConstVector<T> const_iterator;
        typedef iteratorReverseVector<T> reverse_iterator;
        typedef iteratorConstReverseVector<T> const_reverse_iterator;


		explicit vector(const allocator_type& alloc = allocator_type()): data(NULL), alloc(alloc), vector_size(0), vector_capacity() {}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type &alloc = allocator_type()) {
			this->vector_capacity = n;
            vector_size = n;
			data = this->alloc.allocate(n);
			for (int i = 0; i < n; ++i) {
				this->alloc.construct(data + i, val);
			}
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
               typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0):data(NULL), alloc(alloc), vector_size(0), vector_capacity(0) {
            assign(first, last);
		}

		vector(const vector& x): data(NULL), alloc(x.alloc), vector_size(0), vector_capacity(0) {
            assign(x.begin(), x.end());
		}

		~vector() {
            this->clear();
            this->alloc.deallocate(this->data, this->vector_capacity);
		}

        vector &operator=(vector const &x) {
            this->assign(x.begin(), x.end());
            return (*this);
        }

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {
            this->clear();
            size_type len = indexPos(first, last);

            if (this->vector_capacity < len) {
                getAllocate(len);
            }
            for (int i = 0; i < len; ++i) {
                this->alloc.construct(this->data + i, *first);
                first++;
            }
            this->vector_size = len;
		}

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

        const_iterator begin() const {
            return (this->data);
        }

        reference at(size_type n) {
            if (n >= this->vector_size)  {
                throw std::out_of_range("out of range");
            }
            return (this->data[n]);
		}

        const_reference at(size_type n) const {
            if (n >= this->vector_size)  {
                throw std::out_of_range("out of range");
            }
            return (this->data[n]);
        }

        reference back() {
            return (this->data[this->vector_size - 1]);
		}

        const_reference back() const {
            return (this->data[this->vector_size - 1]);
		}

        reference front() {
            return (this->data[0]);
		}

        const_reference front() const {
            return (this->data[0]);
		}

        iterator end() {
            return (this->data + this->vector_size);
		}

        const_iterator end() const {
            return (this->data + this->vector_size);
		}

        reverse_iterator rbegin() {
            return (this->data + this->vector_size - 1);
		}

        const_reverse_iterator rbegin() const {
            return (this->data + this->vector_size - 1);
		}

        reverse_iterator rend() {
            return (this->data - 1);
		}

        const_reverse_iterator rend() const {
            return (this->data - 1);
        }

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

       const_reference operator[](size_type n) const {
           return (this->data[n]);
		}

        iterator insert(iterator position, const value_type& val) {

            if (this->vector_capacity < this->vector_size + 1) {
                size_type len = indexPos(position, --this->end());
                reserve(this->vector_capacity == 0 ? 1 : this->vector_capacity * 2);
                position = this->end() - len - 1;
            }

            iterator end = this->end();

            while (--end != position) {
                this->alloc.construct(&(*end) + 1, *end);
                this->alloc.destroy(&(*end));
            }

            this->alloc.construct(&(*end) + 1, *end);
            this->alloc.destroy(&(*position));
            this->alloc.construct(&(*position), val);
            this->vector_size++;
            return position;
        }

        void insert(iterator position, size_type n, const value_type& val) {

            // TODO -  check if vector_size + n > capacity * 2
            if (this->vector_capacity < this->vector_size + n) {
                size_type len = indexPos(position, --this->end());
                reserve(this->vector_capacity == 0 ? 1 : this->vector_capacity * 2);
                position = --this->end() - len;
            }

            iterator end = this->end();

            while (--end != position - 1) {
                this->alloc.construct(&(*end) + n, *end);
                this->alloc.destroy(&(*end));
            }

            while (++end != position + n) {
                this->alloc.destroy(&(*end));
                this->alloc.construct(&(*end), val);
            }
            this->vector_size += n;
        }

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {

		    size_type len = indexPos(first, last);

		    // TODO -  check if vector_size + n > capacity * 2
            if (this->vector_capacity < this->vector_size + len) {
                size_type len_pos = indexPos(position, --this->end());
                reserve(this->vector_capacity == 0 ? 1 : this->vector_capacity * 2);
                position = --this->end() - len_pos;
            }

            iterator end = this->end();
            while (--end != position - 1) {
                this->alloc.construct(&(*end) + len, *end);
                this->alloc.destroy(&(*end));
            }

            while (++end != position + len) {
                this->alloc.destroy(&(*end));
                this->alloc.construct(&(*end), *first);
                first++;
            }
            this->vector_size += len;
		}

        iterator erase(iterator position) {
            iterator end = this->end();
            iterator start_pos = position;

            this->alloc.destroy(&(*position));
            while ((position + 1) != end) {
                this->alloc.construct(&(*position), *(position + 1));
                this->alloc.destroy(&(*position) + 1);
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
                this->alloc.destroy(&(*first));
                len++;
                first++;
            }

            while (first != end) {
                this->alloc.construct(&(*first) - len, *first);
                this->alloc.destroy(&(*first));
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
                reserve(this->vector_capacity == 0 ? 1 : this->vector_capacity * 2);
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

		size_type indexPos(iterator start, iterator end) {
		    size_type len = 0;

		    while (end-- != start) {
		        len++;
		    }
            return (len);
		}

	};


    template <class T, class Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        if (lhs.size() != rhs.size()) {
            return (false);
        }

        for (int i = 0; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i]) {
                return (false);
            }
        }
        return (true);
    }

    template<class T, class Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (!(lhs == rhs));
    }

    template<class T, class Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

        typename ft::vector<T>::iterator left = lhs.begin();
        typename ft::vector<T>::iterator right = rhs.begin();

        while (left != lhs.end()) {
            if (*left < *right) {
                return (true);
            }
            else if (*left == *right) {
                left++;
                right++;
            } else {
                return (false);
            }
        }
        return (right != rhs.end());
    }

    template<class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (!(rhs < lhs));
    }

    template<class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (rhs < lhs);
    }

    template<class T, class Alloc>
    bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return (!(lhs < rhs));
    }

    template<class T, class Alloc>
    void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {
        x.swap(y);
    }
}
#endif //VECTOR_HPP
