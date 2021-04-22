#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>


namespace ft {


	template <class T> class mapNode {

		template <class A, class B, class C, class D>
		friend class map;
		private:
//			typedef std::pair<const Key, T> value_type;
			typedef T value_type;
			bool isBlack;
			mapNode *left;
			mapNode *right;
			mapNode *parent;
			value_type data;

		public:
			mapNode(value_type &vt = value_type()):isBlack(false), left(NULL), right(NULL), parent(NULL), data(vt) {}


	};

	template <class T> class iteratorMap {
	protected:
		typedef T value_type;
		typedef mapNode<T> node;
		node *pointer;
	public:
//		template<typename myT, typename Alloc>
//		friend class list;

		iteratorMap(node *pointer = NULL): pointer(pointer) {}

		bool operator==(iteratorMap const &itL) {
			return (this->pointer == itL.pointer);
		}

		bool operator!=(iteratorMap const &itL) {
			return (!(*this == itL));
		}

		value_type& operator*() {
			return (this->pointer->data);
		}

		value_type* operator->() {
			return (&(this->pointer->data));
		}

		iteratorMap& operator++() { // ++it
			this->pointer = this->pointer->next;
			return (*this);
		}

		iteratorMap operator++(int) { // it++
			iteratorMap it(*this);
			this->pointer = this->pointer->next;
			return (it);
		}
		iteratorMap& operator--() { // --it
			this->pointer = this->pointer->prev;
			return (*this);
		}

		iteratorMap operator--(int) { // it--
			iteratorMap it(*this);
			this->pointer = this->pointer->prev;
			return (it);
		}
		iteratorMap& operator=(const iteratorMap &it) {
			this->pointer = it.pointer;
			return (*this);
		}
	};

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > > class map {
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef Compare key_compare;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef mapNode<value_type> node;
		typedef iteratorMap<value_type> iterator;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
		map_size = 0;
		initNodes();
	}

//	template <class InputIterator>
//	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
//
//	}

	map(const map& x) {

	}

	map& operator=(const map& x) {

	}

	~map() {
		this->clear();
	}

	iterator begin() {}
//	const_iterator begin() const {}

	iterator end() {}
//	const_iterator end() const {}

//	reverse_iterator rbegin() {}
//	const_reverse_iterator rbegin() const {}

//	reverse_iterator rend() {}
//	const_reverse_iterator rend() const {}

	bool empty() const {
		return (this->map_size == 0);
	}

	size_type size() const {
		return (this->map_size);
	}

	size_type max_size() const {
		return (std::numeric_limits<size_type>::max() / sizeof(value_type));
	}

	std::pair<iterator,bool> insert(const value_type& val) {

		// TODO - if found val - return false

		node *tmp = new node(val);
		fillNode(tmp);
		tmp->left = leaf;
		tmp->right = leaf;

		if (root->left == NULL) {
			root->left = tmp;
			return ;
		}

		node *current = this->root;
		while (current != tmp) {






		}




		this->map_size++;
//		return std::pair<iterator, >
	}

	iterator insert(iterator position, const value_type& val) {

	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last) {

	}


	void erase(iterator position) {

	}

	size_type erase(const key_type& k) {

	}

	void erase(iterator first, iterator last) {

	}

	void swap(map& x) {

	}

	void clear() {

	}

	key_compare key_comp() const {

	}

//	value_compare value_comp() const {}

	iterator find(const key_type& k) {

		if (this->map_size == 0) {
			return NULL; 	// TODO: Return end()
		}



//		while (cur != leaf) {
//
//		}


		return (0); // TODO: Return iterator
	}

//	const_iterator find(const key_type& k) const {}

	size_type count(const key_type& k) const {

	}

//	iterator lower_bound(const key_type& k) {}
//	const_iterator lower_bound(const key_type& k) const {}

//	iterator upper_bound(const key_type& k) {}
//	const_iterator upper_bound(const key_type& k) const {}


//	pair<const_iterator,const_iterator> equal_range(const key_type& k) const {}
//	pair<iterator,iterator> equal_range(const key_type& k) {}



	private:
		size_type map_size;
		node *root;
		node *leaf;
		node *max;
		node *min;

		void initNodes() {
			root = new node();
			fill_node(root);
			leaf = new node();
			fill_node(leaf);
			max = new node();
			fill_node(max);
			min = new node();
			fill_node(min);
//			root->parent = NULL;
//			root->left = NULL;
//			root->right = NULL;

		}

		void fill_node(node *n) {
			n->parent = NULL;
			n->left = NULL;
			n->right = NULL;
		}
};

	// map::key_type map::mapped_type map::key_compare map::allocator_type


}

#endif
