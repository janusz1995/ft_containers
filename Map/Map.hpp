#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>


namespace ft {


	template <class T> class mapNode {

		template <class A, class B, class C, class D>
		friend class map;

		template <class A>
		friend class iteratorMap;
		private:
//			typedef std::pair<const Key, T> value_type;
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
        protected:
            typedef T value_type;
            typedef mapNode<T> node;
            node *pointer;
            node *leaf;
        public:
    //		template<typename myT, typename Alloc>
    //		friend class list;

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
                this->leaf = it.leaf;
                return (*this);
            }

	    private:
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

            node *tree_minimum(node *x) {
                while (x->left != this->leaf) {
                    x = x->left;
                }
                return (x);
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
            //  TODO - detele root, leaf
        }

        iterator begin() {
        	return (iterator(this->leaf->left, this->leaf));
        }
    //	const_iterator begin() const {}

        iterator end() {
			return (iterator(this->leaf));
        }
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

            if (this->root == this->leaf) {
                node *tmp = new node(val);
                fillNode(tmp, this->leaf);
                this->root = tmp;
                this->map_size++;
                // TODO find max and min
                return (std::pair<iterator,bool>(iterator(tmp), true));
            }

            node *current = this->root;
            while (current != this->leaf) {
                if (current->data.first == val.first) {
                	  return (std::pair<iterator,bool>(iterator(current), false));
                }

                if (this->comp(val.first, current->data.first)) {
					if (current->left == this->leaf) {
						break;
					}
                    current = current->left;
                } else {
                	if (current->right == this->leaf) {
						break;
                	}
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
            this->map_size++;

            return (std::pair<iterator,bool>(iterator(tmp), true));
        }

//        iterator insert(iterator position, const value_type& val) {
//
//        }

//        template <class InputIterator>
//        void insert(InputIterator first, InputIterator last) {
//
//        }


        void erase(iterator position) {

        }

        size_type erase(const key_type& k) {

        }

        void erase(iterator first, iterator last) {

        }

        void swap(map& x) {
			swap(this->root, x.root);
			swap(this->leaf, x.leaf);
			swap(this->map_size, x.map_size);
        }

        void clear() {
//        	iterator it = begin();
//			iterator save = it;
//
//			while (it != this->leaf) {
//				++it;
//				delete save;
//				this->map_size--;
//				save = it;
//			}

        }

		iterator getMax() {
			return (iterator(this->leaf->right));
        }

		iterator getMin() {
			return (iterator(this->leaf->left));
		}

        key_compare key_comp() const {
            return (key_compare());
        }

//    	value_compare value_comp() const {}

        iterator find(const key_type& k) {

            if (this->map_size == 0) {
                return (this->leaf); 	// TODO: Return end()
            }

            node *cur = this->root;

            while (cur != this->leaf && cur->data.first != k) {
                if (this->comp(cur->data.first, k)) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }

            if (cur == this->leaf) {
                return (this->leaf); // TODO - end
            }

            return (iterator(cur)); // TODO: Return iterator
        }

    //	const_iterator find(const key_type& k) const {}

        size_type count(const key_type& k) const {
            return 0;
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
            node *_end;
            node *max;
            node *min;
            key_compare comp;

            void initNodes() {

                leaf = new node();
                fillNode(leaf, NULL);
                max = new node();
                fillNode(max, NULL);
                min = new node();
                fillNode(min, NULL);
                _end = new node();
                fillNode(_end, NULL);
                this->root = this->leaf;
    //			root->parent = NULL;
    //			root->left = NULL;
    //			root->right = NULL;

            }

            void fillNode(node *n, node *leaf) {
                n->parent = leaf;
                n->left = leaf;
                n->right = leaf;
            }

			void findMinOrMax(bool isMin) {

				if (this->map_size == 0) {
					return;
				}

				node *current = this->root;

				while ((isMin ? current->left : current->right) != this->leaf) {
					current = isMin ? current->left : current->right;
				}

				(isMin ? this->leaf->left : this->leaf->right) = current;
			}

			template <typename TMP>
			void swap(TMP &one, TMP &two) {
				TMP tmp = one;
				one = two;
				two = tmp;
			}

//            void findMin() {
//
//                if (this->map_size == 0) {
//                    return;
//                }
//
//                node *current = this->root;
//
//                while (current->left != this->leaf) {
//                    current = current->left;
//                }
//
//                this->_end->left = current;
//            }

//            void findMax() {
//
//                if (this->map_size == 0) {
//                    return;
//                }
//
//                node *current = this->root;
//
//                while (current->right != this->leaf) {
//                    current = current->right;
//                }
//
//                this->_end->right = current;
//            }

    };

	// map::key_type map::mapped_type map::key_compare map::allocator_type


}

#endif
