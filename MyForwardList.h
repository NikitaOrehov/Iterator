#pragma once
#include <iostream>

template <class T>
struct Node{
    T data;
    Node* next;
};

template <class T>
struct ListIterator{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Node<T>;
    using pointer = Node<T>*;
    using reference = Node<T>&;
    ListIterator(const pointer node): _node(node){};
    const reference operator*()const{return *_node;}
    const pointer operator->(){return _node;}
    ListIterator operator++(int){
        ListIterator tmp=*this;
        ++(*this);
        return tmp;
    }
    ListIterator& operator++(){
        _node = _node->next;
        return *this;
    }
    friend bool operator==(const ListIterator& a,const ListIterator& b){
        return a._node==b._node;
    }
    friend bool operator!=(const ListIterator& a,const ListIterator& b){
        return a._node != b._node;
    }

private:
    pointer _node;
};

template <class T>
class MyForwardList{
private:
    Node<T>* _head;
    Node<T>* _tail;
public:
    MyForwardList(){
        _head = nullptr;
    }
    
    void AddNode(T data) {
        Node<T>* node = new Node<T>{.data = data, .next = nullptr};
        if (_head == nullptr){
            _head = node;
            _tail = node;
        }
        else{
            _tail->next = node;
            _tail = _tail->next;
        }
    }

    void DeleteElem(T data){
        auto tmp = begin();
        while ((*tmp).next != nullptr || (*tmp).next->data != data){
            tmp++;
        }
        (*tmp).next = (*tmp).next->next;
    }

    ListIterator<T> begin(){
        return ListIterator<T>(_head);
    }

    ListIterator<T> end(){
        return ListIterator<T>(nullptr);
    }

    friend std::ostream& operator<<(const std::ostream& os, MyForwardList f){
        for (auto f: f){
            std::cout<<f.data<<" ";
        }
    }

};