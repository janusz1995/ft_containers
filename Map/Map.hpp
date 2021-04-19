#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>


namespace ft {



	template <class Key, class T> class mapNode {
		private:
			// color;
			// left; - mapMode
			// right; - mapMode
			// parent; - mapMode
			// Key
			// T
	};


	template <class T1, class T2> struct pair;

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> >> class map {
	public:
//		typedef pair<const Key, T> value_type;
		typedef Key key_type;
		typedef T mapped_type;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef Compare key_compare;
		typedef pair<const key_type, mapped_type> value_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {

	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {

	}

	map(const map& x) {

	}

	map& operator=(const map& x) {

	}

	~map() {

	}

//	iterator begin() {}
//	const_iterator begin() const {}

//	iterator end() {}
//	const_iterator end() const {}

//	reverse_iterator rbegin() {}
//	const_reverse_iterator rbegin() const {}

//	reverse_iterator rend() {}
//	const_reverse_iterator rend() const {}

	bool empty() const {

	}

	size_type size() const {

	}

	size_type max_size() const {

	}

//	pair<iterator,bool> insert(const value_type& val) {}
//	iterator insert(iterator position, const value_type& val);
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last) {

	}


//	void erase (iterator position);
	size_type erase(const key_type& k) {

	}
//	void erase (iterator first, iterator last) {}

	void swap(map& x) {

	}

	void clear() {

	}

	key_compare key_comp() const {

	}

//	value_compare value_comp() const {}

//	iterator find(const key_type& k) {}
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


};

	// map::key_type map::mapped_type map::key_compare map::allocator_type


}

#endif
