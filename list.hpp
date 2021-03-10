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

		list& operator=(list const &List) {
			if (&List != this) {
				this->head = List.head;
				this->last = List.last;
				this->list_size = List.list_size;
			}
			return (*this);
		}

		~list() {
			delete head;
			delete last;
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {

		}

		void assign (size_type n, const value_type& val) {

		}

		void push_back(const value_type &val) {
			 insert(last, val);
		}

		void pop_back() {
			erase(last->prev);
//			node *preLast = last->prev;
//			preLast->prev->next = last;
//			last->prev = preLast->prev;
//			list_size--;
//			delete preLast;
		}

		void push_front(const value_type &val) {
			insert(this->head->next, val);
		}

		void pop_front() {
			erase(head->next);
		}

		reference back() {
			return (this->last->prev);
		}

//		const_reference back() const {
//
//		}

		void insert(iterator position, const value_type &val) {
			node *myNode = new node(val);
			node *it = position.pointer;

			it->prev->next = myNode;
			myNode->prev = it->prev;
			myNode->next = it;
			it->prev = myNode;
			list_size++;
		}
		void insert(iterator position, size_type n, const value_type& val) {
			for (int i = 0; i < n; ++i) {
				insert(position, val);
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {

		}

		void merge(list &x) {
			this->last->prev = x.head->next;
			this->last = x.last;
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
			iterator it = this->begin();
			iterator save = it;
			while (it != this->end())
			{
				++it;
				if (val == *save)
					erase(save);
				save = it;
			}
		}

		template <class Predicate>
		void remove_if(Predicate pred) {

		}

		void clear() {
			erase(head->next, last);
		}

		iterator begin()
		{ return (iterator (this->head->next)); }

//		const_iterator begin() const {}

		iterator end()
		{ return (iterator (this->last)); }

//		const_iterator end() const {
//
//		}

//		reverse_iterator rbegin() {}
//		const_reverse_iterator rbegin() const {}

//		reverse_iterator rend() {}
//		const_reverse_iterator rend() const {}

		void resize(size_type n, value_type val = value_type()) {

		}

		void reverse() {

		}

		void sort() {

		}

		template <class Compare>
		void sort(Compare comp) {

		}

		void splice(iterator position, list& x) {

		}

		void splice(iterator position, list& x, iterator i) {

		}

		void splice(iterator position, list& x, iterator first, iterator last) {

		}

		void swap (list& x) {

		}

		void unique() {

		}

		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred) {

		}

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
