#ifndef NODE_HPP
#define NODE_HPP

template<class T>
struct Node{
    Node<T>* prev;
    Node<T>* next;
    T data;

    Node() : prev(nullptr), next(nullptr) {}
    Node(const Node& other);
    Node(Node&& other);
    Node(const T val) : prev(nullptr), next(nullptr), data(val) {}
    Node& operator =(const Node& other);
    Node& operator =(Node&& other);
    ~Node() {}

    template<class M>
    friend bool operator ==(const Node<M>& lhs, const Node<M>& rhs);

    template<class M>
    friend bool operator !=(const Node<M>& lhs, const Node<M>& rhs);

private:
    void copycat(const Node& other);
    void clean();
};

template<class T>
Node<T>::Node(const Node& other) : prev(nullptr), next(nullptr) {
    copycat(other);
}
template<class T>
Node<T>::Node(Node&& other) : prev(nullptr), next(nullptr) {
    copycat(other);
    other.clean();
}

template<class T>
Node<T>& Node<T>::operator =(const Node& other){
    if(*this != other){
        clean();
        copycat(other);
    }

    return *this;
}

template<class T>
Node<T>& Node<T>::operator =(Node&& other){
    *this = other;
    other.clean();
}

template<class T>
bool operator ==(const Node<T>& lhs, const Node<T>& rhs){
    return lhs.data == rhs.data;
}

template<class T>
bool operator !=(const Node<T>& lhs, const Node<T>& rhs){
    return !(lhs == rhs);
}

template<class T>
void Node<T>::copycat(const Node& other){
    data = other.data;
}

template<class T>
void Node<T>::clean(){
    prev = nullptr;
    next = nullptr;
    data = T();
}

#endif // NODE_HPP
