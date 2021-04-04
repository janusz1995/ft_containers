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
		explicit listNode(T data = T(), listNode *next = NULL, listNode *prev = NULL):data(data), next(next), prev(prev) {}
	};

	template <class T> class iteratorList {
	protected:
		listNode<T> *pointer;
	public:
		template<typename myT, typename Alloc>
		friend class list;
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
		iteratorList& operator=(const iteratorList &it) {
			this->pointer = it.pointer;
			return (*this);
		}
	};

	template <class T> class constIteratorList : public iteratorList<T> {
	public:
		constIteratorList(): iteratorList<T>() {}

	};

	template < class T, class Alloc = std::allocator<T> > class list {
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef ptrdiff_t difference_type;
		typedef listNode<T> node;
		typedef iteratorList<T> iterator;
//		typedef iterator reverse_iterator;
//		typedef const iterator const_iterator;
		typedef size_t size_type;
//		typedef ptrdiff_t difference_type;

		explicit list(const allocator_type& alloc = allocator_type()) {
			list_size = 0;
			head = new node();
			last = new node();
			last->prev = head;
			head->next = last;
		}

		explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
			// TODO allocate memory for head and last, next step - add N elements in list
			head = new node();
			last = new node();
			last->prev = head;
			head->next = last;
			list_size = 0;
			for (int i = 0; i < n; ++i) {
				this->push_back(val);
			}
		}

		list& operator=(list const &List) {
			// TODO allocate memory for head and last elements, next step - copy all elements (allocate memory too)
			if (&List != this) {
				head = new node();
				last = new node();
//				this->head = List.head;
//				this->last = List.last;
//				this->list_size = List.list_size;
			}
			return (*this);
		}

		~list() {
			this->clear();
			delete head;
			delete last;
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last) {
			this->clear();
			insert(begin(), first, last);
		}

		void assign(size_type n, const value_type& val) {
			this->clear();
			insert(begin(), n, val);
		}

		void push_back(const value_type &val) {
			 insert(last, val);
		}

		void pop_back() {
			erase(last->prev);
		}

		void push_front(const value_type &val) {
			insert(this->head->next, val);
		}

		void pop_front() {
			erase(head->next);
		}

//		reference back() {
//			return (this->last->prev);
//		}

//		const_reference back() const {
//
//		}

		iterator insert(iterator position, const value_type &val) {
			node *myNode = new node(val);
			node *it = position.pointer;

			it->prev->next = myNode;
			myNode->prev = it->prev;
			myNode->next = it;
			it->prev = myNode;
			list_size++;
			return (myNode); // TODO need check valid iterator
		}

		void insert(iterator position, size_type n, const value_type& val) {
			for (int i = 0; i < n; ++i) {
			 	position = ++insert(position, val); // TODO increase iterator
			}
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
			  typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {

			for (; first != last; first++) {
				insert(position, *first);
			}
		}

		void merge(list &x) {

			node *it = this->head->next;
			node *itX = x.head->next;
			node *save;

			while (itX != x.last) {
				if (it->data > itX->data) {
					save = itX->next;
					insert(it, itX);
					this->list_size++;
					x.list_size--;
					itX = save;
				} else {
					it = it->next;
					if (it == this->last)
						break;
				}
			}
			while (itX != x.last) {
				save = itX->next;
				insert(it, itX);
				this->list_size++;
				x.list_size--;
				itX = save;
			}
			x.head->next = x.last;
			x.last->prev = x.head;
		}

		template <class Compare>
		void merge(list& x, Compare comp) {

		}

		iterator erase(iterator position) {
			node *save = position.pointer;
			node *ret = save->next;

			save->prev->next = save->next;
			save->next->prev = save->prev;
			delete save;
			list_size--;
			return (ret);
		}

		iterator erase(iterator first, iterator last) {
			node *tmp = first.pointer;

			while (tmp != last.pointer) {
				tmp = erase(tmp).pointer;
			}
			return (tmp);
		}

		void remove(const value_type& val) {
			remove_if(equals(val));
		}

		template <class Predicate>
		void remove_if(Predicate pred) {
			iterator it = this->begin();
			iterator save = it;
			while (it != this->end())
			{
				++it;
				if (pred(*save))
					erase(save);
				save = it;
			}
		}

		void clear() {
			erase(head->next, last);
		}

		iterator begin() {
			return (iterator (this->head->next));
		}

//		const_iterator begin() const {
//			return (const_iterator (this->head->next));
//		}

		iterator end() {
			return (iterator (this->last));
		}

//		const_iterator end() const {
//			return (const_iterator (this->last));
//		}

//		reverse_iterator rbegin() {
//			return (reverse_iterator (this->last->next));
//		}

//		const_reverse_iterator rbegin() const {}

//		reverse_iterator rend() {
//			return (reverse_iterator (this->head));
//		}
//		const_reverse_iterator rend() const {}

		void resize(size_type n, value_type val = value_type()) {
			iterator it = this->begin();
			if (n < this->list_size) {
				for (int i = 0; i < n; ++i) {
					it++;
				}
				erase(it, last);
			} else if (n > this->list_size) {
				for (int i = this->list_size; i < n; ++i) {
					push_back(val);
				}
			}
		}

		void reverse() {

			if (this->list_size < 2) {
				return;
			}

			last = head;
			while(42) {
				swap(head->prev, head->next);
				node *prev = head->prev;
				if (prev == nullptr)
					break;
				head = prev;
			}
		}

		void sort() {

		}

		template <class Compare>
		void sort(Compare comp) {

		}

		void splice(iterator position, list& x) {
			this->list_size += x.list_size;
			x.list_size = 0;
			this->splice(position, x, x.begin(), x.end());
		}

		void splice(iterator position, list& x, iterator i) {
			this->list_size++;
			x.list_size--;
			this->splice(position, x, i, ++i);

		}

		void splice(iterator position, list& x, iterator first, iterator last) {
			node *pos = position.pointer;

			node *firstNode = first.pointer;
			node *lastNode = last.pointer;
			node *savePrevLastNode = lastNode->prev;

			firstNode->prev->next = lastNode;
			lastNode->prev = firstNode->prev;

			pos->prev->next = firstNode;
			firstNode->prev = pos->prev;
			pos->prev = savePrevLastNode;
			savePrevLastNode->next = pos;
		}


		void swap(list& x) {
			swap(this->list_size, x.list_size);
			swap(this->head, x.head);
			swap(this->last, x.last);
		}

		void unique() {

		}

		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred) {

		}

		size_type max_size() const {
			return (std::numeric_limits<size_type>::max() / sizeof(node));
		}

		bool empty() const {
			return (this->list_size == 0);
		}

		size_type size() const {
			return (this->list_size);
		}

	private:
		listNode<T> *head;
		listNode<T> *last;
		size_type list_size;

		struct equals {
			equals(T val):tmp(val) {}
			bool operator()(T y) const { return tmp == y;}
		private:
			T tmp;
		};


		template <typename TMP>
		void swap(TMP &one, TMP &two) {
			TMP tmp = one;
			one = two;
			two = tmp;
		}

		void insert(iterator position, iterator second) {
			node *itPos = position.pointer;
			node *itSecond = second.pointer;
			itSecond->prev->next = itSecond->next;
			itSecond->next->prev = itSecond->prev;

			itPos->prev->next = itSecond;
			itSecond->prev = itPos->prev;
			itSecond->next = itPos;
			itPos->prev = itSecond;

		}

//		void insert(iterator position, iterator second) {
//			node *itFirst = position.pointer;
//			node *itSecond = second.pointer;
//
//			itSecond->prev = itFirst->prev;
//			itSecond->next = itFirst;
//			itFirst->prev->next = itSecond;
//			itFirst->prev = itSecond;
//		}
	};
}

#endif
