#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"

template<class T>
class List{
    Node<T>* head;
    Node<T>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}
    List(const List& other);
    List(List&& other);
    List& operator =(const List& other);
    List& operator =(List&& other);
    void push(const T val);
    void pop();
    void push_rear(const T val);
    void pop_rear();
    ~List();

    template<class M>
    friend bool operator ==(const List<M>& lhs, const List<M>& rhs);

    template<class M>
    friend bool operator !=(const List<M>& lhs, const List<M>& rhs);

private:
    void copycat(const List& other);
    void clean();
};

template<class T>
List<T>::List(const List& other) : head(nullptr), tail(nullptr) {
    copycat(other);
}

template<class T>
List<T>::List(List&& other){
    this.head = other.head;
    this.tail = other.tail;

    other.head = nullptr;
    other.tail = nullptr;
}

template<class T>
List<T>& List<T>::operator =(const List& other){
    if(*this != other){
        clean();
        copycat(other);
    }

    return *this;
}

template<class T>
List<T>& List<T>::operator =(List&& other){
    *this = other;
    other.head = nullptr;
    other.tail = nullptr;
}

template<class T>
void List<T>::push(const T val){
    if(head){
        Node<T>* curr = new Node<T>(val);
        curr->next = head;
        head->prev = curr;
        head = curr;
    } else {
        head = tail = new Node<T>(val);
    }
}

template<class T>
void List<T>::pop(){
    if(head){
        delete head->prev;
        head->prev = nullptr;
        head = head->next;
    }
}

template<class T>
void List<T>::push_rear(const T val){
    if(tail){
        Node<T>* curr = new Node<T>(val);
        curr->prev = tail;
        tail->prev = curr;
        tail = curr;
    } else {
        head = tail = new Node<T>(val);
    }
}

template<class T>
void List<T>::pop_rear(){
    if(tail){
        delete tail->next;
        tail->next = nullptr;
        tail = tail->prev;
    }
}

template<class T>
List<T>::~List(){
    clean();
}

template<class T>
void List<T>::copycat(const List& other){
    if(other.head){
        head = new Node<T>(*other.head);
        tail = new Node<T>(*other.tail);

        Node<T>* from = other.head;
        Node<T>* to = head;
        while(from->next) {

            to->next = new Node<T>(*from->next);
            if(from->prev){
                to->prev = new Node<T>(*from->prev);
            }

            from = from->next;
            to = to->next;
        }
    }
}

template<class T>
void List<T>::clean(){
    Node<T>* curr = tail;
    while(curr){
        delete curr->next;
        curr->next = nullptr;
        curr = curr->prev;
    }
}

template<class T>
bool operator ==(const List<T>& lhs, const List<T>& rhs){
    bool eq = true;
    Node<T>* currL = lhs.head;
    Node<T>* currR = rhs.head;

    while(currL && currR && eq){
        if(currL->data != currR->data){
            eq = false;
        }
        currL = currL->next;
        currR = currR->next;
    }

    if(currL || currR){
        eq = false;
    }

    return eq;
}

template<class T>
bool operator !=(const List<T>& lhs, const List<T>& rhs){
    return !(lhs == rhs);
}
#endif // LIST_HPP
