#ifndef LIST_HPP
# define LIST_HPP
# include <iostream>
# include <memory>
# include <cstddef>
# include <limits>


namespace ft {

	template< class T > class listNode {
		template < class A, class Alloc >
		friend class list;

		template <class A>
		friend class iteratorList;
	private:
		T data;
		listNode *next;
		listNode *prev;
	public:
		explicit listNode(T data = T(), listNode *next = NULL, listNode *prev = NULL):data(data),next(next), prev(prev) {}
	};

	template <class T> class iteratorList {
	private:
		listNode<T> *pointer;
	public:
		iteratorList(listNode<T> *pointer = NULL):pointer(pointer) {}
		bool operator==(iteratorList const &itL) {
			return (this->pointer == itL.pointer);
		}
		bool operator!=(iteratorList const &itL) {
			return (!(*this == itL));
		}
		T& operator*() {
			return (this->pointer->data);
		}
		T* operator->() {
			return (&(this->pointer->data));
		}
		iteratorList& operator++() { // ++it
			this->pointer = this->pointer->next;
			return (*this);
		}

		iteratorList operator++(int) { // it++
			iteratorList it(*this);
			this->pointer = this->pointer->next;
			return (it);
		}
		iteratorList& operator--() { // --it
			this->pointer = this->pointer->prev;
			return (*this);
		}

		iteratorList operator--(int) { // it--
			iteratorList it(*this);
			this->pointer = this->pointer->prev;
			return (it);
		}
	};

	template < class T, class Alloc = std::allocator<T> > class list {
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef ptrdiff_t difference_type;
		typedef listNode<T> node;
		typedef iteratorList<T> iterator;
		typedef size_t size_type;
//		typedef ptrdiff_t difference_type;

		list() {
			list_size = 0;
			head = new node();
			last = new node();
			last->prev = head;
			head->next = last;
		}

		// push back
		void push_back(const value_type &val) {
			// insert(end, val)
			node *myNode = new node(val);
			myNode->prev = last->prev;
			myNode->next = last;
			last->prev->next = myNode;
			last->prev = myNode;
			list_size++;
		}

		void pop_back() {
			node *preLast = last->prev;
			preLast->prev->next = last;
			last->prev = preLast->prev;
			list_size--;
			delete preLast;
		}

		void push_front(const value_type &val) {

		}

		void pop_front() {

		}

		void insert(iterator position, const value_type &val) {
			node *myNode = new node(val);
			node it = this->head;
			while (it != position)
				it++;

			myNode->next = it.next;
			myNode->prev = it.prev;
			myNode->prev->next = myNode;
			myNode->next->prev = myNode;
			list_size++;
		}

		iterator begin()
		{ return (iterator (this->head->next)); }

		iterator end()
		{ return (iterator (this->last)); }

		size_type max_size() const
		{ return (std::numeric_limits<size_type>::max() / sizeof(node)); }

		bool empty() const {
			return ((this->list_size == 0) ? true : false);
		}
		size_type size() const {
			return (this->list_size);
		}

		// push back
		// pop back
		// erase
		// insert
	private:
		listNode<T> *head;
		listNode<T> *last;
		size_type list_size;
	};
}

#endif
