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

		template <class A>
		friend class reverseIteratorList;

		template <class A>
		friend class constIteratorList;

		template <class A>
		friend class constReverseIteratorList;

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

		iteratorList(listNode<T> *pointer = NULL): pointer(pointer) {}

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
		constIteratorList() {}
		constIteratorList(listNode<T> *pointer) {
			this->pointer = pointer;
		}
		constIteratorList(iteratorList<T> const &itConst): iteratorList<T>(itConst) {}
		~constIteratorList() {}

		const T& operator*() {
			return (this->pointer->data);
		}

		const T* operator->() {
			return (&(this->pointer->data));
		}

		constIteratorList& operator=(const iteratorList<T> &it) {
			this->pointer = it.pointer;
			return (*this);
		}
	};

	template <class T> class reverseIteratorList : public iteratorList<T> {
	public:

		reverseIteratorList() {}
		reverseIteratorList(listNode<T> *pointer) {
			this->pointer = pointer;
		}
		reverseIteratorList(reverseIteratorList const &itReverse) {
			*this = itReverse;
		}
		~reverseIteratorList() {}

		reverseIteratorList& operator++() { // ++it
			this->pointer = this->pointer->prev;
			return (*this);
		}

		reverseIteratorList operator++(int) { // it++
			reverseIteratorList it(*this);
			this->pointer = this->pointer->prev;
			return (it);
		}
		reverseIteratorList& operator--() { // --it
			this->pointer = this->pointer->next;
			return (*this);
		}

		reverseIteratorList operator--(int) { // it--
			reverseIteratorList it(*this);
			this->pointer = this->pointer->next;
			return (it);
		}
		reverseIteratorList& operator=(const reverseIteratorList &it) {
			this->pointer = it.pointer;
			return (*this);
		}
	};

	template <class T> class constReverseIteratorList : public reverseIteratorList<T> {
	public:

		constReverseIteratorList() {}
		constReverseIteratorList(listNode<T> *pointer) {
			this->pointer = pointer;
		}
		constReverseIteratorList(reverseIteratorList<T> const &itConst): reverseIteratorList<T>(itConst) {
//			this->pointer = itConst.pointer;
		}
		~constReverseIteratorList() {}

		const T& operator*() {
			return (this->pointer->data);
		}

		const T* operator->() {
			return (&(this->pointer->data));
		}

		constReverseIteratorList& operator=(const reverseIteratorList<T> &it) {
			this->pointer = it.pointer;
			return (*this);
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
		typedef constIteratorList<T> const_iterator;
		typedef reverseIteratorList<T> reverse_iterator;
		typedef constReverseIteratorList<T> const_reverse_iterator;
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
			head = new node();
			last = new node();
			last->prev = head;
			head->next = last;
			list_size = 0;
			for (int i = 0; i < n; ++i) {
				push_back(val);
			}
		}

		explicit list(const list& x) {
			list_size = 0;
			head = new node();
			last = new node();
			last->prev = head;
			head->next = last;
			assign(x.begin(), x.end());
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {
			list_size = 0;
			head = new node();
			this->last = new node();
			this->last->prev = head;
			head->next = this->last;
			assign(first, last);
		}

		list& operator=(list const &x) {
			if (&x != this) {
				clear();
				delete head;
				delete last;
				head = new node();
				last = new node();
				last->prev = head;
				head->next = last;
				assign(x.begin(), x.end());
			}
			return (*this);
		}

		~list() {
			this->clear();
			delete head;
			delete last;
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
			  typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {
			this->clear();
			insert(this->begin(), first, last);
		}

		void assign(size_type n, const value_type& val) {
			this->clear();
			insert(this->begin(), n, val);
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

		value_type& front() {
			return (this->head->next->data);
		}

		const value_type& front() const {
			return (this->head->next->data);
		}

		value_type& back() {
			return (this->last->prev->data);
		}

		const value_type& back() const {
			return (this->last->prev->data);
		}

		iterator insert(iterator position, const value_type &val) {
			node *myNode = new node(val);
			node *it = position.pointer;

			it->prev->next = myNode;
			myNode->prev = it->prev;
			myNode->next = it;
			it->prev = myNode;
			list_size++;
			return (myNode);
		}

		void insert(iterator position, size_type n, const value_type& val) {
			for (int i = 0; i < n; ++i) {
			 	position = ++insert(position, val);
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

			if (&x == this) { return; }
			iterator a = this->begin();
			iterator b = x.begin();
			iterator next;

			while (b != x.end()) {
				if (*a > *b) {
					next = ++b;
					this->splice(a, x, --b);
					b = next;
				}
				else if (++a == this->last) { break; }
			}
			while (b != x.end()) {
				next = ++b;
				splice(a, x, --b);
				b = next;
			}
		}

		template <class Compare>
		void merge(list& x, Compare comp) {

			if (&x == this) { return; }
			iterator a = this->begin();
			iterator b = x.begin();
			iterator next;

			while (b != x.end()) {
				if (comp(*b, *a)) {
					next = ++b;
					this->splice(a, x, --b);
					b = next;
				}
				else if (++a == this->last) { break; }
			}
			while (b != x.end()) {
				next = ++b;
				splice(a, x, --b);
				b = next;
			}
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

		const_iterator begin() const {
			return (const_iterator (this->head->next));
		}

		iterator end() {
			return (iterator (this->last));
		}

		const_iterator end() const {
			return (const_iterator (this->last));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator (this->last->prev));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator (this->last->prev));
		}

		reverse_iterator rend() {
			return (reverse_iterator (this->head));
		}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator (this->head));
		}

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


//		node* partition(node *left, node *right) {
//			node *i = left->prev;
//
//			node *start_left = left;
//			while (start_left != right) {
//				if (start_left->data <= right->data) {
//					i = (i == this->last) ? left : i->next;
////					node *tmp = start_left->next;
////					swapNode(i, start_left);
////					start_left = tmp->prev;
////					swap(i, start_left);
////					start_left = i;
//					swap(i->data, start_left->data);
////					start_left = i;
//				}
//				start_left = start_left->next;
//			}
//			i = (i == this->last) ? left : i->next;
//
//			swap(i->data, right->data);
////			node *tmp1 = i->next;
////			swapNode(i, right);
////			i = tmp1->prev;
////			swap(i, right);
////			i = right;
//			return i;
//		}
//
//		void quickSort(node *left, node *right) {
////			std::cout << "Sort doing :)\n";
//			if (right != this->last && left != right && left != right->next) {
//				node *p = partition(left, right);
//				quickSort(left, p->prev);
//				quickSort(p->next, right);
//			}
//		}
//
////		template <class B>
//		void sort() {
//			node *p1 = partition(head->next, this->last->prev);
//
//			node *p2 = partition(head->next, this->last->prev);
//
////			for (node *it = this->head->next; it != this->last; it = it->next) {
////				std::cout << it->data << " ";
////			}
//
////			std::cout << "\n p1 = " << p1->data << "; p2 = " << p2->data << std::endl;
//			quickSort(p2->next, this->last->prev);
//			quickSort(p1->next, p2->prev);
//			quickSort(this->head->next, p1->prev);
////			quickSort(this->head->next, this->last->prev);
//
//		}

		node* partition(node *left, node *right) {
			node *i = left->prev;

			node *start_left = left;
			while (start_left != right) {
				if (start_left->data <= right->data) {
					i = (i == this->last) ? left : i->next;
//					iterator a = begin();
//					a.pointer.
					node *tmp = start_left->next;
					swapNode(i, start_left);
					start_left = tmp->prev;

//					swap(i->data, start_left->data);
				}
				start_left = start_left->next;
			}
			i = (i == this->last) ? left : i->next;
			node *tmp = i->next;
			swapNode(i, right);
			i = tmp->prev;
//			swap(i->data, right->data);
			return i;
		}

		void quickSort(node *left, node *right) {
//			std::cout << "Sort doing :)\n";
			if (right != NULL && left != right && left != right->next)
			{
//				node *p1 = partition(left, );
				// PARTITION(left, p1.prev)и PARTITION(p2.next, right
//				int p = partition(A, l, h); /* Partitioning index */
//				quickSort(A, l, p - 1);
//				quickSort(A, p + 1, h);
//				node *p1 = ;
				node *p = partition(left, right);
				quickSort(left, p->prev);
				quickSort(p->next, right);
//				node *p = partition(left, right);
//				quickSort(left, p->prev);
//				quickSort(p->next, right);
			}
		}

//		template <class B>
		void sort() {


			node *p1 = partition(head->next, this->last->prev);

			node *p2 = partition(head->next, this->last->prev);

//			std::cout << " p1 = " << p1->data << "; p2 = " << p2->data << std::endl;
			quickSort(p2->next, this->last->prev);
			quickSort(p1->next, p2->prev);
			quickSort(this->head->next, p1->prev);
//			quickSort(left, right);

//			quickSort(head->next, last->prev);
		}

		template <class Compare>
		void sort(Compare comp) {

		}

		void splice(iterator position, list& x) {
			this->splice(position, x, x.begin(), x.end());
		}

		void splice(iterator position, list& x, iterator i) {
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
			while (firstNode != pos) {
				this->list_size++;
				x.list_size--;
				firstNode = firstNode->next;
			}
		}


		void swap(list& x) {
			swap(this->list_size, x.list_size);
			swap(this->head, x.head);
			swap(this->last, x.last);
		}

		void unique() {
			if (this->list_size < 2) {
				return;
			}

			iterator first = begin();
			iterator nextFirst = ++begin();
			while (nextFirst != last) {
				if (*first == *nextFirst) {
					nextFirst = erase(nextFirst);
				} else {
					first++;
					nextFirst++;
				}
			}
		}

		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred) {

			if (this->list_size < 2) {
				return;
			}

			iterator first = begin();
			iterator nextFirst = ++begin();
//			node *first = head->next;
//			node *nextFirst = first->next;
			while (nextFirst != last) {
				if (binary_pred(*first, *nextFirst)) {
					nextFirst = erase(nextFirst);
				} else {
					first++;
					nextFirst++;
				}
			}
		}

		// |a|b|c|d|e|f|f|

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

		void swapNode(node *first, node *second) {

			node *saveFirstNext = first->next;
			node *saveFirstPrev = first->prev;

			first->next = second->next;
			second->next->prev = first;
			first->prev = second->prev;
			second->prev->next = first;

			second->next = saveFirstNext;
			saveFirstNext->prev = second;
			second->prev = saveFirstPrev;
			saveFirstPrev->next = second;
//			swap(first->data, second->data);
//			swap(first->next->prev, second->next->prev);
//			swap(first->prev->next, second->prev->next);
//			swap(first->next, second->next);
//			swap(first->prev, second->prev);
		}

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


		bool are_they_neighbours(node* A,node* B) {
			return ((A->next == B && B->prev == A) || (A->prev == B && B->next == A));
		}

		void refresh_outer_pointers(node* A) {
			A->prev->next = A;
			A->next->prev = A;
		}

		void swap_node(node* A, node* B) {
			node* swapper[4];
			node* tmp;

			if (A == B) {
				return ;
			}
			if (B->next == A) {
				tmp = A;
				A = B;
				B = tmp;
			}
			swapper[0] = A->prev;
			swapper[1] = B->prev;
			swapper[2] = A->next;
			swapper[3] = B->next;
			if (are_they_neighbours(A,B)) {
				A->prev = swapper[2];
				B->prev = swapper[0];
				A->next = swapper[3];
				B->next = swapper[1];
			} else {
				A->prev = swapper[1];
				B->prev = swapper[0];
				A->next = swapper[3];
				B->next = swapper[2];
			}
			refresh_outer_pointers(A);
			refresh_outer_pointers(B);
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

	template <class T, class Alloc>
	bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		iteratorList<T> itList1 = lhs.begin();
		iteratorList<T> itList2 = rhs.begin();
		if (lhs.size() == rhs.size()) {
			while (itList1 != lhs.end()) {
				if (*itList1 != *itList2) {
					return (false);
				}
				++itList1;
				++itList2;
			}
			return (true);
		}
		return (false);
	}

	template <class T, class Alloc>
	bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		iteratorList<T> itList1 = lhs.begin();
		iteratorList<T> itList2 = rhs.begin();
		while (itList1 != lhs.end()) {
			if (*itList1 < *itList2) {
				return (true);
			}
			else if (*itList1 == *itList2) {
				++itList1;
				++itList2;
			} else {
				return (false);
			}
		}
		if (itList2 != rhs.end())
			return (true);
		else
			return (false);
	}

	template <class T, class Alloc>
	bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(list<T,Alloc>& x, list<T,Alloc>& y) {
		x.swap(y);
	}

}


#endif
