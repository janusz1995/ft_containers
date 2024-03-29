#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "../List/list.hpp"

namespace ft {

    template<class T, class Container = ft::list<T> >
    class queue {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

        explicit queue(const container_type &ctnr = container_type()) : container(ctnr) {}

        bool empty() const {
            return (this->container.empty());
        }

        size_type size() const {
            return (container.size());
        }

        value_type& front() {
            return (container.front());
        }

        const value_type& front() const {
            return (container.front());
        }

        value_type& back() {
            return (container.back());
        }

        const value_type& back() const {
            return (container.back());
        }

        void push(const value_type& val) {
            this->container.push_back(val);
        }

        void pop() {
            this->container.pop_front();
        }

        template <class A, class C>
        friend bool operator==(const ft::queue<A, C>& lhs, const ft::queue<A, C>& rhs);

        template <class A, class C>
        friend bool operator!=(const ft::queue<A, C>& lhs, const ft::queue<A, C>& rhs);

        template <class A, class C>
        friend bool operator<(const ft::queue<A, C>& lhs, const ft::queue<A, C>& rhs);

        template <class A, class C>
        friend bool operator>(const queue<A, C>& lhs, const queue<A, C>& rhs);

        template <class A, class C>
        friend bool operator<=(const queue<A, C>& lhs, const queue<A, C>& rhs);

        template <class A, class C>
        friend bool operator>=(const queue<A, C>& lhs, const queue<A, C>& rhs);

    private:
        container_type container;

    };

    template <class T, class Container>
    bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
        return (lhs.container == rhs.container);
    }

    template <class T, class Container>
    bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
        return (lhs.container != rhs.container);
    }

    template <class T, class Container>
    bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
        return (lhs.container < rhs.container);
    }

    template <class T, class Container>
    bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
        return (lhs.container <= rhs.container);
    }

    template <class T, class Container>
    bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
        return (lhs.container > rhs.container);
    }

    template <class T, class Container>
    bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
        return (lhs.container >= rhs.container);
    }
}

#endif
