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
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    ListIterator(Node<T>* node): _node(node){};
    const reference operator*()const { return _node->data; }
    const pointer operator->(){return &(_node->data);}
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
    Node<T>* _node;
};

template <class T>
class MyForwardList{
private:
    Node<T>* _head;
    Node<T>* _tail;
public:
    MyForwardList(){
        _head = nullptr;
        _tail = nullptr;
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
        if (empty()) return;
        Node<T>* current = _head;
        Node<T>* previous = nullptr;
        while (current != nullptr){
            if (current->data == data) {
                Node<T>* tmp = current;
                if (previous) previous->next = current->next;
                else _head = _head->next;
                if (current == _tail) {
                    _tail = previous;
                }
                current = current->next;
                delete tmp;
                continue;
            }
            previous = current;
            current = current->next;
        }
        return;
    }

    void DeleteElem(T* elems, size_t size) {
        for (int i = 0; i < size; i++) {
            DeleteElem(elems[i]);
        }
    }

    bool empty() {
        return !_head;
    }

    ListIterator<T> begin(){
        return ListIterator<T>(_head);
    }

    ListIterator<T> end(){
        return ListIterator<T>(nullptr);
    }

    friend std::ostream& operator<<(std::ostream& os, MyForwardList f){
        for (auto f: f){
            std::cout<<f<<" ";
        }
        return os;
    }

};