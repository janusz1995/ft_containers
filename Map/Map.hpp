#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>

namespace ft {

	template <class T> class mapNode {

		template <class A, class B, class C, class D>
		friend class map;

		template <class A>
		friend class iteratorMap;

        template <class A>
        friend class constIteratorMap;

        template <class A>
        friend class reverseIteratorMap;

        template <class A>
        friend class constReverseIteratorMap;

		private:
			typedef T value_type;
			bool isBlack;
			mapNode *left;
			mapNode *right;
			mapNode *parent;
			value_type data;

		public:
			mapNode(const value_type &vt = value_type()):isBlack(false), left(NULL), right(NULL), parent(NULL), data(vt) {}

	};

	template <class T> class iteratorMap {
        template <class A, class B, class C, class D>
        friend class map;
        protected:
            typedef T value_type;
            typedef mapNode<T> node;
            node *pointer;
            node *leaf;
        public:

            iteratorMap(node *pointer = NULL, node *leaf = NULL): pointer(pointer), leaf(leaf) {}

            bool operator==(iteratorMap const &itL) {
                return (this->pointer == itL.pointer); // TODO - add leaf ==
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
                this->pointer = tree_successor(this->pointer);
                return (*this);
            }

            iteratorMap operator++(int) { // it++
                iteratorMap it(*this);
				this->pointer = tree_successor(this->pointer);
                return (it);
            }

            iteratorMap& operator--() { // --it
                if (this->pointer == this->leaf)
                    this->pointer = this->leaf->right;
                else
                    this->pointer = tree_successor_back(this->pointer);
                return (*this);
            }

            iteratorMap operator--(int) { // it--
                iteratorMap it(*this);
                if (this->pointer == this->leaf)
                    this->pointer = this->leaf->right;
                else
                    this->pointer = tree_successor_back(this->pointer);
                return (it);
            }

            iteratorMap& operator=(const iteratorMap &it) {
                this->pointer = it.pointer;
                this->leaf = it.leaf;
                return (*this);
            }

        protected:
            node* tree_successor(node *n) {
                if (n->right != this->leaf) {
                    return (tree_minimum(n->right));
                }
                node *y = n->parent;
                while (y != this->leaf && n == y->right) {
                    n = y;
                    y = y->parent;
                }
                return (y);
            }

            node *tree_successor_back(node *n) {
                if (n->left != this->leaf) {
                    return (tree_maximim(n->left));
                }

                node *y = n->parent;
                while (y != this->leaf && n == y->left) {
                    n = y;
                    y = y->parent;
                }
                return (y);
            }

            node *tree_minimum(node *x) {
                while (x->left != this->leaf) {
                    x = x->left;
                }
                return (x);
            }

            node *tree_maximim(node *x) {
                while (x->right != this->leaf) {
                    x = x->right;
                }
                return (x);
            }
	};

	template <class T> class constIteratorMap : public iteratorMap<T> {
        typedef T value_type;
        typedef mapNode<T> node;
	public:
        constIteratorMap() {}
        constIteratorMap(node *pointer = NULL, node *leaf = NULL) {
            this->pointer = pointer;
            this->leaf = leaf;
        }

        constIteratorMap(iteratorMap<T> const &itConst): iteratorMap<T>(itConst) {}
        ~constIteratorMap() {}

        const value_type& operator*() {
            return (this->pointer->data);
        }

        const value_type* operator->() {
            return (&(this->pointer->data));
        }

        constIteratorMap& operator=(const iteratorMap<T> &it) {
            this->pointer = it.pointer;
            this->leaf = it.leaf;
            return (*this);
        }
	};

    template <class T> class reverseIteratorMap : public iteratorMap<T> {
        typedef T value_type;
        typedef mapNode<T> node;
    public:
        reverseIteratorMap() {}
        reverseIteratorMap(node *pointer = NULL, node *leaf = NULL) {
            this->pointer = pointer;
            this->leaf = leaf;
        }

        reverseIteratorMap(iteratorMap<T> const &itConst) : iteratorMap<T>(itConst) {}
        ~reverseIteratorMap() {}

        reverseIteratorMap& operator++() { // ++it
            this->pointer = this->tree_successor_back(this->pointer);
            return (*this);
        }

        reverseIteratorMap operator++(int) { // it++
            reverseIteratorMap it(*this);
            this->pointer = this->tree_successor_back(this->pointer);
            return (it);
        }

        reverseIteratorMap& operator--() { // --it
            if (this->pointer == this->leaf)
                this->pointer = this->leaf->left;
            else
                this->pointer = this->tree_successor(this->pointer);
            return (*this);
        }

        reverseIteratorMap operator--(int) { // it--
            reverseIteratorMap it(*this);
            if (this->pointer == this->leaf)
                this->pointer = this->leaf->left;
            else
                this->pointer = this->tree_successor(this->pointer);
            return (it);
        }

        reverseIteratorMap &operator=(const iteratorMap<T> &it) {
            this->pointer = it.pointer;
            this->leaf = it.leaf;
            return (*this);
        }
    };

    template <class T> class constReverseIteratorMap : public reverseIteratorMap<T> {
        typedef T value_type;
        typedef mapNode<T> node;
    public:
        constReverseIteratorMap() {}
        constReverseIteratorMap(node *pointer = NULL, node *leaf = NULL) {
            this->pointer = pointer;
            this->leaf = leaf;
        }

        constReverseIteratorMap(reverseIteratorMap<T> const &itConst) : reverseIteratorMap<T>(itConst) {}
        ~constReverseIteratorMap() {}

        const value_type& operator*() {
            return (this->pointer->data);
        }

        const value_type* operator->() {
            return (&(this->pointer->data));
        }

        constReverseIteratorMap &operator=(const reverseIteratorMap<T> &it) {
            this->pointer = it.pointer;
            this->leaf = it.leaf;
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
            class value_compare {
                protected:
                    Compare comp;
                    value_compare(Compare c) : comp(c) {}
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };
            typedef mapNode<value_type> node;
            typedef iteratorMap<value_type> iterator;
            typedef constIteratorMap<value_type> const_iterator;
            typedef reverseIteratorMap<value_type> reverse_iterator;
            typedef constReverseIteratorMap<value_type> const_reverse_iterator;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
            map_size = 0;
			leaf = new node();
			fillNode(leaf, NULL);
			this->leaf->isBlack = true;
			this->root = this->leaf;
            this->comp = comp;
            this->alloc = alloc;
        }

    	template <class InputIterator>
    	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
            typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {
            map_size = 0;
            this->leaf = new node();
            fillNode(leaf, NULL);
            this->leaf->isBlack = true;
            this->root = this->leaf;
            this->comp = comp;
            this->alloc = alloc;

            insert(first, last);
    	}

        map(const map& x) {
            map_size = 0;
            this->leaf = new node();
            fillNode(leaf, NULL);
            this->leaf->isBlack = true;
            this->root = this->leaf;
            this->comp = x.comp;
            this->alloc = x.alloc;

            insert(x.begin(), x.end());
        }

        map& operator=(const map& x) {
            clear();

            this->root = this->leaf;
            this->comp = x.comp;
            this->alloc = x.alloc;
            insert(x.begin(), x.end());
        }


        mapped_type& operator[](const key_type& k) {

            iterator it = find(k);
            if (it != end()) {
                return (it.pointer->data.second);
            }
            else {
                it = insert(begin(), std::make_pair(k, NULL));
                return (it.pointer->data.second);
            }
        }

        ~map() {
            this->clear();
            delete leaf;
        }

        iterator begin() {
        	return (iterator(this->leaf->left, this->leaf));
        }

    	const_iterator begin() const {
            return (const_iterator(this->leaf->left, this->leaf));
        }

        iterator end() {
			return (iterator(this->leaf, this->leaf));
        }

    	const_iterator end() const {
            return (const_iterator(this->leaf, this->leaf));
        }

    	reverse_iterator rbegin() {
            return (reverse_iterator(this->leaf->right, this->leaf));
        }

    	const_reverse_iterator rbegin() const {
            return (const_reverse_iterator(this->leaf->right, this->leaf));
        }

    	reverse_iterator rend() {
            return (reverse_iterator(this->leaf, this->leaf));
        }

    	const_reverse_iterator rend() const {
            return (const_reverse_iterator(this->leaf, this->leaf));
    	}

        bool empty() const {
            return (this->map_size == 0);
        }

        size_type size() const {
            return (this->map_size);
        }

        size_type max_size() const {
            return (std::numeric_limits<size_type>::max() / sizeof(node));
        }

        std::pair<iterator,bool> insert(const value_type& val) {

            if (this->root == this->leaf) {
                node *tmp = new node(val);
                fillNode(tmp, this->leaf);
                tmp->isBlack = false;
                this->root = tmp;
                this->map_size++;
                insertFix(tmp);
                findBeginAndEnd();
                return (std::pair<iterator,bool>(iterator(tmp, this->leaf), true));
            }

            node *current = this->root;
            while (current != this->leaf) {
                if (current->data.first == val.first) {
                	  return (std::pair<iterator,bool>(iterator(current, this->leaf), false));
                }

                if (this->comp(val.first, current->data.first)) {
					if (current->left == this->leaf)
						break;
                    current = current->left;
                } else {
                	if (current->right == this->leaf)
						break;
                    current = current->right;
                }
            }

            node *tmp = new node(val);
            fillNode(tmp, this->leaf);

            if (this->comp(current->data.first, val.first)) {
                current->right = tmp;
				findMinOrMax(false);
            } else {
                current->left = tmp;
				findMinOrMax(true);
            }

            tmp->parent = current;
            tmp->isBlack = false;
            this->map_size++;
			insertFix(tmp);

            return (std::pair<iterator,bool>(iterator(tmp, this->leaf), true));
        }

        iterator insert(iterator position, const value_type& val) {
        	static_cast<void>(position);
        	std::pair<iterator,bool> it = insert(val);
        	return (it.first);
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last,
				typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) {

			iterator it = first;

			while (it != last) {
				insert(it.pointer->data);
				++it;
			}
        }

        size_type erase(const key_type& k) {

            size_type count = 0;

            iterator it = this->find(k);

            while (it != this->end()) {
                erase(it);
                count++;
                it = this->find(k);
            }

            return (count);
        }

        void erase(iterator position) {
			if (this->map_size == 0) {
				return ;
			}

			iterator cur = begin();

			while (cur != position) {
				++cur;
			}

			node *node_delete = cur.pointer;
            deleteElem(node_delete);
			delete node_delete;
			this->map_size--;
			findBeginAndEnd();
        }

        void erase(iterator first, iterator last) {
            iterator it = this->begin();

            while (it != this->end()) {
            	if (it == first)
					break;
                it++;
            }

            iterator nextIt = it;
            if (it == this->end())
                return ;

            while (it != last) {
                ++nextIt;
                this->erase(it);
                it = nextIt;
            }
        }

        void swap(map& x) {
			swap(this->root, x.root);
			swap(this->leaf, x.leaf);
			swap(this->map_size, x.map_size);
			swap(this->alloc, x.alloc);
			swap(this->comp, x.comp);
        }

        void clear() {
        	node *cur_delete;

        	if (this->map_size == 0) {
				return ;
        	}

			while (this->root->left != this->leaf || this->root->right != this->leaf) {
				cur_delete = findDeleteElement();

				(cur_delete->parent->left == cur_delete ? cur_delete->parent->left : cur_delete->parent->right) = this->leaf;

				delete cur_delete;
				this->map_size--;
			}

			delete this->root;
			this->root = this->leaf;
			this->map_size--;
			findBeginAndEnd();
        }

        key_compare key_comp() const {
            return (key_compare());
        }

    	value_compare value_comp() const {
            return (value_compare(comp));
        }

        iterator find(const key_type& k) {

            node *cur = this->root;

            while (cur != this->leaf && cur->data.first != k) {
                if (this->comp(cur->data.first, k)) {
                    cur = cur->right;
                } else {
                    cur = cur->left;
                }
            }

            return (iterator(cur, this->leaf));
        }

    	const_iterator find(const key_type& k) const {
            node *cur = this->root;

            while (cur != this->leaf && cur->data.first != k) {
                if (this->comp(cur->data.first, k)) {
                    cur = cur->right;
                } else {
                    cur = cur->left;
                }
            }

            return (const_iterator(cur, this->leaf));
        }


        size_type count(const key_type& k) const {

            node *cur = this->root;

            while (cur != this->leaf && cur->data.first != k) {
                if (this->comp(cur->data.first, k)) {
                    cur = cur->right;
                } else {
                    cur = cur->left;
                }
            }
            return (cur == this->leaf ? 0 : 1);
        }

    	iterator lower_bound(const key_type& k) {
        	iterator it = this->begin();

        	while (it != this->end()) {
        		if (!comp(it.pointer->data.first, k))
					break;
        		++it;
        	}
        	return (it);
        }

    	const_iterator lower_bound(const key_type& k) const {
            const_iterator it = this->begin();

            while (it != this->end()) {
                if (!comp(it.pointer->data.first, k))
                    break;
                ++it;
            }
            return (it);
    	}

    	iterator upper_bound(const key_type& k) {
			iterator it = this->begin();

			while (it != this->end()) {
				if (!comp(it.pointer->data.first, k))
					break;
				++it;
			}
			return (++it);
        }

    	const_iterator upper_bound(const key_type& k) const {
            const_iterator it = this->begin();

            while (it != this->end()) {
                if (!comp(it.pointer->data.first, k))
                    break;
                ++it;
            }
            return (++it);
        }

    	std::pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
            const_iterator lower = lower_bound(k);
            const_iterator upper = upper_bound(k);

            return (std::pair<const_iterator, const_iterator>(lower, upper));
        }

    	std::pair<iterator,iterator> equal_range(const key_type& k) {

        	iterator lower = lower_bound(k);
        	iterator upper = upper_bound(k);

        	return (std::pair<iterator, iterator>(lower, upper));
        }

        private:
            size_type map_size;
            node *root;
            node *leaf;
            key_compare comp;
            allocator_type alloc;

            void fillNode(node *n, node *leaf) {
                n->parent = leaf;
                n->left = leaf;
                n->right = leaf;
            }

			void findMinOrMax(bool isMin) {

				if (this->map_size == 0) {
				    this->leaf->left = this->root;
				    this->leaf->right = this->root;
					return;
				}

				node *current = this->root;

				while ((isMin ? current->left : current->right) != this->leaf) {
					current = isMin ? current->left : current->right;
				}

				(isMin ? this->leaf->left : this->leaf->right) = current;
			}

			node *findDeleteElement() {
            	node *current = this->root;

            	while (current->left != this->leaf || current->right != this->leaf) {
            		if (current->left != this->leaf) {
						current = current->left;
            		} else {
						current = current->right;
            		}
            	}
            	return (current);
            }

        	void insertFix(node *z) {

				node *y;

            	while (z->parent->isBlack == false) {

            		if (z->parent == z->parent->parent->left) {
						y = z->parent->parent->right;

						if (y->isBlack == false) {
							z->parent->isBlack = true;
							y->isBlack = true;
							z->parent->parent->isBlack = false;
							z = z->parent->parent;
						}
						else {
							if (z == z->parent->right) {
								z = z->parent;
								leftRotate(z);
							}
							z->parent->isBlack = true;
							z->parent->parent->isBlack = false;
							rightRotate(z->parent->parent);
						}
            		}
            		else {
						y = z->parent->parent->left;

						if (y->isBlack == false) {
							z->parent->isBlack = true;
							y->isBlack = true;
							z->parent->parent->isBlack = false;
							z = z->parent->parent;
						}
						else {
							if (z == z->parent->left) {
								z = z->parent;
								rightRotate(z);
							}
							z->parent->isBlack = true;
							z->parent->parent->isBlack = false;
							leftRotate(z->parent->parent);
						}
            		}
            	}
            	this->root->isBlack = true;
            }

			void leftRotate(node *x) {
				node *y = x->right;

				x->right = y->left;
				if (y->left != this->leaf)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == this->leaf)
					this->root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
            }

			void rightRotate(node *x) {
				node *y = x->left;

				x->left = y->right;
				if (y->right != this->leaf)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == this->leaf)
					this->root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
            }

			node *minimum(node *cur) {
            	while (cur->left != this->leaf)
            		cur = cur->left;
				return cur;
            }

        	void deleteElem(node *z) {
				node *y = z;
				node *x;
				bool y_original_color = y->isBlack;

				if (z->left == this->leaf) {
					x = z->right;
					transplant(z, z->right);
				} else if (z->right == this->leaf) {
					x = z->left;
					transplant(z, z->left);
				}
				else {
					y = minimum(z->right);
					y_original_color = y->isBlack;
					x = y->right;
					if (y->parent == z) {
						x->parent = y;
					} else {
						transplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->isBlack = z->isBlack;
				}

				if (y_original_color)
					 deleteFix(x);
			}

			void transplant(node *u, node *v) {
				if (u->parent == this->leaf)
					this->root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;

				v->parent = u->parent;
            }

            void deleteFix(node *x) {
				node *w;

            	while (x != this->root && x->isBlack == true) {

            		if (x == x->parent->left) {
            			w = x->parent->right;
            			if (w->isBlack == false) {
							w->isBlack = true;
							x->parent->isBlack = false;
							leftRotate(x->parent);
							w = x->parent->right;
            			}
            			if (w->left->isBlack == true && w->right->isBlack == true) {
							w->isBlack = false;
							x = x->parent;
            			}
            			else {
							if (w->right->isBlack == true) {
								w->left->isBlack = true;
								rightRotate(w);
								w->isBlack = false;
							}
							w->isBlack = x->parent->isBlack;
							x->parent->isBlack = true;
							w->right->isBlack = true;
							leftRotate(x->parent);
							x = this->root;
            			}
            		} else {

						w = x->parent->left;
						if (w->isBlack == false) {
							w->isBlack = true;
							w->parent->isBlack = false;
							rightRotate(x->parent);
							w = x->parent->left;
						}
						if (w->right->isBlack == true && w->left->isBlack == true) {
							w->isBlack = false;
							x = x->parent;
						}
						else {
							if (w->left->isBlack == true) {
								w->right->isBlack = true;
								w->isBlack = false;
								leftRotate(w);
								w = x->parent->left;
							}
							w->isBlack = x->parent->isBlack;
							x->parent->isBlack = true;
							w->left->isBlack = true;
							rightRotate(x->parent);
							x = this->root;
						}
            		}
            	}
				x->isBlack = true;
            }

            void findBeginAndEnd() {
                findMinOrMax(false);
                findMinOrMax(true);
            }

			template <typename TMP>
			void swap(TMP &one, TMP &two) {
				TMP tmp = one;
				one = two;
				two = tmp;
			}

    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
        if (lhs.size() != rhs.size()) {
            return (false);
        }

        typename ft::map<Key, T, Compare, Alloc >::iterator itL = lhs.begin();
        typename ft::map<Key, T, Compare, Alloc >::iterator itR = rhs.begin();

        while (itL != lhs.end() && itR != rhs.end() && *itL == *itR) {
            ++itL;
            ++itR;
        }

        if (itR == rhs.end() && itL == lhs.end())
            return (true);
        return (false);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
        return (!(lhs==rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
        return (rhs > lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
        return (lhs < rhs || lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
        if (lhs.size() > rhs.size()) {
            return (true);
        }
        if (lhs.size() < rhs.size()) {
            return (false);
        }

        typename ft::map<Key, T, Compare, Alloc >::iterator itL = lhs.begin();
        typename ft::map<Key, T, Compare, Alloc >::iterator itR = rhs.begin();

        while (itL != lhs.end() && itR != rhs.end() && *itL == *itR) {
            ++itL;
            ++itR;
        }

        if ((itR == rhs.end() && itL == lhs.end()) || itL == lhs.end() || *itR <= *itR)
            return (false);
        return (true);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
        return (lhs > rhs || lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    void swap(map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
        x.swap(y);
    }

}

#endif
