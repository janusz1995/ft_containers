#ifndef STACK_HPP
#define STACK_HPP
#include "../List/list.hpp"

namespace ft {

    template<class T, class Container = ft::list<T> > class stack {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

        explicit stack(const container_type& ctnr = container_type()):container(ctnr) {}

        bool empty() const {
            return (this->container.empty());
        }

        size_type size() const {
            return (this->container.size());
        }

        value_type& top() {
            return (this->container.front());
        }

        const value_type& top() const {
            return (this->container.front());
        }

        void push(const value_type& val) {
            this->container.push_front(val);
        }

        void pop() {
            this->container.pop_front();
        }

        template <class A, class C>
        friend bool operator==(const ft::stack<A, C>& lhs, const ft::stack<A, C>& rhs);

        template <class A, class C>
        friend bool operator!=(const ft::stack<A, C>& lhs, const ft::stack<A, C>& rhs);

        template <class A, class C>
        friend bool operator<(const ft::stack<A, C>& lhs, const ft::stack<A, C>& rhs);

        template <class A, class C>
        friend bool operator>(const stack<A, C>& lhs, const stack<A, C>& rhs);

        template <class A, class C>
        friend bool operator<=(const stack<A, C>& lhs, const stack<A, C>& rhs);

        template <class A, class C>
        friend bool operator>=(const stack<A, C>& lhs, const stack<A, C>& rhs);


    private:
        container_type container;
    };


    template <class T, class Container>
    bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs.container == rhs.container);
    }

    template <class T, class Container>
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs.container != rhs.container);
    }

    template <class T, class Container>
    bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs.container < rhs.container);
    }

    template <class T, class Container>
    bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs.container <= rhs.container);
    }

    template <class T, class Container>
    bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs.container > rhs.container);
    }

    template <class T, class Container>
    bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs.container >= rhs.container);
    }
}

#endif
